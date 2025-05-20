//FormAI DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char* key){
    int messageLength = strlen(message), keyLength = strlen(key), i, j;
    char* encryptedMessage = (char*)malloc(sizeof(char)*(messageLength + 1));
    
    //Perform XOR on message and key
    for(i = 0, j = 0; i < messageLength; i++, j++){
        if(j == keyLength)
            j = 0;
        encryptedMessage[i] = ((message[i] ^ key[j]) + 65);
    }
    
    encryptedMessage[messageLength] = '\0';
    
    printf("Encrypted Message: %s\n", encryptedMessage);
    
    free(encryptedMessage);
}

void decrypt(char* message, char* key){
    int messageLength = strlen(message), keyLength = strlen(key), i, j;
    char* decryptedMessage = (char*)malloc(sizeof(char)*(messageLength + 1));
    
    //Perform XOR on message and key
    for(i = 0, j = 0; i < messageLength; i++, j++){
        if(j == keyLength)
            j = 0;
        decryptedMessage[i] = ((message[i] - 65) ^ key[j]);
    }
    
    decryptedMessage[messageLength] = '\0';
    
    printf("Decrypted Message: %s\n", decryptedMessage);
    
    free(decryptedMessage);
}

int main(){
    char message[50], key[50];
    printf("Enter Message: ");
    gets(message);
    printf("Enter Key: ");
    gets(key);
    
    encrypt(message, key);
    decrypt(encrypt, key);
    
    return 0;
}