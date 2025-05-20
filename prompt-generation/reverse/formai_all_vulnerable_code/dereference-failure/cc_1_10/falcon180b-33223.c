//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096

typedef struct {
    unsigned int freq;
    char code;
} Code;

typedef struct {
    FILE *in;
    FILE *out;
    unsigned int code_size;
    Code codes[MAX_CODE_SIZE];
} State;

void init_codes(State *state) {
    int i;
    for (i = 0; i < MAX_CODE_SIZE; i++) {
        state->codes[i].freq = 0;
        state->codes[i].code = '\0';
    }
}

void build_codes(State *state) {
    int i, j;
    unsigned int code_size = 0;
    for (i = 0; i < MAX_CODE_SIZE; i++) {
        if (state->codes[i].freq > 0) {
            state->codes[code_size++] = state->codes[i];
        }
    }
    for (i = 0; i < code_size; i++) {
        state->codes[i].code = (char) (i + 'A');
    }
    state->code_size = code_size;
}

void write_code(State *state, FILE *out, Code code) {
    fprintf(out, "%c", code.code);
}

void read_byte(State *state, FILE *in) {
    unsigned char c;
    fread(&c, 1, 1, in);
    state->codes[c].freq++;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    State state;
    state.in = fopen(argv[1], "rb");
    if (state.in == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    state.out = fopen(argv[2], "wb");
    if (state.out == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    init_codes(&state);

    while (fgetc(state.in)!= EOF) {
        read_byte(&state, state.in);
    }

    build_codes(&state);

    while (fgetc(state.in)!= EOF) {
        Code code = state.codes[fgetc(state.in)];
        write_code(&state, state.out, code);
    }

    fclose(state.in);
    fclose(state.out);

    return 0;
}