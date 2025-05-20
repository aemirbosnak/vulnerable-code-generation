//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 26

char key[KEY_SIZE];

void load_key() {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        if (i == 0) {
            key[i] = 'A';
        } else {
            key[i] = key[i - 1] + 1;
        }
    }
}

char encrypt_char(char c) {
    int index = (int)c - 65;
    if (index < 0) {
        index += KEY_SIZE;
    }
    return key[index];
}

void encrypt_string(char* str) {
    int i, len;
    len = strlen(str);

    for (i = 0; i < len; i++) {
        str[i] = encrypt_char(str[i]);
    }
}

int main() {
    char input[100], output[100];

    load_key();

    printf("Enter a string to encrypt: ");
    scanf("%s", input);

    encrypt_string(input);

    printf("Encrypted string: %s\n", input);

    return 0;
}