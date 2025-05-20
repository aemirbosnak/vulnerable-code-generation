//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

// Function to encrypt the text using the key
void encrypt(char* text, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (char) (((int) text[i] - 65 + (int) key[j]) % 26 + 65);
            } else {
                text[i] = (char) (((int) text[i] - 97 + (int) key[j]) % 26 + 97);
            }
            j++;
            if (j == strlen(key)) {
                j = 0;
            }
        }
    }
}

// Function to decrypt the text using the key
void decrypt(char* text, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (char) (((int) text[i] - 65 - (int) key[j]) % 26 + 65);
            } else {
                text[i] = (char) (((int) text[i] - 97 - (int) key[j]) % 26 + 97);
            }
            j++;
            if (j == strlen(key)) {
                j = 0;
            }
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];
    printf("Enter the text to encrypt: ");
    scanf("%s", text);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}