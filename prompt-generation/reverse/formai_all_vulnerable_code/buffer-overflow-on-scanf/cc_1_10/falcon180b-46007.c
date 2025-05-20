//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* output) {
    int i, j, k;
    int key_index = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                output[i] = 'A' + ((text[i] - 'A' + key_index) % 26);
            } else {
                output[i] = 'a' + ((text[i] - 'a' + key_index) % 26);
            }
        } else {
            output[i] = text[i];
        }

        key_index = (key_index + 1) % strlen(key);
    }
}

void decrypt(char* key, char* text, char* output) {
    int i, j, k;
    int key_index = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                output[i] = 'A' + ((text[i] - 'A' - key_index + 26) % 26);
            } else {
                output[i] = 'a' + ((text[i] - 'a' - key_index + 26) % 26);
            }
        } else {
            output[i] = text[i];
        }

        key_index = (key_index + 1) % strlen(key);
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char output[MAX_TEXT_LENGTH];

    printf("Enter the key for encryption: ");
    scanf("%s", key);

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    encrypt(key, text, output);

    printf("\nEncrypted text: %s\n", output);

    printf("Enter the encrypted text for decryption: ");
    scanf("%s", output);

    printf("Enter the key for decryption: ");
    scanf("%s", key);

    decrypt(key, output, text);

    printf("\nDecrypted text: %s\n", text);

    return 0;
}