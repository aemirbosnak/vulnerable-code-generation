//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define TAB_WIDTH 4  // set default tab width to 4

void indent_code(char *input_file, char *output_file) {
    FILE *input, *output;
    int indent_level = 0;
    char ch, prev_ch = '\0';

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Could not open file '%s'\n", input_file);
        exit(1);
    }
    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Could not create file '%s'\n", output_file);
        exit(1);
    }

    while ((ch = fgetc(input)) != EOF) {
        if (ch == '\n') {
            fputc(ch, output);
            indent_level = 0;
            continue;
        }
        if (prev_ch == '<' && ch != '/') {
            indent_level++;
            fputc('\n', output);
            for (int i = 0; i < TAB_WIDTH * indent_level; i++) {
                fputc(' ', output);
            }
        }
        if (ch == '>') {
            fputc(ch, output);
            if (prev_ch == '/' || prev_ch == '>') {
                indent_level--;
            }
        } else {
            fputc(ch, output);
        }
        prev_ch = ch;
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[50], output_file[50];
    printf("Enter input file name (include path if necessary): ");
    scanf("%s", input_file);
    printf("Enter output file name (include path if necessary): ");
    scanf("%s", output_file);
    indent_code(input_file, output_file);
    printf("Code successfully indented!\n");
    return 0;
}