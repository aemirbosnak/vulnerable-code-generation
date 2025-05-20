//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
    char message[MAX_STRING_LENGTH];
    int key;
    int option;
    
    printf("Welcome to the encryption program!\n");
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Please enter your message:\n");
                fflush(stdin);
                scanf("%[^\n]", message);
                printf("Please enter the encryption key (1-26):\n");
                scanf("%d", &key);
                encrypt(message, key);
                printf("\nEncrypted message: %s\n", message);
                break;
            case 2:
                printf("Please enter the encrypted message:\n");
                fflush(stdin);
                scanf("%[^\n]", message);
                printf("Please enter the decryption key (1-26):\n");
                scanf("%d", &key);
                decrypt(message, key);
                printf("\nDecrypted message: %s\n", message);
                break;
            case 3:
                printf("Thank you for using the encryption program!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while(option != 3);
    
    return 0;
}

void encrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        // Shift each character by the key value
        if(message[i] >= 'a' && message[i] <= 'z') {
            // Lowercase letter
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            // Uppercase letter
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        // Shift each character back by the key value
        if(message[i] >= 'a' && message[i] <= 'z') {
            // Lowercase letter
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            // Uppercase letter
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}