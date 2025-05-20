//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input string
#define MAX_CODE_LENGTH 4096 // Maximum length of code
#define CODE_LENGTH 8 // Length of code for each character

typedef struct {
    char character;
    char code[CODE_LENGTH];
} code_table_t;

void generate_codes(char* input, code_table_t* table) {
    int i, j, count = 0;
    for (i = 0; i < strlen(input); i++) {
        if (count == MAX_LENGTH) {
            printf("Error: Input string is too long.\n");
            exit(1);
        }
        table[i].character = input[i];
        for (j = 0; j < CODE_LENGTH; j++) {
            table[i].code[j] = 'A' + count;
            count++;
        }
    }
}

void compress(char* input, code_table_t* table, char* output) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < CODE_LENGTH; j++) {
            strcat(output, table[input[i]].code[j]);
        }
    }
}

void decompress(char* input, code_table_t* table, char* output) {
    int i, j, count = 0;
    char code[CODE_LENGTH];
    for (i = 0; i < strlen(input); i += CODE_LENGTH) {
        memset(code, 0, CODE_LENGTH);
        for (j = 0; j < CODE_LENGTH; j++) {
            code[j] = input[i + j];
        }
        for (j = 0; j < strlen(table[count].code); j++) {
            if (strcmp(code, table[count].code) == 0) {
                strcat(output, table[count].character);
                count++;
                break;
            }
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    code_table_t table[256];
    char output[MAX_LENGTH];

    printf("Enter input string: ");
    scanf("%s", input);

    generate_codes(input, table);

    printf("Compressed string: ");
    compress(input, table, output);
    printf("%s\n", output);

    printf("Decompressed string: ");
    decompress(output, table, input);
    printf("%s\n", input);

    return 0;
}