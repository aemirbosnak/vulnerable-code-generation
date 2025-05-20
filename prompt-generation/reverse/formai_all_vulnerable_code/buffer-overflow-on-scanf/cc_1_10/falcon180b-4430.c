//Falcon-180B DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void generate_key(char key[KEY_SIZE]) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i;

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

char encrypt(char plaintext, char key) {
    int ascii_value = plaintext;
    int key_value = key;

    ascii_value = ascii_value + key_value;

    if (ascii_value > 122) {
        ascii_value = ascii_value - 26;
    } else if (ascii_value < 97) {
        ascii_value = ascii_value + 26;
    }

    return ascii_value;
}

char decrypt(char ciphertext, char key) {
    int ascii_value = ciphertext;
    int key_value = key;

    ascii_value = ascii_value - key_value;

    if (ascii_value > 122) {
        ascii_value = ascii_value - 26;
    } else if (ascii_value < 97) {
        ascii_value = ascii_value + 26;
    }

    return ascii_value;
}

int main() {
    char key[KEY_SIZE];
    char plaintext[100];
    char ciphertext[100];
    int i;

    generate_key(key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    for (i = 0; plaintext[i]!= '\0'; i++) {
        ciphertext[i] = encrypt(plaintext[i], key[i % KEY_SIZE]);
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    for (i = 0; ciphertext[i]!= '\0'; i++) {
        plaintext[i] = decrypt(ciphertext[i], key[i % KEY_SIZE]);
    }

    plaintext[i] = '\0';

    printf("Plaintext: %s\n", plaintext);

    return 0;
}