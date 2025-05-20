//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: complex
// Unique C Encryption Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the encryption and decryption functions
void encrypt(char *msg, int key) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ key;
    }
}

void decrypt(char *msg, int key) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ key;
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments are provided
    if (argc != 4) {
        printf("Usage: %s <message> <key> <action>\n", argv[0]);
        return 1;
    }

    // Get the message and key from the command line arguments
    char *message = argv[1];
    int key = atoi(argv[2]);
    char *action = argv[3];

    // Check if the action is valid
    if (strcmp(action, "encrypt") != 0 && strcmp(action, "decrypt") != 0) {
        printf("Invalid action: %s\n", action);
        return 1;
    }

    // Encrypt or decrypt the message
    if (strcmp(action, "encrypt") == 0) {
        encrypt(message, key);
    } else {
        decrypt(message, key);
    }

    // Print the result
    printf("%s\n", message);

    return 0;
}