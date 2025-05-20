//Falcon-180B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ThisIsASecretKey"
#define KEY_LENGTH (strlen(KEY))

/* Function to encrypt the given string */
void encrypt(char* message, int message_length) {
    char* encrypted_message = malloc(message_length + 1);
    int j = 0;

    /* XOR each character of the message with the corresponding character in the key */
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ KEY[j];
        j = (j + 1) % KEY_LENGTH;
    }

    encrypted_message[message_length] = '\0';

    /* Print the encrypted message */
    printf("Encrypted message: %s\n", encrypted_message);
}

/* Function to decrypt the given string */
void decrypt(char* message, int message_length) {
    char* decrypted_message = malloc(message_length + 1);
    int j = 0;

    /* XOR each character of the message with the corresponding character in the key */
    for (int i = 0; i < message_length; i++) {
        decrypted_message[i] = message[i] ^ KEY[j];
        j = (j + 1) % KEY_LENGTH;
    }

    decrypted_message[message_length] = '\0';

    /* Print the decrypted message */
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100] = "Hello, world!";
    int message_length = strlen(message);

    /* Encrypt the message */
    encrypt(message, message_length);

    /* Decrypt the encrypted message */
    char* encrypted_message = malloc(message_length + 1);
    strcpy(encrypted_message, message);
    decrypt(encrypted_message, message_length);

    return 0;
}