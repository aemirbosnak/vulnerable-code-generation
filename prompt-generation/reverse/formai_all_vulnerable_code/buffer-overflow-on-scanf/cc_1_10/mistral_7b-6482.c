//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MAX_CHAR 128

typedef struct {
    int count;
    char chr;
} char_count;

void compress(char *input, char *output) {
    char_count char_table[MAX_CHAR];
    int table_index = 0;
    int output_index = 0;

    memset(char_table, 0, sizeof(char_table));

    for (int i = 0; i < strlen(input); i++) {
        char c = tolower(input[i]);
        if (isalpha(c)) {
            for (int j = 0; j < table_index; j++) {
                if (char_table[j].chr == c) {
                    output[output_index++] = j + 'A';
                    break;
                }
            }

            if (table_index < MAX_CHAR) {
                char_table[table_index].chr = c;
                char_table[table_index++].count++;
            } else {
                // Drop the least frequently used character
                char least_used = char_table[0].chr;
                for (int j = 0; j < table_index - 1; j++) {
                    if (char_table[j].count < char_table[j + 1].count) {
                        least_used = char_table[j].chr;
                    }
                }

                for (int j = 0; j < table_index; j++) {
                    if (char_table[j].chr == least_used) {
                        memmove(&char_table[j], &char_table[j + 1], (table_index - j) * sizeof(char_count));
                        break;
                    }
                }

                char_table[--table_index] = (char_count){c, 1};
            }

            output[output_index++] = c;
        } else {
            output[output_index++] = input[i];
        }
    }

    for (int i = 0; i < table_index; i++) {
        output[output_index++] = i + 'A';
    }

    output[output_index] = '\0';
}

void decompress(char *input, char *output) {
    int table_index = 0;
    int input_index = 0;
    int output_index = 0;

    char_count char_table[MAX_CHAR];

    while (input[input_index] != '\0') {
        if (isalpha(input[input_index])) {
            if (table_index == 0) {
                char_table[table_index++] = (char_count){input[input_index], 1};
            } else {
                for (int i = 0; i < table_index - 1; i++) {
                    if (char_table[i].chr == input[input_index]) {
                        output[output_index++] = char_table[i].chr;
                        for (int j = i; j < table_index - 1; j++) {
                            char_table[j] = char_table[j + 1];
                        }
                        break;
                    }
                }
            }

            input_index++;
        } else {
            output[output_index++] = input[input_index++];
        }
    }

    output[output_index] = '\0';
}

int main() {
    char input[BUF_SIZE];
    char output[2 * BUF_SIZE];

    printf("Enter a string to compress: ");
    scanf("%s", input);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    char decompressed[BUF_SIZE];
    decompress(output, decompressed);

    printf("Decompressed string: %s\n", decompressed);

    return 0;
}