//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_INPUT_SIZE 1024

void encrypt(char *key, char *input, char *output) {
    int key_len = strlen(key);
    int input_len = strlen(input);

    if (key_len > MAX_KEY_SIZE || input_len > MAX_INPUT_SIZE) {
        printf("Error: Input too long\n");
        exit(1);
    }

    char *key_expanded = malloc(input_len + 1);
    char *input_copy = malloc(input_len + 1);

    strcpy(key_expanded, key);
    strcpy(input_copy, input);

    int key_index = 0;
    for (int i = 0; i < input_len; i++) {
        char c = input_copy[i];
        output[i] = (c ^ key_expanded[key_index % key_len]) & 0xff;
        key_index++;
    }

    output[input_len] = '\0';

    free(key_expanded);
    free(input_copy);
}

void decrypt(char *key, char *input, char *output) {
    int key_len = strlen(key);
    int input_len = strlen(input);

    if (key_len > MAX_KEY_SIZE || input_len > MAX_INPUT_SIZE) {
        printf("Error: Input too long\n");
        exit(1);
    }

    char *key_expanded = malloc(input_len + 1);
    char *input_copy = malloc(input_len + 1);

    strcpy(key_expanded, key);
    strcpy(input_copy, input);

    int key_index = 0;
    for (int i = 0; i < input_len; i++) {
        char c = input_copy[i];
        output[i] = (c ^ key_expanded[key_index % key_len]) & 0xff;
        key_index++;
    }

    output[input_len] = '\0';

    free(key_expanded);
    free(input_copy);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <encrypt|decrypt> <key> <input>\n", argv[0]);
        exit(1);
    }

    char *mode = argv[1];
    char *key = argv[2];
    char *input = argv[3];

    char output[MAX_INPUT_SIZE + 1];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(key, input, output);
        printf("Encrypted output: %s\n", output);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(key, input, output);
        printf("Decrypted output: %s\n", output);
    } else {
        printf("Invalid mode\n");
        exit(1);
    }

    return 0;
}