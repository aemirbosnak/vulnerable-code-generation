//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE (1024*1024*1024) // 1GB
#define CHECKSUM_LENGTH 8

// Function to calculate the checksum of a file
void calculate_checksum(FILE* file, char* checksum) {
    unsigned char buffer[MAX_FILE_SIZE];
    unsigned int total_bytes_read = 0;
    unsigned int current_checksum = 0;

    // Read the file in chunks
    while (total_bytes_read < MAX_FILE_SIZE) {
        size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE - total_bytes_read, file);
        if (bytes_read == 0) {
            break;
        }
        total_bytes_read += bytes_read;

        // Calculate the checksum
        for (int i = 0; i < bytes_read; i++) {
            current_checksum += buffer[i];
        }
    }

    // Convert the checksum to a string
    sprintf(checksum, "%08X", current_checksum);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <checksum>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Calculate the checksum of the file
    char calculated_checksum[CHECKSUM_LENGTH+1] = {0};
    calculate_checksum(file, calculated_checksum);

    // Compare the calculated checksum with the provided checksum
    if (strcmp(argv[2], calculated_checksum) == 0) {
        printf("Checksum matches.\n");
    } else {
        printf("Checksum does not match.\n");
    }

    // Close the file
    fclose(file);
    return 0;
}