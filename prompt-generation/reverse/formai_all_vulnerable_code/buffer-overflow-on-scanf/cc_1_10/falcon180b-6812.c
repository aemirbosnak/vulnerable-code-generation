//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_TEXT_SIZE 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';
}

void encrypt(char *text, char *key) {
    int i, j, k = 0;
    char cipher[MAX_TEXT_SIZE];
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                cipher[k] = 'A' + ((text[i] - 'A' + key[k % MAX_KEY_SIZE]) % 26);
            } else {
                cipher[k] = 'a' + ((text[i] - 'a' + key[k % MAX_KEY_SIZE]) % 26);
            }
        } else {
            cipher[k] = text[i];
        }
        k++;
    }
    cipher[k] = '\0';
    strcpy(text, cipher);
}

void decrypt(char *text, char *key) {
    int i, j, k = 0;
    char plain[MAX_TEXT_SIZE];
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                plain[k] = 'A' + (26 - (text[i] - key[k % MAX_KEY_SIZE] + 26) % 26);
            } else {
                plain[k] = 'a' + (26 - (text[i] - key[k % MAX_KEY_SIZE] + 26) % 26);
            }
        } else {
            plain[k] = text[i];
        }
        k++;
    }
    plain[k] = '\0';
    strcpy(text, plain);
}

int main() {
    char text[MAX_TEXT_SIZE], key[MAX_KEY_SIZE];
    printf("Enter the text to be encrypted: ");
    scanf("%s", text);
    printf("Enter the key (1-%d characters): ", MAX_KEY_SIZE);
    scanf("%s", key);
    generate_key(key);
    printf("Encrypted text: %s\n", text);
    encrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}