//Falcon-180B DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

void generate_key(char *key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

int encrypt(char *plaintext, char *key, char *ciphertext) {
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < plaintext_length; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j] = (int) plaintext[i] + (int) key[j % key_length] - 97;
            j++;
        } else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }

    ciphertext[j] = '\0';

    return 0;
}

int decrypt(char *ciphertext, char *key, char *plaintext) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < ciphertext_length; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j] = (int) ciphertext[i] - (int) key[j % key_length] + 97;
            j++;
        } else {
            plaintext[j] = ciphertext[i];
            j++;
        }
    }

    plaintext[j] = '\0';

    return 0;
}

int main() {
    char plaintext[MAX_KEY_LENGTH];
    char key[MAX_KEY_LENGTH];
    char ciphertext[MAX_KEY_LENGTH];

    // Get plaintext from user
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Generate random key
    generate_key(key, strlen(plaintext));

    // Encrypt plaintext using key
    encrypt(plaintext, key, ciphertext);

    // Print encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext using key
    decrypt(ciphertext, key, plaintext);

    // Print decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}