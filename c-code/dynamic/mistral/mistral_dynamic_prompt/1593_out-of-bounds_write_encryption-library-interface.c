#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    int len;
} CryptKey;

CryptKey createKey(char *str) {
    CryptKey k;
    k.key = str;
    k.len = strlen(str);
    return k;
}

char* encrypt(CryptKey key, char *plainText, char *cipherText, int maxLength) {
    int plainLength = strlen(plainText);

    if (key.len != 16 && key.len != 24 && key.len != 32) {
        printf("Error: Invalid key length\n");
        return NULL;
    }

    for (int i = 0; i < plainLength && i < maxLength; ++i) {
        cipherText[i] = plainText[i] ^ key.key[i % key.len];
    }

    if (plainLength < maxLength) {
        for (int i = plainLength; i < maxLength; ++i) {
            cipherText[i] = cipherText[i - plainLength] ^ key.key[(i % key.len) + 1]; // Out of bounds access
        }
    }

    cipherText[maxLength] = '\0';

    return cipherText;
}

int main() {
    CryptKey key = createKey("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    char plainText[] = "Meet me at the park at 3PM";
    char cipherText[100];

    encrypt(key, plainText, cipherText, strlen(plainText) + 1);

    printf("Plain Text: %s\n", plainText);
    printf("Cipher Text: %s\n", cipherText);

    return 0;
}
