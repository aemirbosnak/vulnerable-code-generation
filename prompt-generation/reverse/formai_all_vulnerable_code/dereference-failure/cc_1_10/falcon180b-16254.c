//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to calculate the checksum
int calculate_checksum(char* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage:./checksum_calculator <filename>\n");
        exit(1);
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_SIZE) {
        printf("Error: File size exceeds maximum limit.\n");
        exit(1);
    }

    char* data = malloc(file_size + 1);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(data, file_size, 1, file);
    data[file_size] = '\0';

    int checksum = calculate_checksum(data, file_size);

    printf("File: %s\n", argv[1]);
    printf("Size: %d bytes\n", file_size);
    printf("Checksum: 0x%X\n", checksum);

    free(data);
    fclose(file);

    return 0;
}