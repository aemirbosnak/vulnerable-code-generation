//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encrypt(char key[], char message[]);
void decrypt(char key[], char message[]);

int main() {
    char key[100], message[100];
    int option;
    
    printf("Welcome to the Simple Cryptography Algorithm!\n\n");
    
    printf("What would you like to do?\n");
    printf("1 - Encrypt a message\n");
    printf("2 - Decrypt a message\n");
    printf("Select an option: ");
    scanf("%d", &option);
    
    printf("\nEnter key: ");
    scanf("%s", key);
    
    printf("\nEnter message: ");
    scanf("%s", message);
    
    if (option == 1) {
        encrypt(key, message);
        printf("\nEncrypted message: %s\n", message);
    } else if (option == 2) {
        decrypt(key, message);
        printf("\nDecrypted message: %s\n", message);
    } else {
        printf("Invalid option selected!\n");
    }
    
    return 0;
}

void encrypt(char key[], char message[]) {
    int keyLen = strlen(key), msgLen = strlen(message), i, j;
    char newKey[msgLen], encryptedMsg[msgLen];
    
    // Generate new key
    for (i = 0, j = 0; i < msgLen; i++, j++) {
        if (j == keyLen) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    
    // Encrypt message
    for (i = 0; i < msgLen; i++) {
        int asciiValue = ((message[i] + newKey[i]) % 26) + 'A';
        encryptedMsg[i] = asciiValue;
    }
    encryptedMsg[i] = '\0';
    
    strcpy(message, encryptedMsg);
}

void decrypt(char key[], char message[]) {
    int keyLen = strlen(key), msgLen = strlen(message), i, j;
    char newKey[msgLen], decryptedMsg[msgLen];
    
    // Generate new key
    for (i = 0, j = 0; i < msgLen; i++, j++) {
        if (j == keyLen) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    
    // Decrypt message
    for (i = 0; i < msgLen; i++) {
        int asciiValue = (((message[i] - newKey[i]) + 26) % 26) + 'A';
        decryptedMsg[i] = asciiValue;
    }
    decryptedMsg[i] = '\0';
    
    strcpy(message, decryptedMsg);
}