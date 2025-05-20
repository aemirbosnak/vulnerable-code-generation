//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
/*
 * A paranoid C Text Summarizer program
 *
 * Usage:
 *      $ summarize [input_file] [output_file] [max_sentences]
 *
 *      input_file    - The input text file to summarize
 *      output_file   - The output text file containing the summary
 *      max_sentences - The maximum number of sentences to include in the summary
 *
 * Example:
 *      $ summarize input.txt output.txt 10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 10
#define MAX_LINE_LEN 100

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [input_file] [output_file] [max_sentences]\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int max_sentences = atoi(argv[3]);

    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out) {
        perror("Error opening files");
        return 1;
    }

    char line[MAX_LINE_LEN];
    int line_count = 0;
    int sentence_count = 0;
    int i;

    while (fgets(line, MAX_LINE_LEN, in)) {
        line_count++;

        if (line[0] == '.') {
            sentence_count++;
        }

        if (sentence_count > max_sentences) {
            break;
        }
    }

    rewind(in);

    while (fgets(line, MAX_LINE_LEN, in)) {
        if (line[0] == '.') {
            fputs(line, out);
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}