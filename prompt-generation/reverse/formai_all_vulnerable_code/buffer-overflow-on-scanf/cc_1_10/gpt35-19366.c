//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *fileName, char *key) {
    FILE *file;
    char *buffer;
    long fileSize;
    int keyLength = strlen(key);
    int i, j;

    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory.");
        exit(1);
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    for (i = 0, j = 0; i < fileSize; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        buffer[i] ^= key[j];
    }

    file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    fwrite(buffer, 1, fileSize, file);
    fclose(file);

    free(buffer);
}

int main() {
    char fileName[100];
    char key[100];

    printf("Enter a file name: ");
    scanf("%s", fileName);
    printf("Enter a key: ");
    scanf("%s", key);

    encrypt(fileName, key);

    printf("File encrypted successfully!");

    return 0;
}