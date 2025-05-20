//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Returns the size of the file in bytes
long int getFileSize(char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    fclose(file);
    return fileSize;
}

// Reads data from a file and stores it in a buffer
void readFileData(char *filename, char *buffer, long int bufferSize) {
    FILE *file = fopen(filename, "rb");
    fread(buffer, bufferSize, 1, file);
    fclose(file);
}

// Writes data from a buffer to a file
void writeFileData(char *filename, char *buffer, long int bufferSize) {
    FILE *file = fopen(filename, "wb");
    fwrite(buffer, bufferSize, 1, file);
    fclose(file);
}

// Encrypts a buffer of data by XOR'ing each byte with a key
void encryptData(char *data, long int dataSize, char *key, int keySize) {
    int keyIndex = 0;
    for (long int i = 0; i < dataSize; i++) {
        data[i] ^= key[keyIndex];
        keyIndex = (keyIndex + 1) % keySize;
    }
}

// Decrypts a buffer of data by XOR'ing each byte with a key
void decryptData(char *data, long int dataSize, char *key, int keySize) {
    encryptData(data, dataSize, key, keySize);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);

    long int fileSize = getFileSize(filename);
    char *fileData = malloc(fileSize);
    readFileData(filename, fileData, fileSize);

    char key[MAX_BUFFER_SIZE] = "my_secret_key";
    int keySize = strlen(key);

    encryptData(fileData, fileSize, key, keySize);
    char encryptedFilename[MAX_FILENAME_LENGTH] = "encrypted_";
    strcat(encryptedFilename, filename);
    writeFileData(encryptedFilename, fileData, fileSize);

    printf("Encryption successful. Encrypted file saved as %s\n", encryptedFilename);

    decryptData(fileData, fileSize, key, keySize);
    char decryptedFilename[MAX_FILENAME_LENGTH] = "decrypted_";
    strcat(decryptedFilename, filename);
    writeFileData(decryptedFilename, fileData, fileSize);

    printf("Decryption successful. Decrypted file saved as %s\n", decryptedFilename);

    free(fileData);
    return 0;
}