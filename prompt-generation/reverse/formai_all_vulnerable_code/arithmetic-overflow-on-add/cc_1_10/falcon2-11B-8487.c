//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char* fileName) {
    // Open the file for reading
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("Error opening file: %s\n", fileName);
        return;
    }
    
    // Read the file contents into a buffer
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* fileContents = (char*)malloc(fileSize + 1);
    fread(fileContents, fileSize, 1, file);
    fileContents[fileSize] = '\0';
    
    // Encrypt the file contents
    int keySize = 128;
    char* key = (char*)malloc(keySize);
    srand(time(NULL));
    for (int i = 0; i < keySize; i++) {
        key[i] = rand() % 26 + 'A';
    }
    char* encryptedContents = (char*)malloc(fileSize);
    for (int i = 0; i < fileSize; i++) {
        encryptedContents[i] = fileContents[i] ^ key[i % keySize];
    }
    
    // Write the encrypted contents to a new file
    char* encryptedFileName = (char*)malloc(strlen(fileName) + 10);
    sprintf(encryptedFileName, "%s.enc", fileName);
    FILE* encryptedFile = fopen(encryptedFileName, "wb");
    if (!encryptedFile) {
        printf("Error creating encrypted file: %s\n", encryptedFileName);
        return;
    }
    fwrite(encryptedContents, fileSize, 1, encryptedFile);
    fclose(encryptedFile);
    
    // Free memory
    free(fileContents);
    free(encryptedContents);
    free(key);
    fclose(file);
}

int main() {
    char* fileName = "example.txt";
    encryptFile(fileName);
    printf("File %s encrypted successfully!\n", fileName);
    return 0;
}