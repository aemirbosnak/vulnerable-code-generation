//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int i, j;
    int msgLength = strlen(message);
    int keyLength = strlen(key);

    for(i = 0, j = 0; i < msgLength; ++i, ++j) {
        if(j >= keyLength) {
            j = 0;
        }
        
        message[i] = ((message[i] + key[j]) % 26) + 'a';
    }
}

void decrypt(char* message, char* key) {
    int i, j;
    int msgLength = strlen(message);
    int keyLength = strlen(key);

    for(i = 0, j = 0; i < msgLength; ++i, ++j) {
        if(j >= keyLength) {
            j = 0;
        }
        
        message[i] = (((message[i] - key[j]) + 26) % 26) + 'a';
    }
}

int main() {
    char message[500];
    char key[50];
    int choice;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}