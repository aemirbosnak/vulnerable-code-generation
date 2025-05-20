//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 255
#define MAX_INPUT_LENGTH 1024

typedef struct {
    unsigned char code;
    unsigned char length;
} Code;

Code codes[MAX_CODE_LENGTH];
unsigned char input[MAX_INPUT_LENGTH];
unsigned int input_length;
unsigned int code_index;

void compress(unsigned char *input, unsigned int input_length) {
    unsigned int i, j, k;
    unsigned char current_code, previous_code;
    unsigned char code_length;

    current_code = input[0];
    previous_code = 255;
    code_length = 1;

    for (i = 1; i < input_length; i++) {
        if (input[i] == current_code && code_length < MAX_CODE_LENGTH) {
            code_length++;
        } else {
            codes[code_index].code = current_code;
            codes[code_index].length = code_length;
            code_index++;

            current_code = input[i];
            code_length = 1;
        }
    }

    codes[code_index].code = current_code;
    codes[code_index].length = code_length;
    code_index++;
}

void decompress(Code *codes, unsigned int code_index) {
    unsigned int i, j, k;
    unsigned char current_code, previous_code;
    unsigned char code_length;

    current_code = codes[0].code;
    previous_code = 255;
    code_length = codes[0].length;

    for (i = 1; i < code_index; i++) {
        if (codes[i].code == previous_code && codes[i].length == code_length + 1) {
            code_length++;
        } else {
            for (j = 0; j < code_length; j++) {
                printf("%c", current_code);
            }

            current_code = codes[i].code;
            previous_code = current_code;
            code_length = codes[i].length;
        }
    }

    for (j = 0; j < code_length; j++) {
        printf("%c", current_code);
    }
}

int main() {
    unsigned int i;

    printf("Enter the input string: ");
    scanf("%s", input);

    input_length = strlen(input);

    compress(input, input_length);

    printf("Compressed string: ");
    for (i = 0; i < code_index; i++) {
        printf("%c%d", codes[i].code, codes[i].length);
    }

    printf("\nDecompressed string: ");
    decompress(codes, code_index);

    printf("\n");

    return 0;
}