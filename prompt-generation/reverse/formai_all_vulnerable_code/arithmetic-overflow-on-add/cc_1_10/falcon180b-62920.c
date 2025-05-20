//Falcon-180B DATASET v1.0 Category: Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i;
    for(i=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            }
            else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
    }
}

// Function to decrypt the encrypted message using Caesar cipher
void decrypt(char message[], int key) {
    int i;
    for(i=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - key - 65 + 26) % 26 + 65;
            }
            else {
                message[i] = (message[i] - key - 97 + 26) % 26 + 97;
            }
        }
    }
}

int main() {
    char message[SIZE];
    int key, choice;

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Choose the operation:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if(choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}