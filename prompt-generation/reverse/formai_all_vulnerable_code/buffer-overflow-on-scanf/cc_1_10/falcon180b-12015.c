//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to encrypt the message using the Caesar cipher
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) (((int) message[i] - 97 + key) % 26 + 97);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) (((int) message[i] - 65 + key) % 26 + 65);
        }
        i++;
    }
}

// Function to decrypt the message using the Caesar cipher
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) (((int) message[i] - 97 - key + 26) % 26 + 97);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) (((int) message[i] - 65 - key + 26) % 26 + 65);
        }
        i++;
    }
}

// Function to generate a random key between 1 and 25
int generate_key() {
    return rand() % 26 + 1;
}

int main() {
    srand(time(NULL));

    // Prompt the user to enter a message
    printf("Enter a message to encrypt/decrypt: ");
    char message[100];
    scanf("%s", message);

    // Prompt the user to choose between encryption and decryption
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    // Generate a random key
    int key = generate_key();

    // Encrypt or decrypt the message based on the user's choice
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}