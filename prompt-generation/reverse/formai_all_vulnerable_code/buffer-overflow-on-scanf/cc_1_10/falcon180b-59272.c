//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 256
#define MAX_PLAINTEXT_LEN 1000
#define MAX_CIPHERTEXT_LEN (MAX_PLAINTEXT_LEN + 1)

int main() {
    char key[MAX_KEY_LEN + 1] = "";
    char plaintext[MAX_PLAINTEXT_LEN + 1] = "";
    char ciphertext[MAX_CIPHERTEXT_LEN + 1] = "";
    int i, j, k, n, len;

    // Get the key from the user
    printf("Enter the encryption key (up to %d characters):\n", MAX_KEY_LEN);
    scanf("%s", key);

    // Get the plaintext from the user
    printf("Enter the plaintext (up to %d characters):\n", MAX_PLAINTEXT_LEN);
    scanf("%s", plaintext);

    // Encrypt the plaintext using the key
    len = strlen(plaintext);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = 'A' + ((int) plaintext[i] - 65 + (int) key[j] - 65) % 26;
            } else {
                plaintext[i] = 'a' + ((int) plaintext[i] - 97 + (int) key[j] - 97) % 26;
            }
        }
        j = (j + 1) % strlen(key);
    }
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the ciphertext using the key
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = 'A' + (((int) plaintext[i] - 65 - (int) key[j] - 65) % 26 + 26) % 26;
            } else {
                plaintext[i] = 'a' + (((int) plaintext[i] - 97 - (int) key[j] - 97) % 26 + 26) % 26;
            }
        }
        j = (j + 1) % strlen(key);
    }
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}