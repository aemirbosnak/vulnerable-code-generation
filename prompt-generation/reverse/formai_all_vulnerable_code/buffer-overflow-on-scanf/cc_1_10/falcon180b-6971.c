//Falcon-180B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_TEXT_SIZE 1024

void encrypt(char *key, char *text, char *result) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    int result_length = 0;
    int i, j;

    for (i = 0, j = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[result_length++] = (char) (((int) text[i] + (int) key[j % key_length]) % 26 + 65);
            } else {
                result[result_length++] = (char) (((int) text[i] + (int) key[j % key_length]) % 26 + 97);
            }
        } else {
            result[result_length++] = text[i];
        }
        j++;
    }

    result[result_length] = '\0';
}

void decrypt(char *key, char *text, char *result) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    int result_length = 0;
    int i, j;

    for (i = 0, j = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[result_length++] = (char) (((int) text[i] - (int) key[j % key_length] + 26) % 26 + 65);
            } else {
                result[result_length++] = (char) (((int) text[i] - (int) key[j % key_length] + 26) % 26 + 97);
            }
        } else {
            result[result_length++] = text[i];
        }
        j++;
    }

    result[result_length] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char result[MAX_TEXT_SIZE];

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    encrypt(key, text, result);

    printf("Encrypted text: %s\n", result);

    printf("Enter the encrypted text: ");
    scanf("%s", result);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    decrypt(key, result, text);

    printf("Decrypted text: %s\n", text);

    return 0;
}