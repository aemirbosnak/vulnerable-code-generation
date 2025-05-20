//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function prototype to encrypt the plaintext
void encrypt(char message[], int key);

// function prototype to decrypt the ciphertext
void decrypt(char message[], int key);

int main() {
    char message[1000];
    int key, choice;

    // print a lively welcome message
    printf("Welcome to the Caesar Cipher program!\n\n");

    // prompt the user for input
    printf("Please enter a message to encrypt or decrypt: ");
    fgets(message, 1000, stdin);

    // prompt the user for the encryption/decryption key
    printf("Please enter the encryption/decryption key (a number between 1 and 25): ");
    scanf("%d", &key);

    // prompt the user to select the encryption/decryption option
    printf("Would you like to encrypt (1) or decrypt (2) the message? ");
    scanf("%d", &choice);

    // convert the input message to uppercase for consistency
    for (int i = 0; message[i]; i++) {
        message[i] = toupper(message[i]);
    }

    // choose the appropriate function based on the user's choice
    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    // print the encrypted or decrypted message
    printf("Your message is: %s\n", message);

    // lively goodbye message
    printf("Thanks for using the Caesar Cipher program! Have a great day!\n");

    return 0;
}

// function definition to encrypt the plaintext
void encrypt(char message[], int key) {
    // iterate over each character in the message
    for (int i = 0; message[i]; i++) {
        // if the character is not a letter, ignore it
        if (!isalpha(message[i])) {
            continue;
        }
        // shift the character by the key, wrapping around if necessary
        message[i] = (((message[i] - 'A') + key) % 26) + 'A';
    }
}

// function definition to decrypt the ciphertext
void decrypt(char message[], int key) {
    // iterate over each character in the message
    for (int i = 0; message[i]; i++) {
        // if the character is not a letter, ignore it
        if (!isalpha(message[i])) {
            continue;
        }
        // shift the character by the inverse of the key, wrapping around if necessary
        message[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';
    }
}