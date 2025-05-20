//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
        i++;
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key;
            if (message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        }
        i++;
    }
}

int main() {
    char message[100];
    int key, choice;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    printf("Enter 1 to decrypt or 0 to exit: ");
    scanf("%d", &choice);
    if (choice == 1) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    return 0;
}