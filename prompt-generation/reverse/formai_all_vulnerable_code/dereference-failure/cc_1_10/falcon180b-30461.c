//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to calculate the checksum
unsigned int calculate_checksum(char *data, int size) {
    unsigned int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to read data from a file
void read_file(char *filename, char *data, int size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fread(data, sizeof(char), size, file);
    fclose(file);
}

// Function to write data to a file
void write_file(char *filename, char *data, int size) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(data, sizeof(char), size, file);
    fclose(file);
}

// Function to display usage
void display_usage() {
    printf("Usage:./checksum <filename> <size>\n");
    printf("Calculates the checksum of the first <size> bytes of <filename>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        display_usage();
        return 1;
    }
    char *filename = argv[1];
    int size = atoi(argv[2]);
    char data[MAX_SIZE];
    read_file(filename, data, size);
    unsigned int checksum = calculate_checksum(data, size);
    printf("Checksum: %08X\n", checksum);
    return 0;
}