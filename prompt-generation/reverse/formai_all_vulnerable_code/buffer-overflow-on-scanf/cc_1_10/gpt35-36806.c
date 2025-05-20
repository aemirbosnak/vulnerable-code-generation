//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PASSWORD_LENGTH 40
#define MAX_BUFFER_SIZE 1024

void encryptDecryptFile(char* file_path, char* password);
void encryptBuffer(unsigned char* buffer, size_t bufferLength, char* password);
unsigned long getFileSize(FILE* file);

int main() {
    char file_path[MAX_FILENAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter file path: ");
    scanf("%s", file_path);

    printf("Enter password: ");
    scanf("%s", password);
    
    encryptDecryptFile(file_path, password);

    printf("File encryption/decryption completed!\n");

    return 0;
}

void encryptDecryptFile(char* file_path, char* password) {
    FILE *fp;
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;
    unsigned long fileSize;

    fp = fopen(file_path, "rb+");
    if(fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        exit(1);
    }

    fileSize = getFileSize(fp);
    if(fileSize == 0) {
        printf("File is empty\n");
        exit(1);
    }

    bytesRead = fread(buffer, sizeof(buffer[0]), MAX_BUFFER_SIZE, fp);
    while(bytesRead != 0) {
        encryptBuffer(buffer, bytesRead, password);

        fseek(fp, -((long)bytesRead), SEEK_CUR);
        fwrite(buffer, sizeof(buffer[0]), bytesRead, fp);

        fseek(fp, 0, SEEK_CUR);
        bytesRead = fread(buffer, sizeof(buffer[0]), MAX_BUFFER_SIZE, fp);
    }

    fclose(fp);
}

void encryptBuffer(unsigned char* buffer, size_t bufferLength, char* password) {
    size_t passwordLength = strlen(password);
    unsigned char temp;
    
    for(size_t i = 0; i < bufferLength; i++) {
        temp = buffer[i] ^ password[i % passwordLength];
        buffer[i] = temp;
    }
}

unsigned long getFileSize(FILE* file) {
    unsigned long fileSize;
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fileSize;
}