//FormAI DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 100
#define CHUNK_SIZE 1024

void encryptFile(char* inputFile, char* outputFile, char* key) {
    FILE* in = fopen(inputFile, "rb");
    FILE* out = fopen(outputFile, "wb");
    int keyLength = strlen(key);
    int keyIndex = 0;
    char chunk[CHUNK_SIZE];
    
    while(fread(chunk, 1, CHUNK_SIZE, in) > 0) {
        for(int i = 0; i < CHUNK_SIZE; i++) {
            chunk[i] = chunk[i] ^ key[keyIndex++];
            if(keyIndex == keyLength) {
                keyIndex = 0;
            }
        }
        fwrite(chunk, 1, CHUNK_SIZE, out);
    }
    fclose(in);
    fclose(out);
}

void decryptFile(char* inputFile, char* outputFile, char* key) {
    FILE* in = fopen(inputFile, "rb");
    FILE* out = fopen(outputFile, "wb");
    int keyLength = strlen(key);
    int keyIndex = 0;
    char chunk[CHUNK_SIZE];
    
    while(fread(chunk, 1, CHUNK_SIZE, in) > 0) {
        for(int i = 0; i < CHUNK_SIZE; i++) {
            chunk[i] = chunk[i] ^ key[keyIndex++];
            if(keyIndex == keyLength) {
                keyIndex = 0;
            }
        }
        fwrite(chunk, 1, CHUNK_SIZE, out);
    }
    fclose(in);
    fclose(out);
}

int main() {
    char fileName[FILE_NAME_SIZE];
    char key[FILE_NAME_SIZE];
    int choice;
    printf("Welcome to Brave File Encryption Program\n");
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the name of the file you want to encrypt: ");
                scanf("%s", fileName);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encryptFile(fileName, strcat(fileName,".enc"), key);
                printf("File encrypted successfully as %s.enc\n", fileName);
                break;
            case 2:
                printf("Enter the name of the file you want to decrypt: ");
                scanf("%s", fileName);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decryptFile(fileName, strcat(fileName,".dec"), key);
                printf("File decrypted successfully as %s.dec\n", fileName);
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}