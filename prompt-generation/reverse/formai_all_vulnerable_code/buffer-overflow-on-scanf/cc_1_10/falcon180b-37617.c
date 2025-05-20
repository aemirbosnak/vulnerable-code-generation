//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

int main() {
    char input_text[1000];
    char key[KEY_LENGTH];
    char encrypted_text[1000];
    char decrypted_text[1000];
    int i, j;

    // Get input text from user
    printf("Enter text to encrypt: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Get encryption key from user
    printf("Enter encryption key: ");
    for (i = 0; i < KEY_LENGTH; i++) {
        scanf("%c", &key[i]);
    }

    // Encrypt input text
    for (i = 0, j = 0; input_text[i]!= '\0'; i++) {
        if (isalpha(input_text[i])) {
            encrypted_text[j] = ((input_text[i] + key[i % KEY_LENGTH]) % 26) + 'A';
            j++;
        } else {
            encrypted_text[j] = input_text[i];
            j++;
        }
    }
    encrypted_text[j] = '\0';

    // Print encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Decrypt encrypted text
    for (i = 0, j = 0; encrypted_text[i]!= '\0'; i++) {
        if (isalpha(encrypted_text[i])) {
            decrypted_text[j] = ((encrypted_text[i] - key[i % KEY_LENGTH]) % 26) + 'A';
            j++;
        } else {
            decrypted_text[j] = encrypted_text[i];
            j++;
        }
    }
    decrypted_text[j] = '\0';

    // Print decrypted text
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}