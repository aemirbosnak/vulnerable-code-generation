//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Ken Thompson-style Cryptography Implementation
 *
 * This program uses the well-known Ken Thompson-style
 * cryptography method to encrypt and decrypt a message.
 * The user provides the key and the message to be encrypted
 * or decrypted.
 *
 * To encrypt a message:
 * - Convert each character in the message to its ASCII code
 * - Add the corresponding character in the key to the ASCII code
 * - Convert the sum back to a character and append it to the output
 *
 * To decrypt a message:
 * - Convert each character in the message to its ASCII code
 * - Subtract the corresponding character in the key from the ASCII code
 * - Convert the difference back to a character and append it to the output
 */

int main()
{
    char key[100];
    char message[100];
    char output[100] = "";
    int key_len;
    int msg_len;

    // Get the key from the user
    printf("Enter key: ");
    fgets(key, 100, stdin);
    key_len = strlen(key) - 1;
    key[key_len] = '\0';

    // Get the message from the user
    printf("Enter message: ");
    fgets(message, 100, stdin);
    msg_len = strlen(message) - 1;
    message[msg_len] = '\0';

    // Encrypt the message
    for (int i = 0; i < msg_len; i++) {
        int key_idx = i % key_len;
        int encrypted = (int)message[i] + (int)key[key_idx];
        char encrypted_char = (char)encrypted;
        strncat(output, &encrypted_char, 1);
    }

    printf("Encrypted message: %s\n", output);

    // Decrypt the message
    char decrypted_output[100] = "";
    for (int i = 0; i < msg_len; i++) {
        int key_idx = i % key_len;
        int decrypted = (int)output[i] - (int)key[key_idx];
        char decrypted_char = (char)decrypted;
        strncat(decrypted_output, &decrypted_char, 1);
    }

    printf("Decrypted message: %s\n", decrypted_output);

    return 0;
}