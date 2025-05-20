//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Cryptic File Handling Program
const char* PASSWORD = "r0undTh3C0rner";
const int ENCRYPTION_KEY = 256;

void encryptFile(char* fileName){
    char newFileName[100];
    snprintf(newFileName, sizeof(newFileName), "%s.enc", fileName);
    FILE* originalFile = fopen(fileName, "rb");
    FILE* encryptedFile = fopen(newFileName, "wb");
    int c;
    srand(time(NULL));
    int randomIndex = rand() % strlen(PASSWORD);
    int encryptedChar;
    while((c = fgetc(originalFile)) != EOF){
        encryptedChar = (c + randomIndex) % ENCRYPTION_KEY;
        fputc(encryptedChar, encryptedFile);
    }
    fclose(originalFile);
    fclose(encryptedFile);
    remove(fileName);
    printf("Encryption Successful! Key: %d\n", randomIndex);
}

void decryptFile(char* fileName, int key){
    char newFileName[100];
    snprintf(newFileName, sizeof(newFileName), "%s.dec", fileName);
    FILE* encryptedFile = fopen(fileName, "rb");
    FILE* decryptedFile = fopen(newFileName, "wb");
    int c;
    while((c = fgetc(encryptedFile)) != EOF){
        int decryptedChar = (c - key + ENCRYPTION_KEY) % ENCRYPTION_KEY;
        fputc(decryptedChar, decryptedFile);
    }
    fclose(encryptedFile);
    fclose(decryptedFile);
    remove(fileName);
    printf("Decryption Successful!\n");
}

int main(){
    char fileName[100];
    char choice;
    printf("Enter the file name to encrypt/decrypt: ");
    scanf("%s", fileName);
    printf("Select operation:\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    switch(choice){
        case '1':{
            encryptFile(fileName);
            break;
        }
        case '2':{
            int key;
            printf("Enter decryption key: ");
            scanf("%d", &key);
            decryptFile(fileName, key);
            break;
        }
        default:{
            printf("Invalid Choice!\n");
            break;
        }
    }
    return 0;
}