//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_LENGTH 1000

void encrypt(char* buffer, int key){
    int i = 0;
    while(buffer[i] != '\0'){
        buffer[i] += key;
        i++;
    }
}

void decrypt(char* buffer, int key){
    int i = 0;
    while(buffer[i] != '\0'){
        buffer[i] -= key;
        i++;
    }
}

int main(){
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_BUFFER_LENGTH];
    int key;

    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: Unable to open file\n");
        return 0;
    }

    int i = 0;
    while(fscanf(fp, "%c", &buffer[i]) != EOF){
        i++;
    }
    buffer[i] = '\0';

    fclose(fp);

    encrypt(buffer, key);

    char encryptedFilename[MAX_FILENAME_LENGTH+4];
    strcpy(encryptedFilename, filename);
    strcat(encryptedFilename, ".enc");

    fp = fopen(encryptedFilename, "w");

    fprintf(fp, "%s", buffer);

    fclose(fp);
    
    printf("File %s encrypted successfully as %s\n", filename, encryptedFilename);

    printf("Enter the filename to decrypt: ");
    scanf("%s", filename);

    printf("Enter the decryption key: ");
    scanf("%d", &key);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: Unable to open file\n");
        return 0;
    }

    i = 0;
    while(fscanf(fp, "%c", &buffer[i]) != EOF){
        i++;
    }
    buffer[i] = '\0';

    fclose(fp);

    decrypt(buffer, key);

    char decryptedFilename[MAX_FILENAME_LENGTH-4];
    strncpy(decryptedFilename, filename, strlen(filename)-4);

    fp = fopen(decryptedFilename, "w");

    fprintf(fp, "%s", buffer);

    fclose(fp);
    
    printf("File %s decrypted successfully as %s\n", filename, decryptedFilename);

    return 0;
}