//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_INPUT_LENGTH 1024

void encrypt(char *key, char *input, char *output) {
    int key_length = strlen(key);
    int input_length = strlen(input);
    int output_length = input_length + 1;
    char *output_ptr = output + output_length - 1;

    for (int i = 0; i < input_length; i++) {
        char c = toupper(input[i]);
        int key_index = (c - 65) % key_length;

        if (isalpha(c)) {
            *output_ptr = (char) (((int) c + (int) key[key_index]) % 26 + 65);
        } else {
            *output_ptr = c;
        }
        output_ptr--;
    }
}

void decrypt(char *key, char *input, char *output) {
    int key_length = strlen(key);
    int input_length = strlen(input);
    int output_length = input_length + 1;
    char *output_ptr = output + output_length - 1;

    for (int i = 0; i < input_length; i++) {
        char c = toupper(input[i]);
        int key_index = (c - 65) % key_length;

        if (isalpha(c)) {
            *output_ptr = (char) (((int) c - (int) key[key_index]) % 26 + 65);
        } else {
            *output_ptr = c;
        }
        output_ptr--;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] [key] [input]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *key = argv[2];
    char *input = argv[3];

    if (strlen(key) > MAX_KEY_LENGTH) {
        printf("Error: Key is too long\n");
        return 1;
    }

    if (strlen(input) > MAX_INPUT_LENGTH) {
        printf("Error: Input is too long\n");
        return 1;
    }

    char *output = malloc(strlen(input) + 1);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(key, input, output);
        printf("Encrypted message: %s\n", output);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(key, input, output);
        printf("Decrypted message: %s\n", output);
    } else {
        printf("Error: Invalid mode\n");
        return 1;
    }

    free(output);
    return 0;
}