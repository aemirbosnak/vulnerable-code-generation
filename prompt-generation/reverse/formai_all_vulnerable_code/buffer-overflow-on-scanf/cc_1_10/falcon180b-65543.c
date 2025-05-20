//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_TEXT_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
} CaesarCipher;

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
    char text[MAX_TEXT_LENGTH];
    int text_length;
    int i;

    printf("Enter the length of the key (must be between 1 and 64): ");
    scanf("%d", &key_length);

    if (key_length < 1 || key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }

    generate_key(key, key_length);

    printf("Enter the text to encrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text_length = strlen(text);

    if (text_length <= 0) {
        printf("Empty text.\n");
        return 1;
    }

    printf("Enter the shift value (must be between 1 and 25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Invalid shift value.\n");
        return 1;
    }

    for (i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';

            if (index >= 0 && index < 26) {
                int new_index = (index + shift - 1) % 26;
                text[i] = (char) (new_index + 'a');
            } else if (index >= 0 && index < 52) {
                int new_index = (index + shift - 26) % 26;
                text[i] = (char) (new_index + 'A');
            }
        }
    }

    printf("Encrypted text: %s\n", text);

    return 0;
}