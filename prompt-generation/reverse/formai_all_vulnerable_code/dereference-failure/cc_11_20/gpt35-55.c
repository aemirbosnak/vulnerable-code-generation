//FormAI DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // Block size in bytes

struct Partition {
    int start; // Starting index of partition
    int end; // Ending index of partition
};

int main(int argc, char *argv[]) {
    // Check if input arguments are correct
    if (argc != 3) {
        printf("Usage: recover inputfile outputfile\n");
        return 1;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file!\n");
        return 1;
    }

    // Get size of input file
    fseek(input_file, 0L, SEEK_END);
    int input_file_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // Create an array for partitions
    struct Partition partitions[input_file_size / BLOCK_SIZE];
    int partition_count = 0;

    // Loop through the input file, searching for partitions
    char buffer[BLOCK_SIZE];
    int partition_start = -1;
    while (fread(buffer, BLOCK_SIZE, 1, input_file) == 1) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Start of new partition found
            if (partition_start != -1) {
                // End previous partition
                partitions[partition_count].start = partition_start;
                partitions[partition_count].end = ftell(input_file) - BLOCK_SIZE;
                partition_count++;
            }
            partition_start = ftell(input_file) - BLOCK_SIZE;
        }
    }
    // End last partition
    partitions[partition_count].start = partition_start;
    partitions[partition_count].end = input_file_size - BLOCK_SIZE;
    partition_count++;

    // Print the number of partitions found
    printf("Found %d partitions.\n", partition_count);

    // Create output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Unable to create output file!\n");
        return 1;
    }

    // Loop through partitions, writing to output file
    char filename[8];
    for (int i = 0; i < partition_count; i++) {
        // Generate filename for current partition
        snprintf(filename, sizeof(filename), "%03d.jpg", i);

        // Read data from input file and write to output file
        fseek(input_file, partitions[i].start, SEEK_SET);
        int bytes_to_read = partitions[i].end - partitions[i].start + BLOCK_SIZE;
        while (bytes_to_read > 0 && fread(buffer, BLOCK_SIZE, 1, input_file) == 1) {
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
            bytes_to_read -= BLOCK_SIZE;
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}