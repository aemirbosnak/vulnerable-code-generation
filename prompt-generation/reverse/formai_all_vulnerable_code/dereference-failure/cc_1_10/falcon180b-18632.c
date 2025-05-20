//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 12
#define MAX_CODE_TABLE_SIZE 4096
#define MAX_INPUT_SIZE 4096

typedef struct {
    char code[MAX_CODE_LENGTH];
    int code_length;
    int freq;
} CodeTableEntry;

int compare_freq(const void *a, const void *b) {
    return (*(CodeTableEntry*)b).freq - (*(CodeTableEntry*)a).freq;
}

void build_code_table(char *input, int input_size, CodeTableEntry *code_table) {
    int i;
    for (i = 0; i < 256; i++) {
        code_table[i].freq = 0;
    }

    for (i = 0; i < input_size; i++) {
        code_table[(int)input[i]].freq++;
    }

    qsort(code_table, 256, sizeof(CodeTableEntry), compare_freq);
}

void generate_codes(CodeTableEntry *code_table, int code_table_size, char *codes) {
    int i;
    for (i = 0; i < code_table_size; i++) {
        strcpy(codes + i * MAX_CODE_LENGTH, code_table[i].code);
    }
}

void compress(char *input, int input_size, char *output, int *output_size) {
    int i, j;
    char code[MAX_CODE_LENGTH];
    int code_index;
    int code_table_size = 0;
    CodeTableEntry *code_table;

    build_code_table(input, input_size, code_table);
    code_table_size = 256;

    for (i = 0; i < input_size; i++) {
        code_index = (int)input[i];
        strcpy(code, code_table[code_index].code);
        *output_size += strlen(code);
        strcat(output, code);
    }
}

void decompress(char *input, int input_size, char *output) {
    int i, j;
    char code[MAX_CODE_LENGTH];
    int code_index;
    int code_table_size = 0;
    CodeTableEntry *code_table;

    for (i = 0; i < input_size; i += strlen(input + i)) {
        strcpy(code, input + i);
        code_index = 0;
        while (code_table[code_index].code[0]!= code[0]) {
            code_index++;
        }
        for (j = 0; j < strlen(code); j++) {
            if (j >= code_table[code_index].code_length || code[j]!= code_table[code_index].code[j]) {
                break;
            }
        }
        if (j == strlen(code)) {
            strcat(output, code_table[code_index].code);
        } else {
            strcat(output, code);
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int input_size, output_size;

    printf("Enter input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);

    compress(input, input_size, output, &output_size);

    printf("Compressed string: ");
    printf("%s\n", output);

    decompress(output, output_size, input);

    printf("Decompressed string: ");
    printf("%s\n", input);

    return 0;
}