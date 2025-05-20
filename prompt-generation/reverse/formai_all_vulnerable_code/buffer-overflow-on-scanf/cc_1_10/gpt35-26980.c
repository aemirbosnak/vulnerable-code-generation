//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    char n;
    for(i = 0; i < strlen(message); i++) {
        n = message[i];
        if(n >= 'a' && n <= 'z') {
            message[i] = ((n - 'a') + key) % 26 + 'a';
        }
        if(n >= 'A' && n <= 'Z') {
            message[i] = ((n - 'A') + key) % 26 + 'A';
        }
    }
    printf("Encrypted Message: %s\n", message);
}

void decrypt(char* message, int key) {
    int i;
    char n;
    for(i = 0; i < strlen(message); i++) {
        n = message[i];
        if(n >= 'a' && n <= 'z') {
            message[i] = (((n - 'a') - key) + 26) % 26 + 'a';
        }
        if(n >= 'A' && n <= 'Z') {
            message[i] = (((n - 'A') - key) + 26) % 26 + 'A';
        }
    }
    printf("Decrypted Message: %s\n", message);
}

int main() {
    char message[100];
    int key;
    int choice;
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    printf("What would you like to do?\n1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) encrypt(message, key);
    else if(choice == 2) decrypt(message, key);
    else printf("Invalid choice");
    return 0;
}