//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* string, int key) {
    for(int i=0; i<strlen(string); i++) {
        if(isalpha(string[i])) {
            if(islower(string[i])) {
                string[i] = ((string[i] - 'a' + key) % 26) + 'a';
            }
            else {
                string[i] = ((string[i] - 'A' + key) % 26) + 'A';
            }
        }
    }
}

void decrypt(char* string, int key) {
    for(int i=0; i<strlen(string); i++) {
        if(isalpha(string[i])) {
            if(islower(string[i])) {
                string[i] = ((string[i] - 'a' - key + 26) % 26) + 'a';
            }
            else {
                string[i] = ((string[i] - 'A' - key + 26) % 26) + 'A';
            }
        }
    }
}

int main() {
    char string[100];
    int key, choice;
    printf("Enter the string you want to encrypt/decrypt: ");
    fgets(string, 100, stdin);
    printf("Enter the key (an integer between 1-25): ");
    scanf("%d", &key);
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            encrypt(string, key);
            printf("Encrypted string: %s\n", string);
            break;
        case 2:
            decrypt(string, key);
            printf("Decrypted string: %s\n", string);
            break;
        default:
            printf("Invalid option!\n");
    }
    return 0;
}