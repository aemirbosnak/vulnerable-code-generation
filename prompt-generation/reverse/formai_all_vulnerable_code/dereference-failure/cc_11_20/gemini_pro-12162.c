//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int indent;
    bool new_line;
    bool space_before;
} state_t;

void html_beautify(char *input, char *output) {
    state_t state = {0, true, true};
    char *in = input, *out = output;
    while (*in) {
        switch (*in) {
            case '<':
                if (state.new_line) {
                    for (int i = 0; i < state.indent; i++) {
                        *out++ = ' ';
                    }
                }
                *out++ = *in++;
                state.new_line = false;
                state.space_before = false;
                break;
            case '>':
                *out++ = *in++;
                state.new_line = true;
                state.space_before = false;
                break;
            case '/':
                if (*in == '/' || *in == '-') {
                    if (state.new_line) {
                        for (int i = 0; i < state.indent; i++) {
                            *out++ = ' ';
                        }
                    }
                    *out++ = *in++;
                    state.new_line = false;
                    state.space_before = false;
                    while (*in && *in != '\n') {
                        *out++ = *in++;
                    }
                    state.new_line = true;
                    state.space_before = false;
                } else {
                    *out++ = *in++;
                    state.space_before = false;
                }
                break;
            case ' ':
            case '\t':
                if (state.space_before) {
                    *out++ = *in++;
                } else {
                    state.space_before = true;
                    in++;
                }
                break;
            case '\n':
                state.new_line = true;
                state.space_before = false;
                in++;
                break;
            default:
                if (state.new_line) {
                    for (int i = 0; i < state.indent; i++) {
                        *out++ = ' ';
                    }
                }
                *out++ = *in++;
                state.new_line = false;
                state.space_before = false;
                break;
        }
    }
    *out = 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("fopen");
        return 1;
    }
    FILE *out = fopen(argv[2], "w");
    if (!out) {
        perror("fopen");
        return 1;
    }
    char *input = malloc(1024);
    char *output = malloc(1024);
    while (fgets(input, 1024, in)) {
        html_beautify(input, output);
        fputs(output, out);
    }
    free(input);
    free(output);
    fclose(in);
    fclose(out);
    return 0;
}