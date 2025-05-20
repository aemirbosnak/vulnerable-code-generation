//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char *buffer;
    FILE *fp_in, *fp_out;
    int file_size, i;

    // Open input file for reading
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get file size
    fseek(fp_in, 0, SEEK_END);
    file_size = ftell(fp_in);
    rewind(fp_in);

    // Allocate memory for buffer
    buffer = (char *) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(fp_in);
        return 1;
    }

    // Read input file into buffer
    fread(buffer, file_size, 1, fp_in);
    fclose(fp_in);

    // Calculate checksum
    unsigned char checksum = 0;
    for (i = 0; i < file_size; i++) {
        checksum += buffer[i];
    }

    // Open output file for writing
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        free(buffer);
        return 1;
    }

    // Write checksum to output file
    fwrite(&checksum, 1, 1, fp_out);

    // Write input file to output file
    fwrite(buffer, file_size, 1, fp_out);

    // Close files
    fclose(fp_out);
    free(buffer);

    printf("Checksum calculated and written to output file.\n");

    return 0;
}