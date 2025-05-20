//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE 4096
#define MAX_CODE_LEN 12
#define EOF_CODE 256

typedef struct {
    char *code;
    int len;
} code_t;

typedef struct {
    FILE *in;
    FILE *out;
    char *buffer;
    int buf_size;
    int buf_pos;
    int code_size;
    code_t *code_table;
} coder_t;

void init_coder(coder_t *coder) {
    coder->in = stdin;
    coder->out = stdout;
    coder->buffer = malloc(4096);
    coder->buf_size = 4096;
    coder->buf_pos = 0;
    coder->code_size = 0;
    coder->code_table = malloc(MAX_CODE * sizeof(code_t));
}

void free_coder(coder_t *coder) {
    free(coder->buffer);
    free(coder->code_table);
}

void encode(coder_t *coder, int code) {
    if (coder->code_size >= MAX_CODE) {
        fprintf(stderr, "Code table is full!\n");
        exit(1);
    }
    coder->code_table[coder->code_size].code = malloc(MAX_CODE_LEN);
    coder->code_table[coder->code_size].len = strlen(coder->buffer + coder->buf_pos - code);
    strncpy(coder->code_table[coder->code_size].code, coder->buffer + coder->buf_pos - code, MAX_CODE_LEN - 1);
    coder->code_table[coder->code_size++].code[coder->code_table[coder->code_size - 1].len] = '\0';
}

void decode(coder_t *coder, int code) {
    for (int i = 0; i < coder->code_size; i++) {
        if (code == coder->code_table[i].code[0]) {
            fprintf(coder->out, "%s", coder->code_table[i].code);
            return;
        }
    }
    fprintf(coder->out, "%c", code);
}

int main() {
    coder_t coder;
    init_coder(&coder);
    int c;
    while ((c = fgetc(coder.in))!= EOF) {
        if (isalpha(c)) {
            encode(&coder, c);
        } else {
            decode(&coder, c);
        }
    }
    free_coder(&coder);
    return 0;
}