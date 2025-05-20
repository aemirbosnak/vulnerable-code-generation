//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key, char *result);
void decrypt(char *message, char *key, char *result);

int main() {
    char message[100];
    char key[100];
    char result[100];
    int choice;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    printf("\nEnter key to encrypt message: ");
    fgets(key, sizeof(key), stdin);

    printf("\nChoose one of the following: ");
    printf("\n1. Encrypt message");
    printf("\n2. Decrypt message");
    printf("\nChoice: ");
    scanf("%d", &choice);
    while(getchar() != '\n'); //clear newline from input buffer
    
    if(choice == 1) {
        encrypt(message, key, result);
        printf("\nEncrypted message: %s", result);
    }
    else if(choice == 2) {
        decrypt(message, key, result);
        printf("\nDecrypted message: %s", result);
    }
    else {
        printf("\nInvalid choice!");
    }
    
    return 0;
}

void encrypt(char *message, char *key, char *result) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int i, j;
    
    for(i = 0, j = 0; i < messageLength; ++i, ++j) {
        if(j == keyLength) {
            j = 0;
        }
        result[i] = message[i] ^ key[j];
    }
    result[i] = '\0';
}

void decrypt(char *message, char *key, char *result) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int i, j;
    
    for(i = 0, j = 0; i < messageLength; ++i, ++j) {
        if(j == keyLength) {
            j = 0;
        }
        result[i] = message[i] ^ key[j];
    }
    result[i] = '\0';
}