//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: safe
/*
 * Unique C Encryption Example Program
 *
 * This program demonstrates a simple encryption algorithm
 * using a Caesar Cipher.
 *
 * Usage: ./caesar_cipher [key] [input_file] [output_file]
 *
 * Examples:
 * ./caesar_cipher 3 example.txt encrypted.txt
 * ./caesar_cipher 10 example.txt encrypted.txt
 *
 * Note: The key is a positive integer that represents
 * the number of characters to shift each letter by.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Encrypt a string using a Caesar Cipher
 *
 * @param input The input string to encrypt
 * @param key The encryption key
 * @return The encrypted string
 */
char *caesar_cipher(char *input, int key) {
    int length = strlen(input);
    char *output = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        output[i] = input[i] + key;
    }
    output[length] = '\0';
    return output;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s [key] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    FILE *input_file = fopen(argv[2], "r");
    FILE *output_file = fopen(argv[3], "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, input_file)) != -1) {
        char *encrypted = caesar_cipher(line, key);
        fprintf(output_file, "%s", encrypted);
        free(encrypted);
    }

    fclose(input_file);
    fclose(output_file);
    free(line);
    return 0;
}