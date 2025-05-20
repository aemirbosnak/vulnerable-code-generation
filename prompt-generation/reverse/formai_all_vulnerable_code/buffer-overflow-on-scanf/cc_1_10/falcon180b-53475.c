//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1000

void generate_key(char *key, int key_size) {
    srand(time(NULL));

    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char *text, char *key, int key_size) {
    for (int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]);
        int k = key[i % key_size];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + (k - 65) % 26;
            } else {
                c = 'a' + (k - 97) % 26;
            }
        }

        printf("%c", c);
    }
}

void decrypt(char *text, char *key, int key_size) {
    for (int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]);
        int k = key[i % key_size];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + (k - 65 + 26) % 26;
            } else {
                c = 'a' + (k - 97 + 26) % 26;
            }
        }

        printf("%c", c);
    }
}

int main() {
    char text[MAX_TEXT_SIZE], key[MAX_KEY_SIZE];

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    printf("Encrypted text: ");
    encrypt(text, key, strlen(key));
    printf("\n");

    printf("Decrypted text: ");
    decrypt(text, key, strlen(key));
    printf("\n");

    return 0;
}