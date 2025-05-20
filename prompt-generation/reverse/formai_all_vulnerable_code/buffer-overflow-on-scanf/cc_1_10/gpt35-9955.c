//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encryptFile(char* fileName, char* key){
    FILE* inFile = fopen(fileName, "r");
    if(inFile == NULL){
        printf("Error reading file...\n");
        return;
    }
    FILE* outFile = fopen("encrypted.txt", "w");
    if(outFile == NULL){
        printf("Error opening encrypted file...\n");
        fclose(inFile);
        return;
    }
    int keyLength = strlen(key);
    int count = 0;
    char ch;
    while((ch = fgetc(inFile)) != EOF){
        ch ^= key[count % keyLength]; // XOR operation with current key character
        fputc(ch, outFile);
        count++;
    }
    fclose(inFile);
    fclose(outFile);
}

void decryptFile(char* fileName, char* key){
    FILE* inFile = fopen(fileName, "r");
    if(inFile == NULL){
        printf("Error reading file...\n");
        return;
    }
    FILE* outFile = fopen("decrypted.txt", "w");
    if(outFile == NULL){
        printf("Error opening decrypted file...\n");
        fclose(inFile);
        return;
    }
    int keyLength = strlen(key);
    int count = 0;
    char ch;
    while((ch = fgetc(inFile)) != EOF){
        ch ^= key[count % keyLength]; // XOR operation with current key character
        fputc(ch, outFile);
        count++;
    }
    fclose(inFile);
    fclose(outFile);
}

int main(){
    printf("Enter file name: ");
    char fileName[50];
    scanf("%s", fileName);
    printf("Enter key: ");
    char key[25];
    scanf("%s", key);
    encryptFile(fileName, key);
    printf("File encrypted successfully.\n");
    decryptFile("encrypted.txt", key);
    printf("File decrypted successfully.");
    return 0;
}