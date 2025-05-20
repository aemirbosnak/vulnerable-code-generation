//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    while (fscanf(input_file, "%[^\n]", sentences[num_sentences].sentence)!= EOF) {
        sentences[num_sentences].length = strlen(sentences[num_sentences].sentence);
        num_sentences++;
    }

    fclose(input_file);

    if (num_sentences == 0) {
        printf("Error: input file is empty.\n");
        fclose(output_file);
        return 1;
    }

    int total_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        total_length += sentences[i].length;
    }

    int average_length = total_length / num_sentences;
    int max_length = 0;
    int min_length = MAX_SENTENCE_LENGTH;

    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].length > max_length) {
            max_length = sentences[i].length;
        }
        if (sentences[i].length < min_length) {
            min_length = sentences[i].length;
        }
    }

    fprintf(output_file, "Total number of sentences: %d\n", num_sentences);
    fprintf(output_file, "Average sentence length: %d\n", average_length);
    fprintf(output_file, "Minimum sentence length: %d\n", min_length);
    fprintf(output_file, "Maximum sentence length: %d\n", max_length);

    for (int i = 0; i < num_sentences; i++) {
        fprintf(output_file, "Sentence %d: %s\n", i+1, sentences[i].sentence);
    }

    fclose(output_file);
    return 0;
}