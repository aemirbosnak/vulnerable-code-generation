//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    char *filename = "input.txt";
    char ch;
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read in each sentence and store in array
    while ((ch = fgetc(input_file))!= EOF) {
        if (ch == '.' || ch == '?' || ch == '!') {
            ungetc(ch, input_file);
            break;
        }
        if (num_sentences >= MAX_SENTENCES) {
            printf("Error: Too many sentences.\n");
            exit(1);
        }
        sentences[num_sentences].length = 0;
        while ((ch = fgetc(input_file))!= EOF && ch!= '.' && ch!= '?' && ch!= '!') {
            if (isalpha(ch)) {
                if (sentences[num_sentences].length >= MAX_SENTENCE_LENGTH) {
                    printf("Error: Sentence too long.\n");
                    exit(1);
                }
                sentences[num_sentences].sentence[sentences[num_sentences].length++] = tolower(ch);
            } else if (isspace(ch)) {
                if (sentences[num_sentences].length < MIN_SENTENCE_LENGTH) {
                    printf("Error: Sentence too short.\n");
                    exit(1);
                }
            }
        }
        if (sentences[num_sentences].length == 0) {
            printf("Error: Empty sentence.\n");
            exit(1);
        }
        num_sentences++;
    }

    // Summarize sentences
    for (int i = 0; i < num_sentences; i++) {
        if (i % 2 == 0) {
            fprintf(output_file, "%s ", sentences[i].sentence);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}