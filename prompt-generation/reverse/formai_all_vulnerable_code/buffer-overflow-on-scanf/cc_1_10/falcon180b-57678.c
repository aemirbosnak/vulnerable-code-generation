//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define the size of the key
#define KEY_SIZE 16

// Define the S-box and P-box
char sbox[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char pbox[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

// Define the encryption and decryption functions
void encrypt(char *message, char *key) {
    int i, j, k;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            k = 0;
            while (key[k]!= '\0') {
                temp = sbox[j + (int)key[k] - 65];
                message[i] = temp;
                j = (j + 1) % 26;
                k++;
            }
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j, k;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            k = 0;
            while (key[k]!= '\0') {
                temp = pbox[j - (int)key[k] + 65];
                message[i] = temp;
                j = (j - 1 + 26) % 26;
                k++;
            }
        }
    }
}

// Define the main function
int main() {
    char message[100], key[KEY_SIZE];
    int i, n;
    char ch;

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the encryption key: ");
    for (i = 0; i < KEY_SIZE; i++) {
        ch = getchar();
        key[i] = ch;
    }

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}