//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void read_sentences(Sentence sentences[], int num_sentences) {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    int num_sentences_read = 0;
    while (num_sentences_read < num_sentences && fgets(sentences[num_sentences_read].text, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        sentences[num_sentences_read].length = strlen(sentences[num_sentences_read].text);
        num_sentences_read++;
    }

    fclose(input_file);
}

void summarize_sentences(Sentence sentences[], int num_sentences, int max_summary_length, char summary[]) {
    int num_sentences_in_summary = 0;
    int summary_length = 0;

    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].length >= MIN_SENTENCE_LENGTH) {
            strncat(summary, sentences[i].text, MAX_SENTENCE_LENGTH);
            summary_length += sentences[i].length;
            num_sentences_in_summary++;

            if (summary_length >= max_summary_length) {
                break;
            }
        }
    }

    summary[summary_length] = '\0';
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    printf("Enter the number of sentences to read (up to %d): ", MAX_SENTENCES - 1);
    scanf("%d", &num_sentences);

    read_sentences(sentences, num_sentences);

    int max_summary_length;
    printf("Enter the maximum length of the summary (up to %d): ", MAX_SENTENCE_LENGTH - 1);
    scanf("%d", &max_summary_length);

    char summary[MAX_SENTENCE_LENGTH];
    summarize_sentences(sentences, num_sentences, max_summary_length, summary);

    printf("Summary:\n%s\n", summary);

    return 0;
}