//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key
#define KEY "mysecretkey"

// Define the encryption function
void encrypt(char* message, int length, char* encrypted_message) {
    int i, j;
    for(i=0, j=0; i<length; i++, j++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted_message[j] = 'A' + ((message[i] - 'A' + 13) % 26);
            } else {
                encrypted_message[j] = 'a' + ((message[i] - 'a' + 13) % 26);
            }
        } else {
            encrypted_message[j] = message[i];
        }
    }
    encrypted_message[j] = '\0';
}

// Define the decryption function
void decrypt(char* encrypted_message, int length, char* decrypted_message) {
    int i, j;
    for(i=0, j=0; i<length; i++, j++) {
        if(isalpha(encrypted_message[i])) {
            if(isupper(encrypted_message[i])) {
                decrypted_message[j] = 'A' + ((encrypted_message[i] - 'A' - 13 + 26) % 26);
            } else {
                decrypted_message[j] = 'a' + ((encrypted_message[i] - 'a' - 13 + 26) % 26);
            }
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';
}

// Define the main function
int main(int argc, char* argv[]) {
    char message[100], encrypted_message[200], decrypted_message[100];
    int length;

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    length = strlen(message);

    // Encrypt the message
    encrypt(message, length, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(encrypted_message, length, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}