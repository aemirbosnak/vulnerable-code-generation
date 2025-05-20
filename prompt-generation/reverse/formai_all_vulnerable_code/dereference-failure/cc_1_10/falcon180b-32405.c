//Falcon-180B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_TEXT_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char text[MAX_TEXT_LENGTH];
    int text_length;
} EncryptionContext;

EncryptionContext* create_context() {
    EncryptionContext* context = (EncryptionContext*) malloc(sizeof(EncryptionContext));
    context->key_length = 0;
    context->text_length = 0;
    return context;
}

void destroy_context(EncryptionContext* context) {
    free(context);
}

int is_valid_key_character(char c) {
    return isalnum(c);
}

int is_valid_text_character(char c) {
    return isprint(c);
}

void generate_key(EncryptionContext* context, int key_length) {
    char* key = (char*) malloc(key_length + 1);
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
    strcpy(context->key, key);
    context->key_length = key_length;
    free(key);
}

void encrypt_text(EncryptionContext* context) {
    char* key = context->key;
    int key_length = context->key_length;
    char* text = context->text;
    int text_length = context->text_length;
    char* encrypted_text = (char*) malloc(text_length + 1);
    for (int i = 0; i < text_length; i++) {
        char c = toupper(text[i]);
        if (is_valid_text_character(c)) {
            encrypted_text[i] = (char) ((c - 'A' + key_length - 1) % key_length + 'A');
        } else {
            encrypted_text[i] = c;
        }
    }
    encrypted_text[text_length] = '\0';
    strcpy(context->text, encrypted_text);
    free(encrypted_text);
}

void decrypt_text(EncryptionContext* context) {
    char* key = context->key;
    int key_length = context->key_length;
    char* text = context->text;
    int text_length = context->text_length;
    char* decrypted_text = (char*) malloc(text_length + 1);
    for (int i = 0; i < text_length; i++) {
        char c = toupper(text[i]);
        if (is_valid_text_character(c)) {
            char k = key[c - 'A'];
            decrypted_text[i] = (char) ((k - 1 + 26) % 26 + 'A');
        } else {
            decrypted_text[i] = c;
        }
    }
    decrypted_text[text_length] = '\0';
    strcpy(context->text, decrypted_text);
    free(decrypted_text);
}

int main() {
    EncryptionContext* context = create_context();
    generate_key(context, 10);
    strcpy(context->text, "Hello, world!");
    encrypt_text(context);
    printf("Encrypted text: %s\n", context->text);
    decrypt_text(context);
    printf("Decrypted text: %s\n", context->text);
    destroy_context(context);
    return 0;
}