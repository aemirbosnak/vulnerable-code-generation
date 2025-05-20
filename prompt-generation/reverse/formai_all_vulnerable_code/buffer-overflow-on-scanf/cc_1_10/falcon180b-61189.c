//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char text[MAX_TEXT_LENGTH];
    int text_length;
} encryption_t;

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt_text(encryption_t *encryption) {
    for (int i = 0; i < encryption->text_length; i++) {
        encryption->text[i] = (encryption->text[i] + encryption->key[i % encryption->key_length]) % 26 + 'a';
    }
}

void decrypt_text(encryption_t *encryption) {
    for (int i = 0; i < encryption->text_length; i++) {
        encryption->text[i] = (encryption->text[i] - encryption->key[i % encryption->key_length] + 26) % 26 + 'a';
    }
}

int main() {
    encryption_t encryption;
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text to encrypt/decrypt: ");
    scanf("%s", text);

    encryption.key_length = strlen(key);
    strcpy(encryption.key, key);

    encryption.text_length = strlen(text);
    strcpy(encryption.text, text);

    printf("Encrypted text: ");
    encrypt_text(&encryption);
    printf("%s\n", encryption.text);

    printf("Decrypted text: ");
    decrypt_text(&encryption);
    printf("%s\n", encryption.text);

    return 0;
}