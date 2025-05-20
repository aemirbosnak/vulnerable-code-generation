//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to perform the encryption
char* encrypt(char* fileContent, char* encryptKey){
    int keyLength = strlen(encryptKey);
    char* encryptedContent = malloc(sizeof(char) * strlen(fileContent));
    memset(encryptedContent, '\0', strlen(fileContent));
    int j = 0; //j will increment until it reaches length of key
    
    for(int i = 0; i < strlen(fileContent); i++) { 		
        if(j == keyLength) j = 0; //if j reaches key length, reset it to 0
        encryptedContent[i] = fileContent[i] ^ encryptKey[j]; //encrypt content
        j++;
    }

    return encryptedContent;
}

int main() {
    char fileName[100], encryptKey[100], buffer[100];
    printf("Welcome to the File Encryptor!\n");
    printf("Please enter the name of the file to encrypt:\n");
    scanf("%s", fileName);
    printf("Please enter the encryption key:\n");
    scanf("%s", encryptKey);

    FILE *fileToEncrypt = fopen(fileName, "r");
    if(fileToEncrypt == NULL) { //If the file does not exist, exit gracefully
        printf("File not found. Exiting program.\n");
        return 0;
    }

    FILE *encryptedFile = fopen(strcat(fileName, ".enc"), "w"); //open a new file to write encrypted content
    if(encryptedFile == NULL) { //If new file cannot be created, exit gracefully
        printf("Unable to create encrypted file. Exiting program.\n");
        return 0;
    }

    while(fgets(buffer, 100, fileToEncrypt) != NULL) { //read file line by line
        char* encryptedContent = encrypt(buffer, encryptKey); //encrypt each line
        fprintf(encryptedFile, "%s\n", encryptedContent); //write encrypted content to new file
        free(encryptedContent);
    }

    printf("File Encrypted Successfully!\n");
    fclose(fileToEncrypt);
    fclose(encryptedFile);

    return 0;
}