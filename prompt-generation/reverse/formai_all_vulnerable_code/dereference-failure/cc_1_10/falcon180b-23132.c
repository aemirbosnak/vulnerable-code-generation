//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 12
#define MAX_CODE_VALUE 4095
#define EOF_CODE 256

typedef struct {
    char code;
    int length;
} Code;

Code codes[MAX_CODE_VALUE + 1];
int next_code = 257;

void init_codes() {
    int i;
    for (i = 0; i <= MAX_CODE_VALUE; i++) {
        codes[i].code = 0;
        codes[i].length = 0;
    }
}

void build_codes(char *text, int length) {
    int i;
    Code *code;

    for (i = 0; i < length; i++) {
        code = &codes[text[i]];
        code->code = next_code++;
        code->length = 0;
    }
}

void print_codes(FILE *out) {
    int i;
    for (i = 0; i <= MAX_CODE_VALUE; i++) {
        if (codes[i].code!= 0) {
            fprintf(out, "%c -> %d\n", codes[i].code, codes[i].length);
        }
    }
}

void encode(char *text, int length, FILE *out) {
    int i;
    char code;

    fprintf(out, "%d ", length);

    for (i = 0; i < length; i++) {
        code = text[i];
        if (codes[code].length == 0) {
            fprintf(out, "%c ", code);
        } else {
            fprintf(out, "%d ", codes[code].code);
        }
    }
}

void decode(char *text, int length, FILE *in) {
    int i, code;

    for (i = 0; i < length; i++) {
        if (fscanf(in, "%d", &code) == EOF) {
            fprintf(stderr, "Error: unexpected end of file\n");
            exit(1);
        }
        if (code == EOF_CODE) {
            fprintf(stdout, "%c", codes[code].code);
        } else if (code < 256) {
            fprintf(stdout, "%c", code);
        } else {
            fprintf(stdout, "%c", codes[code].code);
        }
    }
}

int main() {
    char input_file[100], output_file[100];
    FILE *in, *out;
    int length;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    in = fopen(input_file, "r");
    if (in == NULL) {
        fprintf(stderr, "Error: cannot open input file\n");
        exit(1);
    }

    out = fopen(output_file, "w");
    if (out == NULL) {
        fprintf(stderr, "Error: cannot open output file\n");
        exit(1);
    }

    fseek(in, 0, SEEK_END);
    length = ftell(in);
    rewind(in);

    init_codes();
    build_codes((char *)malloc(length + 1), length);

    encode((char *)malloc(length + 1), length, out);

    free(codes[EOF_CODE].code);
    free(codes);

    fclose(in);
    fclose(out);

    return 0;
}