//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: lively
/*
 * Unique C Encryption Example Program
 *
 * This program uses a custom encryption algorithm to encrypt and decrypt text.
 *
 * Usage:
 * 1. Compile the program with a C compiler.
 * 2. Run the program with the following command:
 *    ./a.out <text_to_encrypt>
 * 3. The program will encrypt the text and display the encrypted text.
 * 4. To decrypt the text, run the program with the following command:
 *    ./a.out -d <encrypted_text>
 * 5. The program will decrypt the text and display the original text.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption algorithm
void encrypt(char *text, char *key) {
    int i, j;
    int key_len = strlen(key);
    int text_len = strlen(text);

    for (i = 0; i < text_len; i++) {
        text[i] = (text[i] + key[i % key_len]) % 256;
    }
}

void decrypt(char *text, char *key) {
    int i, j;
    int key_len = strlen(key);
    int text_len = strlen(text);

    for (i = 0; i < text_len; i++) {
        text[i] = (text[i] - key[i % key_len]) % 256;
    }
}

int main(int argc, char *argv[]) {
    char text[1024];
    char key[1024];
    int i;

    // Check if the correct number of arguments were passed
    if (argc != 2 && argc != 4) {
        printf("Usage: %s <text_to_encrypt> <key>\n", argv[0]);
        return 1;
    }

    // Get the text and key from the command line arguments
    strcpy(text, argv[1]);
    strcpy(key, argv[2]);

    // Check if the decryption flag is set
    if (argc == 4 && strcmp(argv[3], "-d") == 0) {
        // Decrypt the text
        decrypt(text, key);
    } else {
        // Encrypt the text
        encrypt(text, key);
    }

    // Print the encrypted/decrypted text
    printf("%s\n", text);

    return 0;
}