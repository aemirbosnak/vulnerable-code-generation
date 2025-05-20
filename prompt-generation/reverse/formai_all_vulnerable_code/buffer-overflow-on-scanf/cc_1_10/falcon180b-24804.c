//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i = 0, j = 0;
    char encrypted_message[1000] = "";
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + key - 65) % 26 + 65;
            } else {
                encrypted_message[j] = (message[i] + key - 97) % 26 + 97;
            }
        } else {
            encrypted_message[j] = message[i];
        }
        i++;
        j++;
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i = 0, j = 0;
    char decrypted_message[1000] = "";
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[j] = (message[i] - key - 65) % 26 + 65;
            } else {
                decrypted_message[j] = (message[i] - key - 97) % 26 + 97;
            }
        } else {
            decrypted_message[j] = message[i];
        }
        i++;
        j++;
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    int key, choice;
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter the key (1-25): ");
    scanf("%d", &key);
    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);
    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}