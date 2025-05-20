//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECKSUM_LENGTH 16

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error reading file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    unsigned char checksum[CHECKSUM_LENGTH];
    memset(checksum, 0, CHECKSUM_LENGTH);

    // Calculate checksum
    for (size_t i = 0; i < file_size; i++) {
        unsigned char byte = buffer[i];
        if (i % 2 == 0) {
            checksum[i / 2] += byte;
        } else {
            checksum[i / 2] -= byte;
        }
    }

    // Convert checksum to hexadecimal string
    char checksum_string[CHECKSUM_LENGTH * 2 + 1];
    for (int i = 0; i < CHECKSUM_LENGTH; i++) {
        sprintf(&checksum_string[i * 2], "%02x", checksum[i]);
    }
    checksum_string[CHECKSUM_LENGTH * 2] = '\0';

    printf("Checksum: %s\n", checksum_string);

    free(buffer);
    fclose(file);

    return 0;
}