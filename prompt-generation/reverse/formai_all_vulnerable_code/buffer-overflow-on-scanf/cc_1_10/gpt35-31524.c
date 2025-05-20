//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000 // 1MB

// This function takes in a filename, reads its contents, and encrypts it using XOR
void encryptFile(char *filename, char *key){
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Could not open file %s\n", filename);
        return;
    }

    // Allocate memory for file contents
    char *contents = (char *) malloc(MAX_FILE_SIZE);
    if(contents == NULL){
        printf("Could not allocate memory for file contents\n");
        fclose(fp);
        return;
    }

    // Read file contents into memory
    int fileSize = 0;
    while(!feof(fp)){
        int bytesRead = fread(contents + fileSize, 1, MAX_FILE_SIZE - fileSize - 1, fp);
        fileSize += bytesRead;
        if(fileSize >= MAX_FILE_SIZE){
            printf("File size exceeded limit of %d bytes\n", MAX_FILE_SIZE);
            free(contents);
            fclose(fp);
            return;
        }
    }
    contents[fileSize] = '\0'; // Null terminate the string

    // Generate pseudo-random key
    srand(time(NULL));
    for(int i = 0; i < strlen(key); i++){
        key[i] = (char) (rand() % 256);
    }

    // Encrypt file contents using key
    int keyIndex = 0;
    for(int i = 0; i < fileSize; i++){
        contents[i] = contents[i] ^ key[keyIndex++];
        if(keyIndex >= strlen(key)){
            keyIndex = 0;
        }
    }

    // Write encrypted contents back to file
    char encryptedFilename[strlen(filename) + 5];
    strcpy(encryptedFilename, filename);
    strcat(encryptedFilename, ".enc");
    FILE *encryptedFp = fopen(encryptedFilename, "wb");
    if(encryptedFp == NULL){
        printf("Could not create encrypted file %s\n", encryptedFilename);
        free(contents);
        fclose(fp);
        return;
    }
    fwrite(key, 1, strlen(key), encryptedFp);
    fwrite(contents, 1, fileSize, encryptedFp);
    printf("Successfully encrypted file %s to %s\n", filename, encryptedFilename);

    // Clean up memory and files
    free(contents);
    fclose(fp);
    fclose(encryptedFp);
}

int main(){
    char filename[100], key[100];

    printf("Welcome to the C File Encryptor!\n");
    printf("Please enter the name of the file you wish to encrypt: ");
    scanf("%s", filename);
    printf("Please enter the encryption key: ");
    scanf("%s", key);

    encryptFile(filename, key);

    return 0;
}