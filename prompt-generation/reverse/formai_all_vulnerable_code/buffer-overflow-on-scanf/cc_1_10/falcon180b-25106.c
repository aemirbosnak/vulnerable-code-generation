//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024 // Maximum size of data that can be checksummed

// Function to calculate the checksum of the given data
unsigned int calculate_checksum(char* data, int data_size) {
    unsigned int checksum = 0;
    for (int i = 0; i < data_size; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to read the data from a file and calculate its checksum
unsigned int read_file_and_calculate_checksum(FILE* file) {
    char buffer[MAX_DATA_SIZE];
    int bytes_read;
    unsigned int checksum = 0;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_DATA_SIZE, file)) > 0) {
        checksum += calculate_checksum(buffer, bytes_read);
    }

    return checksum;
}

// Function to print the checksum in hexadecimal format
void print_checksum(unsigned int checksum) {
    printf("Checksum: %08X\n", checksum);
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    unsigned int checksum = read_file_and_calculate_checksum(file);
    print_checksum(checksum);

    fclose(file);
    return 0;
}