//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* result, int key_index) {
    if (key_index == strlen(key)) {
        strcpy(result, text);
        return;
    }

    char current_key_char = toupper(key[key_index]);
    int ascii_value = (int)current_key_char;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char current_text_char = toupper(text[i]);
            int current_ascii_value = (int)current_text_char;

            if (current_ascii_value >= ascii_value) {
                result[i] = text[i] + (ascii_value - current_ascii_value);
            } else {
                result[i] = text[i] - (current_ascii_value - ascii_value);
            }
        } else {
            result[i] = text[i];
        }
    }

    encrypt(key, text, result, key_index + 1);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    char result[MAX_TEXT_LENGTH];
    encrypt(key, text, result, 0);

    printf("Encrypted text: %s\n", result);

    return 0;
}