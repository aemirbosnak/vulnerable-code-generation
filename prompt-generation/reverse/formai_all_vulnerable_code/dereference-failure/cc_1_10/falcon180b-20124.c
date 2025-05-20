//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define CHECKSUM_LENGTH 32

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *data = (char *) malloc(MAX_SIZE);
    int length = 0;
    while ((length = fread(data + length, 1, MAX_SIZE - length, file)) > 0) {
        if (length + length > MAX_SIZE) {
            printf("File too large.\n");
            free(data);
            fclose(file);
            return 1;
        }
    }

    unsigned char checksum[CHECKSUM_LENGTH];
    unsigned int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (unsigned char) data[i];
    }

    for (int i = 0; i < CHECKSUM_LENGTH; i++) {
        checksum[i] = (unsigned char) (sum % 256);
        sum /= 256;
    }

    printf("File: %s\n", argv[1]);
    printf("Checksum: ");
    for (int i = 0; i < CHECKSUM_LENGTH; i++) {
        printf("%02X ", checksum[i]);
    }
    printf("\n");

    free(data);
    fclose(file);
    return 0;
}