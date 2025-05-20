//FormAI DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt a given file
void encryptFile(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // get file size
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // allocate memory for file buffer
    char *buffer = (char*) malloc(size * sizeof(char));
    if (buffer == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // read file content to buffer
    fread(buffer, sizeof(char), size, fp);
    fclose(fp);

    // perform XOR encryption on buffer with given key
    long int key_length = strlen(key);
    for (long int i = 0; i < size; i++) {
        buffer[i] ^= key[i % key_length];
    }

    // write encrypted content to file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(buffer, sizeof(char), size, fp);
    fclose(fp);

    free(buffer);
}

int main() {
    char filename[100], key[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter key: ");
    scanf("%s", key);

    // encrypt file
    encryptFile(filename, key);

    printf("File encrypted successfully.\n");
    return 0;
}