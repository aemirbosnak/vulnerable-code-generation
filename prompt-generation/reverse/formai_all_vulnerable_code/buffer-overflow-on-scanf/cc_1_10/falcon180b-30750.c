//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_TEXT_SIZE 10000

typedef struct {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char encrypted_text[MAX_TEXT_SIZE];
} EncryptionContext;

void generate_key(EncryptionContext *context) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        context->key[i] = rand() % 26 + 'a';
    }
    context->key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt_text(EncryptionContext *context) {
    int i, j;
    for (i = 0, j = 0; i < strlen(context->text); i++) {
        if (isalpha(context->text[i])) {
            context->encrypted_text[j++] = context->key[(int)context->text[i] - 'a']? context->key[(int)context->text[i] - 'a'] : 'z';
        } else {
            context->encrypted_text[j++] = context->text[i];
        }
    }
    context->encrypted_text[j] = '\0';
}

int main() {
    EncryptionContext context;
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];

    printf("Enter the key: ");
    scanf("%s", key);
    strcpy(context.key, key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);
    strcpy(context.text, text);

    generate_key(&context);
    encrypt_text(&context);

    printf("Encrypted text: %s\n", context.encrypted_text);

    return 0;
}