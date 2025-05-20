//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/* Define the encryption key */
#define KEY "secret_key"

/* Function to encrypt the message */
void encrypt(char* message) {
    int i, j, n = strlen(message);
    char encrypted_message[n];

    /* Initialize the encryption key */
    char key[strlen(KEY)];
    for (i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }

    /* Encrypt the message */
    for (i = 0; i < n; i++) {
        encrypted_message[i] = message[i] + key[i % strlen(KEY)];
    }

    /* Print the encrypted message */
    printf("Encrypted message: %s\n", encrypted_message);
}

/* Function to decrypt the message */
void decrypt(char* message) {
    int i, j, n = strlen(message);
    char decrypted_message[n];

    /* Initialize the encryption key */
    char key[strlen(KEY)];
    for (i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }

    /* Decrypt the message */
    for (i = 0; i < n; i++) {
        decrypted_message[i] = message[i] - key[i % strlen(KEY)];
    }

    /* Print the decrypted message */
    printf("Decrypted message: %s\n", decrypted_message);
}

/* Main function */
int main() {
    char message[100];

    /* Get the message from the user */
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    /* Encrypt the message */
    encrypt(message);

    /* Decrypt the message */
    decrypt(message);

    return 0;
}