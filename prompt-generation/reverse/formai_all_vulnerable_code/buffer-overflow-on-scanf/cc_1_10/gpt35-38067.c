//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// This is a one-time pad encryption algorithm that uses
// XOR operation to encrypt an input string.
void encrypt(char *message, char *key) {
    int i;
    int len = strlen(message);
    for(i=0; i<len; i++){
        message[i] ^= key[i%strlen(key)];
    }
}

// This function takes in an encrypted string and the original key used 
// for encryption as input and returns the original message.
void decrypt(char *encrypted, char *key) {
    int i;
    int len = strlen(encrypted);
    for(i=0; i<len; i++){
        encrypted[i] ^= key[i%strlen(key)];
    }
}

int main() {
    char message[MAX], key[MAX], encrypted[MAX];
    int choice;
    do{
        printf("Choose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter message to encrypt: ");
                scanf("%s", message);
                printf("Enter key: ");
                scanf("%s", key);
                encrypt(message, key);
                printf("The encrypted message is: %s\n", message);
                break;
            case 2:
                printf("Enter encrypted message: ");
                scanf("%s", encrypted);
                printf("Enter key: ");
                scanf("%s", key);
                decrypt(encrypted, key);
                printf("The original message is: %s\n", encrypted);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}