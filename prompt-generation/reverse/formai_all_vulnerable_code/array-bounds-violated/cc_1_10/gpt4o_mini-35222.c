//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 10

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;
    int inTag = 0;

    while (fgets(line, sizeof(line), input)) {
        int i = 0;

        // Process each character in the line
        while (line[i] != '\0') {
            if (line[i] == '<') {
                // Start of a tag
                if (line[i + 1] != '/') {
                    // Opening tag
                    fprintf(output, "%*s<%s", indentLevel * 4, "", line + i + 1);
                    indentLevel++;
                } else {
                    // Closing tag
                    indentLevel--;
                    fprintf(output, "%*s<%s", indentLevel * 4, "", line + i + 2);
                }
                inTag = 1; // We're inside a tag
                while (line[i] != '>' && line[i] != '\0') {
                    fputc(line[i], output);
                    i++;
                }
                fputc('>', output);
                if (line[i] == '>') {
                    if (line[i - 1] == '/') {
                        // Self-closing tag
                        indentLevel--; // Decrease indent for self-closed tags too
                    }
                }
            } else {
                if (inTag && line[i] == ' ') {
                    // Continue the whitespace
                    fputc(line[i], output);
                } else {
                    // Normal text outside tags
                    if (!inTag && line[i - 1] == '>') {
                        fprintf(output, "\n%*s", indentLevel * 4, "");
                    }
                    fputc(line[i], output);
                }
            }
            i++;
        }
        inTag = 0; // Reset flag for next line
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    beautify_html(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("HTML beautification completed! Check the output in %s\n", argv[2]);
    return EXIT_SUCCESS;
}