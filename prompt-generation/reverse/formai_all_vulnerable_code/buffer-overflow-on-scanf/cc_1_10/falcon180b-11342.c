//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILES 100
#define HASH_SIZE 256

typedef struct {
    char filename[MAX_LINE_LENGTH];
    unsigned char hash[HASH_SIZE];
} FileHash;

void calculateHash(char *filename, unsigned char *hash) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        for (int j = 0; j < strlen(line); j++) {
            hash[i] ^= line[j];
            i++;
            if (i >= HASH_SIZE) {
                i = 0;
            }
        }
    }

    fclose(file);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    unsigned char hash[HASH_SIZE];
    FileHash files[MAX_FILES];
    int numFiles = 0;

    printf("Enter filenames (up to %d):\n", MAX_FILES - 1);
    while (scanf("%s", filename)!= EOF) {
        calculateHash(filename, hash);
        strcpy(files[numFiles].filename, filename);
        for (int i = 0; i < HASH_SIZE; i++) {
            files[numFiles].hash[i] = hash[i];
        }
        numFiles++;
    }

    printf("Checksums:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s: ", files[i].filename);
        for (int j = 0; j < HASH_SIZE; j++) {
            printf("%02X ", files[i].hash[j]);
        }
        printf("\n");
    }

    return 0;
}