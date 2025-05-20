//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3

char shift_char(char c, int shift) {
    if (isalpha(c)) {
        if (isupper(c))
            return (char)(((int)c + shift - 65) % 26 + 65);
        else
            return (char)(((int)c + shift - 97) % 26 + 97);
    } else {
        return c;
    }
}

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = shift_char(plaintext[i], KEY);
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);

    printf("Enter key (1-25): ");
    int key;
    scanf("%d", &key);

    printf("Key: %d\n", key);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");

    encrypt(plaintext, ciphertext); // Encrypt again with the entered key

    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        putchar(ciphertext[i]);
    }
    putchar('\n');

    return 0;
}