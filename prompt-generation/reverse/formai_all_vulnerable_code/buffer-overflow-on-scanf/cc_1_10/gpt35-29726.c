//FormAI DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 256

void encryptFile(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb+");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    unsigned char *buffer = (unsigned char *) malloc(sizeof(unsigned char) * fileSize);
    if (!buffer) {
        printf("Error allocating memory\n");
        fclose(fp);
        return;
    }

    if (fread(buffer, 1, fileSize, fp) != fileSize) {
        printf("Error reading file: %s\n", filename);
        free(buffer);
        fclose(fp);
        return;
    }

    int bufferIndex = 0;
    int keyIndex = 0;
    int keyLength = strlen(key);

    while (bufferIndex < fileSize) {
        buffer[bufferIndex] ^= key[keyIndex];
        keyIndex = (keyIndex + 1) % keyLength;
        bufferIndex++;
    }

    rewind(fp);
    if (fwrite(buffer, 1, fileSize, fp) != fileSize) {
        printf("Error writing file: %s\n", filename);
    } else {
        printf("Encryption successful: %s\n", filename);
    }

    free(buffer);
    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter key: ");
    scanf("%s", key);
    encryptFile(filename, key);
    return 0;
}