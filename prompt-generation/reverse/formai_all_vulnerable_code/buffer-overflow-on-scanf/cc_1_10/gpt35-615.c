//FormAI DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 

void encrypt(char *str, int key) {
    int i;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + key) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + key) % 26 + 'A';
        }
    }
}

void decrypt(char *str, int key) {
    int i;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[MAX_LEN];
    int key;
    int choice;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
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
            break;
    }

    return 0;
}