//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void read_sentences(Sentence* sentences, int num_sentences) {
    printf("Enter %d sentences:\n", num_sentences);
    for (int i = 0; i < num_sentences; i++) {
        fgets(sentences[i].sentence, MAX_SENTENCE_LENGTH, stdin);
        sentences[i].length = strlen(sentences[i].sentence);
    }
}

void print_sentences(Sentence* sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        printf("Sentence %d: %s\n", i+1, sentences[i].sentence);
    }
}

void generate_summary(Sentence* sentences, int num_sentences, int max_summary_length) {
    int total_length = 0;
    int num_sentences_in_summary = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (total_length + sentences[i].length <= max_summary_length) {
            printf("Sentence %d: %s\n", num_sentences_in_summary+1, sentences[i].sentence);
            total_length += sentences[i].length;
            num_sentences_in_summary++;
        } else {
            break;
        }
    }
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;

    printf("Enter the number of sentences to summarize: ");
    scanf("%d", &num_sentences);

    if (num_sentences > MAX_SENTENCES) {
        printf("Error: too many sentences.\n");
        return 1;
    }

    read_sentences(sentences, num_sentences);
    print_sentences(sentences, num_sentences);

    int max_summary_length;
    printf("Enter the maximum length of the summary: ");
    scanf("%d", &max_summary_length);

    generate_summary(sentences, num_sentences, max_summary_length);

    return 0;
}