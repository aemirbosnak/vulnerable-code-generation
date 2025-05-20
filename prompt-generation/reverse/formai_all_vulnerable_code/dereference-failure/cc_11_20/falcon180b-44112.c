//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char* word;
    int count;
} WordCount;

int main(int argc, char** argv) {
    FILE* input_file = stdin;
    FILE* output_file = stdout;

    if (argc > 1) {
        input_file = fopen(argv[1], "r");
        if (input_file == NULL) {
            fprintf(stderr, "Error: Could not open input file.\n");
            return 1;
        }
    }

    if (argc > 2) {
        output_file = fopen(argv[2], "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Could not open output file.\n");
            return 1;
        }
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char* token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            WordCount* word_count = NULL;
            for (int i = 0; i < argc - 2; i++) {
                if (strcmp(token, argv[i + 2]) == 0) {
                    word_count = &argv[i + 1];
                    break;
                }
            }

            if (word_count == NULL) {
                fprintf(stderr, "Error: Unknown word '%s'.\n", token);
                return 1;
            }

            word_count->count++;
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    if (output_file!= stdout) {
        fclose(output_file);
    }

    return 0;
}