#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 26
#define ALPHABET_SIZE (KEY_SIZE * 2)

void generateKey(char *key) {
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = 'A' + (i % KEY_SIZE);
        key[KEY_SIZE + i] = 'A' + (i + KEY_SIZE) % KEY_SIZE;
    }
}

int main() {
    char input[100], output[100], key[KEY_SIZE];
    generateKey(key);

    printf("Enter a string to encrypt: ");
    scanf("%s", input);

    for (int i = 0, j = 0; input[i] != '\0'; ++i, ++j) {
        if (isalpha(input[i])) {
            output[j] = (isupper(input[i]) ? toupper(key[(int)input[i] - 'A']) : tolower(key[(int)input[i] - 'a']));
        } else {
            output[j] = input[i];
        }
    }
    output[strlen(input)] = '\0';

    printf("Encrypted string: %s\n", output);
    return 0;
}
