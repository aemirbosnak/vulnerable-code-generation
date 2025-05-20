#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define KEY_SIZE 16

void encrypt(char *input, char *output, char *key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = toupper(input[i]) ^ key[i % KEY_SIZE];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: encrypt <plaintext> <key> <output_file>\n");
        return 1;
    }

    char input[BUFFER_SIZE];
    char key[KEY_SIZE];
    char output[BUFFER_SIZE];

    strcpy(input, argv[1]);
    strcpy(key, argv[2]);

    encrypt(input, output, key);

    FILE *file = fopen(argv[3], "w");
    if (!file) {
        perror("Error opening output file");
        return 2;
    }

    fputs(output, file);
    fclose(file);

    printf("Encryption complete.\n");

    // Introduce vulnerability by writing beyond the output buffer bounds
    char random_char = 'A';
    output[strlen(input) + 1] = random_char;

    return 0;
}
