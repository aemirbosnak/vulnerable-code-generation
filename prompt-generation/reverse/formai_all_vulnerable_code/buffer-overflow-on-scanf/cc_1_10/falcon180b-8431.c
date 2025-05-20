//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
#define KEY "This is my secret key"

// Function to encrypt the message
void encrypt(char message[], char encrypted_message[]) {
    int i, j, k;
    char key_index = 0;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = 'A' + ((message[i] - 'A' + key_index) % SIZE);
            } else {
                encrypted_message[i] = 'a' + ((message[i] - 'a' + key_index) % SIZE);
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Function to decrypt the message
void decrypt(char encrypted_message[], char decrypted_message[]) {
    int i, j, k;
    char key_index = 0;

    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = 'A' + ((encrypted_message[i] - 'A' - key_index + SIZE) % SIZE);
            } else {
                decrypted_message[i] = 'a' + ((encrypted_message[i] - 'a' - key_index + SIZE) % SIZE);
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[1000], encrypted_message[1000], decrypted_message[1000];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    encrypt(message, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}