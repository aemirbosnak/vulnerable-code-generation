//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int mode;
} encryption_t;

void encrypt(encryption_t *e, char *text) {
    int i, j;
    char *key = e->key;
    int key_length = e->key_length;
    int mode = e->mode;

    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (isupper(c)) {
            c = 'A' + ((c - 'A' + key_length) % key_length);
        } else if (islower(c)) {
            c = 'a' + ((c - 'a' + key_length) % key_length);
        } else if (isdigit(c)) {
            c = '0' + ((c - '0' + key_length) % key_length);
        }
        text[i] = c;
    }

    if (mode == 1) {
        for (i = 0, j = strlen(text) - 1; i < j; i++, j--) {
            char temp = text[i];
            text[i] = text[j];
            text[j] = temp;
        }
    }
}

int main() {
    encryption_t e;
    char text[MAX_TEXT_LENGTH];
    int key_length, i;

    printf("Enter encryption key: ");
    scanf("%s", e.key);
    key_length = strlen(e.key);

    printf("Enter text to encrypt: ");
    scanf("%s", text);

    printf("Enter encryption mode (0 for Caesar cipher, 1 for reverse text): ");
    scanf("%d", &e.mode);

    encrypt(&e, text);
    printf("Encrypted text: %s\n", text);

    return 0;
}