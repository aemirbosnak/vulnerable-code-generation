//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define TAB_SIZE 4
#define MAX_LINE 1024

void beautify(char *filename);
bool is_bracket(char c);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautify(argv[1]);

    return 0;
}

void beautify(char *filename) {
    FILE *fp_in, *fp_out;
    char line[MAX_LINE];
    int indent_level = 0;
    bool inside_tag = false;
    bool inside_single_quote = false;
    bool inside_double_quote = false;

    fp_in = fopen(filename, "r");
    if (fp_in == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fp_out = fopen("beautified.html", "w");
    if (fp_out == NULL) {
        printf("Error creating output file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE, fp_in) != NULL) {
        int i = 0;
        while (line[i] != '\0') {
            char c = line[i];

            if (!inside_single_quote && !inside_double_quote) {
                if (c == '<') {
                    inside_tag = true;
                    fputs("<", fp_out);
                    if (line[i+1] != '/') {
                        indent_level += TAB_SIZE;
                        fputc('\n', fp_out);
                        for (int j = 0; j < indent_level; j++) {
                            fputc(' ', fp_out);
                        }
                    }
                } else if (c == '>') {
                    inside_tag = false;
                    fputc('>', fp_out);
                    if (line[i-1] != '/') {
                        fputc('\n', fp_out);
                        indent_level -= TAB_SIZE;
                        for (int j = 0; j < indent_level; j++) {
                            fputc(' ', fp_out);
                        }
                    }
                }
            }

            if (!inside_tag) {
                fputc(c, fp_out);
            }

            if (!inside_single_quote && !inside_tag && c == '\'') {
                inside_single_quote = true;
                fputc(c, fp_out);
            } else if (inside_single_quote && c == '\'') {
                inside_single_quote = false;
                fputc(c, fp_out);
            } else if (inside_single_quote) {
                fputc(c, fp_out);
            }

            if (!inside_double_quote && !inside_tag && c == '"') {
                inside_double_quote = true;
                fputc(c, fp_out);
            } else if (inside_double_quote && c == '"') {
                inside_double_quote = false;
                fputc(c, fp_out);
            } else if (inside_double_quote) {
                fputc(c, fp_out);
            }

            if (is_bracket(c) && !inside_tag) {
                fputc('\n', fp_out);
                if (c == '}') {
                    indent_level -= TAB_SIZE;
                }
                for (int j = 0; j < indent_level; j++) {
                    fputc(' ', fp_out);
                }
                fputc(c, fp_out);
                if (c == '{') {
                    indent_level += TAB_SIZE;
                }
                fputc('\n', fp_out);
                for (int j = 0; j < indent_level; j++) {
                    fputc(' ', fp_out);
                }
            }

            i++;
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

bool is_bracket(char c) {
    return (c == '{' || c == '}' || c == '(' || c == ')');
}