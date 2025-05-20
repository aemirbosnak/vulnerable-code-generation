//Falcon-180B DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_PLAIN_TEXT_LENGTH 100
#define MAX_CIPHER_TEXT_LENGTH 200

void generate_key(char *key) {
    int i = 0;
    while (i < MAX_KEY_LENGTH) {
        key[i] = rand() % 26 + 'A';
        i++;
    }
    key[MAX_KEY_LENGTH-1] = '\0';
}

void encrypt(char *plain_text, char *key, char *cipher_text) {
    int i = 0, j = 0;
    while (plain_text[i]!= '\0') {
        if (isalpha(plain_text[i])) {
            cipher_text[j] = (char) ((int) plain_text[i] + (int) key[i % MAX_KEY_LENGTH] - 65);
            i++;
            j++;
        } else {
            cipher_text[j] = plain_text[i];
            i++;
            j++;
        }
    }
    cipher_text[j] = '\0';
}

void decrypt(char *cipher_text, char *key, char *plain_text) {
    int i = 0, j = 0;
    while (cipher_text[i]!= '\0') {
        if (isalpha(cipher_text[i])) {
            plain_text[j] = (char) ((int) cipher_text[i] - (int) key[i % MAX_KEY_LENGTH] + 65);
            i++;
            j++;
        } else {
            plain_text[j] = cipher_text[i];
            i++;
            j++;
        }
    }
    plain_text[j] = '\0';
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char cipher_text[MAX_CIPHER_TEXT_LENGTH];

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    generate_key(key);

    encrypt(plain_text, key, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(cipher_text, key, plain_text);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}