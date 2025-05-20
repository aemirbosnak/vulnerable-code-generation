//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096

struct Code {
    char code[MAX_CODE_SIZE];
    int code_size;
};

struct Code create_code(char *str) {
    struct Code code;
    code.code_size = 0;
    code.code[0] = '\0';

    char *p = str;
    while (*p) {
        char c = *p++;
        if (c == '\n') {
            code.code[code.code_size++] = '\\';
            code.code[code.code_size++] = 'n';
        } else {
            code.code[code.code_size++] = c;
        }
    }
    code.code[code.code_size] = '\0';

    return code;
}

void print_code(struct Code code) {
    printf("Code: %s\n", code.code);
}

void compress(char *input_file, char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    struct Code code;
    char line[MAX_CODE_SIZE];

    while (fgets(line, MAX_CODE_SIZE, in)) {
        code = create_code(line);
        fprintf(out, "%s", code.code);
    }

    fclose(in);
    fclose(out);
}

int main() {
    char input_file[MAX_CODE_SIZE];
    char output_file[MAX_CODE_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    compress(input_file, output_file);

    printf("Compression completed!\n");

    return 0;
}