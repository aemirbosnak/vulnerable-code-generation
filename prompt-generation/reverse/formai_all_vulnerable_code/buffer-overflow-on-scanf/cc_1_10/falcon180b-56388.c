//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char* message) {
    int i, j, key = 0;
    char encrypted_message[100];

    // Shift the message by the key
    for(i=0, j=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted_message[j] = (((message[i] - 65 + key) % 26) + 65);
            } else {
                encrypted_message[j] = (((message[i] - 97 + key) % 26) + 97);
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    encrypted_message[j] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* message) {
    int i, j, key = 0;
    char decrypted_message[100];

    // Shift the message by the key
    for(i=0, j=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                decrypted_message[j] = (((message[i] - 65 - key + 26) % 26) + 65);
            } else {
                decrypted_message[j] = (((message[i] - 97 - key + 26) % 26) + 97);
            }
            j++;
        } else {
            decrypted_message[j] = message[i];
            j++;
        }
    }

    decrypted_message[j] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    char message[100];

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the message
    decrypt(message);

    return 0;
}