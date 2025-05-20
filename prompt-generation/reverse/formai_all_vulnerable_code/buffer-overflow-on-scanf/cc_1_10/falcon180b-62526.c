//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to calculate checksum
unsigned short calculate_checksum(char *data, int size) {
    unsigned short checksum = 0;

    for (int i = 0; i < size; i++) {
        checksum += (unsigned char) data[i];
    }

    return checksum;
}

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char buffer[MAX_SIZE];
    FILE *input, *output;
    int size;

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open output file
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file\n");
        fclose(input);
        return 1;
    }

    // Read input file into buffer
    size = fread(buffer, 1, MAX_SIZE, input);

    // Calculate checksum
    unsigned short checksum = calculate_checksum(buffer, size);

    // Write buffer and checksum to output file
    fwrite(buffer, 1, size, output);
    fwrite(&checksum, 2, 1, output);

    // Close files
    fclose(input);
    fclose(output);

    printf("Checksum calculated and written to output file\n");

    return 0;
}