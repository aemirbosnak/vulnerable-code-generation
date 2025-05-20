//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32

// Encrypt a string using a key
void encrypt(char *input, char *key) {
    int i, j, k;
    char output[strlen(input)];
    char *encrypt_key = (char *) malloc(MAX_KEY_LENGTH * sizeof(char));

    // Generate encryption key
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        encrypt_key[i] = rand() % 26 + 'a';
    }

    // Apply encryption
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j] = encrypt_key[(int) input[i] - 65];
            } else {
                output[j] = encrypt_key[(int) input[i] - 97];
            }
        } else {
            output[j] = input[i];
        }
        j++;
    }

    // Apply key to encryption
    for (i = 0, j = 0; i < MAX_KEY_LENGTH; i++) {
        if (key[i]!= '\0') {
            k = (int) key[i] - 97;
            if (k >= 0 && k < 26) {
                output[j] = encrypt_key[(int) output[j] - 65 + k];
            }
        }
        j++;
    }

    // Print encrypted string
    printf("Encrypted string: %s\n", output);

    free(encrypt_key);
}

int main() {
    char input[1000], key[MAX_KEY_LENGTH];

    // Get input string
    printf("Enter input string: ");
    scanf("%s", input);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Encrypt input string
    encrypt(input, key);

    return 0;
}