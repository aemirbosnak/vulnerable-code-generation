//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int key) {
    int i, j, length = strlen(message);
    char encrypted_message[length];

    for(i = 0; i < length; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted_message[i] = (char)(((int)message[i] + key - 65) % 26 + 65);
            }
            else {
                encrypted_message[i] = (char)(((int)message[i] + key - 97) % 26 + 97);
            }
        }
        else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted Message: %s\n", encrypted_message);
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int key) {
    int i, j, length = strlen(message);
    char decrypted_message[length];

    for(i = 0; i < length; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                decrypted_message[i] = (char)(((int)message[i] - key - 65) % 26 + 65);
            }
            else {
                decrypted_message[i] = (char)(((int)message[i] - key - 97) % 26 + 97);
            }
        }
        else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted Message: %s\n", decrypted_message);
}

// Function to generate a random key
void generate_key() {
    int key = rand() % 26 + 1;
    printf("Random Key: %d\n", key);
}

int main() {
    char message[100];
    int choice;

    // Get message from user
    printf("Enter Message: ");
    scanf("%s", message);

    // Generate random key
    printf("Enter 1 to generate random key or any other key to enter key manually: ");
    scanf("%d", &choice);

    if(choice == 1) {
        generate_key();
    }
    else {
        printf("Enter Key: ");
        scanf("%d", &choice);
    }

    // Encrypt message using Caesar Cipher
    encrypt(message, choice);

    // Decrypt encrypted message using Caesar Cipher
    decrypt(message, choice);

    return 0;
}