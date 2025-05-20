//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Key for encryption
const char *key = "mySecretKey";

// Function to encrypt the given message using the key
char *encrypt(char *message)
{
    int messageLen = strlen(message), keyLen = strlen(key), i, j;
    char *encryptedMsg = (char *)malloc(messageLen*sizeof(char));
    
    // XOR each character of the message with corresponding key character
    for(i=0,j=0; i<messageLen; ++i,++j){
        if(j==keyLen) j=0;
        encryptedMsg[i] = message[i] ^ key[j];   // XOR operation
    }
    encryptedMsg[i] = '\0';

    return encryptedMsg;
}

// Function to decrypt the given message using the key
char *decrypt(char *encryptedMsg)
{
    int messageLen = strlen(encryptedMsg), keyLen = strlen(key), i, j;
    char *decryptedMsg = (char *)malloc(messageLen*sizeof(char));
    
    // XOR each character of the encrypted message with corresponding key character
    for(i=0,j=0; i<messageLen; ++i,++j){
        if(j==keyLen) j=0;
        decryptedMsg[i] = encryptedMsg[i] ^ key[j];   // XOR operation
    }
    decryptedMsg[i] = '\0';

    return decryptedMsg;
}

int main()
{
    char message[100], *encryptedMsg, *decryptedMsg;
    printf("Enter the message to encrypt: ");
    gets(message);
    
    encryptedMsg = encrypt(message);
    printf("Encrypted message: %s\n",encryptedMsg);
    
    decryptedMsg = decrypt(encryptedMsg);
    printf("Decrypted message: %s\n",decryptedMsg);

    free(encryptedMsg);
    free(decryptedMsg);

    return 0;
}