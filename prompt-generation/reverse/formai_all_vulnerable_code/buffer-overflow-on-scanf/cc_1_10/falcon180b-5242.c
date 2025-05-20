//Falcon-180B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define the encryption key */
#define KEY "MySecretKey123"

/* Define the maximum length of the input message */
#define MAX_LENGTH 100

/* Define the encryption function */
void encrypt(char* message) {
    int i, j;
    char encrypted_message[MAX_LENGTH];

    /* Initialize the encrypted message with the original message */
    strcpy(encrypted_message, message);

    /* Loop through each character in the message */
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        /* Convert the character to uppercase */
        message[i] = toupper(message[i]);

        /* Encrypt the character using the key */
        encrypted_message[i] = message[i] ^ KEY[j];

        /* Increment the key index */
        j = (j + 1) % strlen(KEY);
    }

    /* Print the encrypted message */
    printf("Encrypted message: %s\n", encrypted_message);
}

/* Define the decryption function */
void decrypt(char* message) {
    int i, j;
    char decrypted_message[MAX_LENGTH];

    /* Initialize the decrypted message with the encrypted message */
    strcpy(decrypted_message, message);

    /* Loop through each character in the message */
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        /* Decrypt the character using the key */
        decrypted_message[i] = message[i] ^ KEY[j];

        /* Increment the key index */
        j = (j + 1) % strlen(KEY);
    }

    /* Print the decrypted message */
    printf("Decrypted message: %s\n", decrypted_message);
}

/* Define the main function */
int main() {
    char message[MAX_LENGTH];

    /* Prompt the user to enter a message */
    printf("Enter a message: ");
    scanf("%s", message);

    /* Encrypt the message */
    encrypt(message);

    /* Decrypt the encrypted message */
    decrypt(message);

    return 0;
}