//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 26
#define BUFFER_SIZE 1024
#define FILE_MODE "r+b"

int main(int argc, char *argv[]) {
    int key, i, j, k;
    char filename[100], fileContent[BUFFER_SIZE], encryptedContent[BUFFER_SIZE];
    FILE *file;

    if (argc != 3) {
        printf("Usage: %s <key> <file>\n", argv[0]);
        return 1;
    }

    key = atoi(argv[1]);
    strcpy(filename, argv[2]);

    file = fopen(filename, FILE_MODE);
    if (file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    fread(fileContent, sizeof(char), fileSize, file);
    fclose(file);

    for (i = 0; i < fileSize; i++) {
        if (fileContent[i] >= 'a' && fileContent[i] <= 'z') {
            fileContent[i] = ((fileContent[i] - 'a' + key) % KEY_SIZE) + 'a';
        } else if (fileContent[i] >= 'A' && fileContent[i] <= 'Z') {
            fileContent[i] = ((fileContent[i] - 'A' + key) % KEY_SIZE) + 'A';
        }
    }

    for (i = 0, j = 0; i < fileSize && j < BUFFER_SIZE; i++, j++) {
        encryptedContent[j] = fileContent[i];
    }
    encryptedContent[j] = '\0';

    file = fopen(argv[2], "w+b");
    if (file == NULL) {
        perror("Error opening file for writing.\n");
        return 1;
    }

    fwrite(encryptedContent, sizeof(char), j, file);
    fclose(file);

    printf("File %s encrypted with key %d successfully.\n", filename, key);

    return 0;
}