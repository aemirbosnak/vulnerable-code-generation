//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *filename;
    int size;
    char checksum[MAX_SIZE];
} File;

void generate_checksum(char *filename, int size, char *checksum) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char buffer[MAX_SIZE];
    while (fread(buffer, 1, size, file) > 0) {
        for (int i = 0; i < size; i++) {
            checksum[i % MAX_SIZE] ^= buffer[i];
        }
    }

    fclose(file);
}

int main() {
    int num_files;
    printf("Enter the number of files to calculate checksums for: ");
    scanf("%d", &num_files);

    File files[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter filename for file %d: ", i+1);
        char filename[MAX_SIZE];
        scanf("%s", filename);

        printf("Enter size of file %s: ", filename);
        int size;
        scanf("%d", &size);

        files[i].filename = filename;
        files[i].size = size;
        memset(files[i].checksum, 0, MAX_SIZE);
    }

    printf("Calculating checksums...\n");

    for (int i = 0; i < num_files; i++) {
        generate_checksum(files[i].filename, files[i].size, files[i].checksum);
        printf("Checksum for file %s: ", files[i].filename);
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%02X ", files[i].checksum[j]);
        }
        printf("\n");
    }

    return 0;
}