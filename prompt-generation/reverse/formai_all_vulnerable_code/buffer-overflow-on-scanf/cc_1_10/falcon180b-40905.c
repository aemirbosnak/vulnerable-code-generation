//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void read_sentences(Sentence sentences[], int num_sentences) {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    int num_sentences_read = 0;
    while (num_sentences_read < num_sentences && fgets(sentences[num_sentences_read].sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        sentences[num_sentences_read].length = strlen(sentences[num_sentences_read].sentence);
        if (sentences[num_sentences_read].length < MIN_SENTENCE_LENGTH) {
            printf("Warning: Skipping short sentence (%d characters): %s\n", sentences[num_sentences_read].length, sentences[num_sentences_read].sentence);
            num_sentences_read--;
        } else {
            num_sentences_read++;
        }
    }

    fclose(input_file);
}

void tokenize_sentences(Sentence sentences[], int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        char *token = strtok(sentences[i].sentence, " ");
        while (token!= NULL) {
            printf("%s ", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
}

void summarize_sentences(Sentence sentences[], int num_sentences, int max_summary_length) {
    int num_summarized_sentences = 0;
    for (int i = 0; i < num_sentences && num_summarized_sentences < max_summary_length; i++) {
        if (sentences[i].length >= MIN_SENTENCE_LENGTH) {
            printf("%s ", sentences[i].sentence);
            num_summarized_sentences++;
        }
    }
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;

    printf("Enter the number of sentences to read (up to %d): ", MAX_SENTENCES);
    scanf("%d", &num_sentences);

    read_sentences(sentences, num_sentences);

    printf("Enter the maximum length of the summary (up to %d): ", num_sentences);
    scanf("%d", &num_sentences);

    summarize_sentences(sentences, num_sentences, num_sentences);

    return 0;
}