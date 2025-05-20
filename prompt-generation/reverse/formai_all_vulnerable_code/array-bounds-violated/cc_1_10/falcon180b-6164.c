//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_CODE_LENGTH 100
#define MAX_CODE_TABLE_LENGTH 256

// Compression algorithm
void compress(char input[], char output[], int code_table[], int *code_table_length) {
    int i, j, current_code = 0;
    char current_character;
    char previous_character = '\0';

    for (i = 0; i < strlen(input); i++) {
        current_character = input[i];

        if (previous_character!= '\0' && current_character == previous_character) {
            continue;
        }

        previous_character = current_character;

        if (code_table[current_character] == 0) {
            code_table[current_character] = *code_table_length;
            (*code_table_length)++;
        }

        output[*code_table_length - 1] = current_character;
    }
}

// Decompression algorithm
void decompress(char input[], char output[], int code_table[], int code_table_length) {
    int i, j, current_code;
    char current_character;

    for (i = 0; i < strlen(input); i++) {
        current_code = input[i];

        if (current_code == 0) {
            continue;
        }

        current_character = code_table[current_code];

        for (j = 0; j < current_code; j++) {
            output[i - j] = current_character;
        }
    }
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];
    int code_table[MAX_CODE_LENGTH];
    int code_table_length = 0;

    // Initialize code table
    for (int i = 0; i < MAX_CODE_TABLE_LENGTH; i++) {
        code_table[i] = 0;
    }

    // Example input
    strcpy(input, "The quick brown fox jumps over the lazy dog.");

    // Compress input
    compress(input, output, code_table, &code_table_length);

    // Decompress output
    decompress(output, input, code_table, code_table_length);

    // Print output
    printf("Compressed input: %s\n", output);
    printf("Decompressed input: %s\n", input);

    return 0;
}