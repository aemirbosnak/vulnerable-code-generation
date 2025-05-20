//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate checksum
int checksum(char *data, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum % 256;
}

// Function to print usage instructions
void usage() {
    printf("Usage:./checksum <filename>\n");
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        usage();
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Get file length
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    rewind(file);

    // Read file contents into buffer
    char *buffer = malloc(length + 1);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    fread(buffer, length, 1, file);
    fclose(file);
    buffer[length] = '\0';

    // Calculate checksum
    int checksum_value = checksum(buffer, length);

    // Print result
    printf("Checksum value: %d\n", checksum_value);

    free(buffer);
    return 0;
}