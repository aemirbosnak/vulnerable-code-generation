//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following code is inspired by the legendary Linus Torvalds' notoriously blunt and direct style of communication.

// This function prints a colorful error message and exits the program.
void die(const char *message)
{
    printf("**** %s ****\n", message);
    exit(1);
}

// This function encrypts a string using the XOR cipher.
char *encrypt(char *plaintext, char *key)
{
    // Check if the key is valid.
    if (strlen(key) == 0)
        die("No key provided!");

    // Allocate memory for the ciphertext.
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Encrypt the plaintext character by character.
    for (int i = 0; i < strlen(plaintext); i++)
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];

    // Null-terminate the ciphertext.
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext.
    return ciphertext;
}

int main()
{
    // Read the plaintext and key from the user.
    char plaintext[1024];
    char key[128];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the plaintext.
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext.
    printf("Ciphertext: %s\n", ciphertext);

    // Free the memory allocated for the ciphertext.
    free(ciphertext);

    return 0;
}