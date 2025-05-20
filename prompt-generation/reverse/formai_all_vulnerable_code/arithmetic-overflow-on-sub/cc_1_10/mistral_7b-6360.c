//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 26
#define ALPHABET_SIZE 26
#define FILE_MODE "r+b"

// Function to shift characters in alphabet by a given offset
char shift_char(char c, int offset) {
    char shifted_char;
    if (isalpha(c)) {
        shifted_char = ((int)c + offset - (int)'a') % ALPHABET_SIZE + 'a';
    } else {
        shifted_char = c;
    }
    return shifted_char;
}

// Function to generate a random key using current time
void generate_key(char *key) {
    time_t t;
    struct tm *tm;
    int i;

    time(&t);
    tm = localtime(&t);

    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = shift_char('a' + (i % 5), tm->tm_sec + tm->tm_min * 60 + tm->tm_hour * 3600);
    }

    key[KEY_LENGTH] = '\0';
}

// Function to encrypt a single character
char encrypt_char(char c, char *key) {
    char encrypted_char;

    encrypted_char = shift_char(c, key[(int)c % ALPHABET_SIZE]);

    return encrypted_char;
}

// Function to encrypt a whole file
void encrypt_file(FILE *input, FILE *output, char *key) {
    char c;

    while ((c = fgetc(input)) != EOF) {
        fputc(encrypt_char(c, key), output);
    }
}

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char *key;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], FILE_MODE);
    output_file = fopen(argv[2], "wb");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    key = malloc(sizeof(char) * (KEY_LENGTH + 1));

    generate_key(key);

    encrypt_file(input_file, output_file, key);

    printf("Key: %s\n", key);

    free(key);
    fclose(input_file);
    fclose(output_file);

    return 0;
}