//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_PLAIN_TEXT_LENGTH 1000
#define MAX_CIPHER_TEXT_LENGTH (MAX_PLAIN_TEXT_LENGTH + 1)

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
} CipherContext;

void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(CipherContext* context, char* plain_text) {
    int plain_text_length = strlen(plain_text);
    char cipher_text[MAX_CIPHER_TEXT_LENGTH];
    cipher_text[plain_text_length] = '\0';

    for (int i = 0; i < plain_text_length; i++) {
        if (isalpha(plain_text[i])) {
            if (isupper(plain_text[i])) {
                cipher_text[i] = 'A' + ((plain_text[i] - 'A' + context->shift) % 26);
            } else {
                cipher_text[i] = 'a' + ((plain_text[i] - 'a' + context->shift) % 26);
            }
        } else {
            cipher_text[i] = plain_text[i];
        }
    }

    strcpy(plain_text, cipher_text);
}

void decrypt(CipherContext* context, char* cipher_text) {
    int cipher_text_length = strlen(cipher_text);
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    plain_text[cipher_text_length] = '\0';

    for (int i = 0; i < cipher_text_length; i++) {
        if (isalpha(cipher_text[i])) {
            if (isupper(cipher_text[i])) {
                plain_text[i] = 'A' + ((cipher_text[i] - 'A' - context->shift + 26) % 26);
            } else {
                plain_text[i] = 'a' + ((cipher_text[i] - 'a' - context->shift + 26) % 26);
            }
        } else {
            plain_text[i] = cipher_text[i];
        }
    }

    strcpy(cipher_text, plain_text);
}

int main() {
    CipherContext context;
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    char cipher_text[MAX_CIPHER_TEXT_LENGTH];

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    generate_key(context.key, rand() % MAX_KEY_LENGTH + 1);
    context.key_length = strlen(context.key);
    context.shift = rand() % 26;

    encrypt(&context, plain_text);

    printf("Encrypted text: %s\n", plain_text);

    decrypt(&context, plain_text);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}