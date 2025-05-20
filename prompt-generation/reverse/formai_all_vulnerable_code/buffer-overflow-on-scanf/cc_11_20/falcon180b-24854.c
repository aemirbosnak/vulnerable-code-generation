//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        int sentence_length = strlen(sentence);
        if (sentence_length > 0 && sentence[sentence_length - 1] == '\n') {
            sentence[sentence_length - 1] = '\0';
            sentence_length--;
        }
        if (num_sentences >= MAX_SENTENCES) {
            printf("Reached maximum number of sentences.\n");
            break;
        }
        strcpy(sentences[num_sentences].text, sentence);
        sentences[num_sentences].length = sentence_length;
        num_sentences++;
    }

    fclose(input_file);
    fclose(output_file);

    int total_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        total_words += sentences[i].length;
    }

    int avg_sentence_length = total_words / num_sentences;
    int max_sentence_length = 0;
    int min_sentence_length = MAX_SENTENCE_LENGTH;

    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].length > max_sentence_length) {
            max_sentence_length = sentences[i].length;
        }
        if (sentences[i].length < min_sentence_length) {
            min_sentence_length = sentences[i].length;
        }
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fprintf(output_file, "Total words: %d\n", total_words);
    fprintf(output_file, "Average sentence length: %d\n", avg_sentence_length);
    fprintf(output_file, "Maximum sentence length: %d\n", max_sentence_length);
    fprintf(output_file, "Minimum sentence length: %d\n", min_sentence_length);

    for (int i = 0; i < num_sentences; i++) {
        fprintf(output_file, "Sentence %d: %s\n", i + 1, sentences[i].text);
    }

    fclose(output_file);

    return 0;
}