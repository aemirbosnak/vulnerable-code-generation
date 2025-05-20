//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 5
#define MAX_INPUT_LENGTH 100

typedef struct {
    char key[KEY_SIZE];
    int shift;
} EncryptionKey;

void generate_key(EncryptionKey* key) {
    int i;

    for (i = 0; i < KEY_SIZE; i++) {
        key->key[i] = (i + 'A') % 26 + 'A';
    }

    printf("Your encryption key is: ");
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%c ", key->key[i]);
    }
    printf("\nShift: ");
    scanf("%d", &key->shift);
}

int main() {
    char plaintext[MAX_INPUT_LENGTH];
    char encrypted_text[MAX_INPUT_LENGTH];
    EncryptionKey key;

    printf("Welcome to AdaEncryptor! Encrypting messages in Ada Lovelace style...\n");
    generate_key(&key);

    printf("Enter a message to encrypt (up to %d characters): ", MAX_INPUT_LENGTH);
    fgets(plaintext, MAX_INPUT_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    int i, j;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            int index = islower(plaintext[i]) ? (int)plaintext[i] - 'a' : (int)plaintext[i] - 'A' + 26;
            int new_index = (index + key.shift + (int)key.key[index % 26]) % 26;
            encrypted_text[i] = new_index < 0 ? 'z' + (new_index + 26) : 'A' + new_index;
        } else {
            encrypted_text[i] = plaintext[i];
        }
    }

    encrypted_text[strlen(plaintext)] = '\0';

    printf("Encrypted message: %s\n", encrypted_text);

    return 0;
}