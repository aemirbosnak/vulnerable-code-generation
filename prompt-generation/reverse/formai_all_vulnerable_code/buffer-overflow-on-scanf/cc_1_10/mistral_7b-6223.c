//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 5
#define ALPHABET_SIZE 26
#define SHIFT 1

typedef struct {
    char key[KEY_LENGTH];
    int shift;
} EncryptionKey;

void generate_key(EncryptionKey *key) {
    int i;
    char c;

    printf("Enter a %d character encryption key: ", KEY_LENGTH);
    for (i = 0; i < KEY_LENGTH; i++) {
        scanf("%c", &c);
        key->key[i] = c;
    }

    printf("Enter a shift value: ");
    scanf("%d", &key->shift);
}

void print_encrypted_text(char *plaintext, EncryptionKey key) {
    int i;
    char c;

    printf("\nEncrypted Text: ");
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            c = ((isupper(plaintext[i]) ? 'A' : 'a') + (int)plaintext[i] - (int)'A' + key.shift) % ALPHABET_SIZE + 'A';
            putchar(c);
        } else {
            putchar(plaintext[i]);
        }
    }
    putchar('\n');
}

int main() {
    EncryptionKey key;
    char plaintext[100];

    srand(time(NULL));

    generate_key(&key);

    printf("Enter a plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext)] = '\0';

    print_encrypted_text(plaintext, key);

    return 0;
}