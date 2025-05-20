//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char buffer[MAX_LEN];
int curr_pos = 0;

void format(char *input_file, char *output_file);
void indent(int num_indents, FILE *fp);

int main() {
    char input_file[MAX_LEN];
    char output_file[MAX_LEN];

    printf("Enter input file name: ");
    fgets(input_file, MAX_LEN, stdin);
    input_file[strlen(input_file) - 1] = '\0';

    printf("Enter output file name: ");
    fgets(output_file, MAX_LEN, stdin);
    output_file[strlen(output_file) - 1] = '\0';

    format(input_file, output_file);

    printf("Successfully formatted HTML file!\n");

    return 0;
}

void format(char *input_file, char *output_file) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    if (input_fp == NULL) {
        printf("Error opening input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    if (output_fp == NULL) {
        printf("Error creating output file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    int in_tag = 0;
    int in_comment = 0;
    char curr_char;

    while ((curr_char = fgetc(input_fp)) != EOF) {
        if (in_comment) {
            if (curr_char == '-') {
                if (fgetc(input_fp) == '-') {
                    if (fgetc(input_fp) == '>') {
                        in_comment = 0;
                    } else {
                        fseek(input_fp, -1, SEEK_CUR);
                    }
                } else {
                    fseek(input_fp, -1, SEEK_CUR);
                }
            }
        } else if (in_tag) {
            fputc(curr_char, output_fp);
            if (curr_char == '>') {
                in_tag = 0;
            }
        } else {
            if (curr_char == '<' && fgetc(input_fp) != '!') {
                in_tag = 1;
                curr_pos = 0;
                fputc('\n', output_fp);
                indent(curr_pos, output_fp);
                fseek(input_fp, -1, SEEK_CUR);
            } else if (curr_char == '<' && fgetc(input_fp) == '!') {
                if (fgetc(input_fp) == '-' && fgetc(input_fp) == '-') {
                    in_comment = 1;
                }
            } else if (curr_char == '>') {
                fputc(curr_char, output_fp);
                fputc('\n', output_fp);
                curr_pos = 0;
                in_tag = 0;
            } else {
                fputc(curr_char, output_fp);
                if (curr_char == '\n') {
                    curr_pos = 0;
                } else {
                    curr_pos++;
                }
            }
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}

void indent(int num_indents, FILE *fp) {
    for (int i = 0; i < num_indents; i++) {
        fputs("    ", fp);
    }
}