//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int i = 0, j = 0;
    char encrypted_message[1000];

    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = ((message[i] - 'A' + key[j] - 'A') % 26) + 'A';
            } else {
                encrypted_message[j] = ((message[i] - 'a' + key[j] - 'a') % 26) + 'a';
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

// Function to decrypt the message
void decrypt(char* encrypted_message, char* key) {
    int i = 0, j = 0;
    char decrypted_message[1000];

    while (encrypted_message[i]!= '\0') {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = ((encrypted_message[i] - 'A' - key[j] + 26) % 26) + 'A';
            } else {
                decrypted_message[j] = ((encrypted_message[i] - 'a' - key[j] + 26) % 26) + 'a';
            }
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
        i++;
        j++;
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    char key[1000];

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the encryption/decryption key: ");
    scanf("%[^\n]", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}