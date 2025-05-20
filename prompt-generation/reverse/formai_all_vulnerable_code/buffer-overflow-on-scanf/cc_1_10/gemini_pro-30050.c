//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

int main() {
    // Let's get the party started!
    char input[1024];
    char key[1024];
    int mode;

    printf("Howdy, crypto kid! Let's encrypt or decrypt your secret message.\n");
    printf("Choose your adventure:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    scanf("%d", &mode);

    printf("Type in your secret message: ");
    scanf("%s", input);

    printf("Enter a secret key (make sure it's not longer than the message): ");
    scanf("%s", key);

    if (strlen(key) > strlen(input)) {
        printf("Hold yer horses, partner! Your key is too long. Keep it shorter than your message.\n");
        return 1;
    }

    int input_len = strlen(input);
    int key_len = strlen(key);
    char encrypted[input_len + 1];
    char decrypted[input_len + 1];

    // Time for the magic!
    if (mode == ENCRYPT) {
        for (int i = 0; i < input_len; i++) {
            encrypted[i] = input[i] ^ key[i % key_len];
        }
        encrypted[input_len] = '\0';
        printf("Your encrypted message: %s\n", encrypted);
    } else if (mode == DECRYPT) {
        for (int i = 0; i < input_len; i++) {
            decrypted[i] = encrypted[i] ^ key[i % key_len];
        }
        decrypted[input_len] = '\0';
        printf("Your decrypted message: %s\n", decrypted);
    } else {
        printf("Hey there, cowboy! That's not a valid choice. Pick 1 or 2 only.\n");
    }

    return 0;
}