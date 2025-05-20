//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_KEY_LENGTH 32
#define MAX_BUFFER_SIZE 1024

void encryptFile(char *filename, char *key);
void decryptFile(char *filename, char *key);
void xorCrypt(char *data, int dataLen, char *key, int keyLen);

int main(void) {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char option;
    
    printf("Welcome to the File Encryptor/Decryptor!\n\n");
    
    do {
        printf("Please enter the filename: ");
        scanf("%s", filename);
        printf("Please enter the encryption key (maximum 32 characters): ");
        scanf("%s", key);
        
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf(" %c", &option);
        
        switch(option) {
            case '1':
                encryptFile(filename, key);
                printf("\nFile successfully encrypted!\n\n");
                break;
            case '2':
                decryptFile(filename, key);
                printf("\nFile successfully decrypted!\n\n");
                break;
            case '3':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;
        }
    } while (option != '3');
    
    return 0;
}

void encryptFile(char *filename, char *key) {
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp;
    
    fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error: Failed to open the file!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    fread(buffer, fileSize, 1, fp);
    
    xorCrypt(buffer, fileSize, key, strlen(key));
    
    fclose(fp);
    
    fp = fopen(filename, "wb");
    
    if (fp == NULL) {
        printf("Error: Failed to open the file!\n");
        exit(1);
    }
    
    fwrite(buffer, fileSize, 1, fp);
    fclose(fp);
}

void decryptFile(char *filename, char *key) {
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp;
    
    fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error: Failed to open the file!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    fread(buffer, fileSize, 1, fp);
    
    xorCrypt(buffer, fileSize, key, strlen(key));
    
    fclose(fp);
    
    fp = fopen(filename, "wb");
    
    if (fp == NULL) {
        printf("Error: Failed to open the file!\n");
        exit(1);
    }
    
    fwrite(buffer, fileSize, 1, fp);
    fclose(fp);
}

void xorCrypt(char *data, int dataLen, char *key, int keyLen) {
    int i, j;
    for (i = 0, j = 0; i < dataLen; i++, j++) {
        if (j >= keyLen) {
            j = 0;
        }
        data[i] ^= key[j];
    }
}