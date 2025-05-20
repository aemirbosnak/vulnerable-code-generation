//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void read_sentences(Sentence sentences[], int num_sentences) {
    char buffer[MAX_SENTENCE_LENGTH];
    int sentence_index = 0;

    printf("Enter %d sentences:\n", num_sentences);
    for (int i = 0; i < num_sentences; i++) {
        fgets(buffer, MAX_SENTENCE_LENGTH, stdin);
        int length = strlen(buffer) - 1; // remove newline character

        if (length < MIN_SENTENCE_LENGTH) {
            printf("Sentence %d is too short. Please enter a longer sentence.\n", i + 1);
            i--;
            continue;
        }

        strcpy(sentences[i].text, buffer);
        sentences[i].length = length;
    }
}

void count_words(Sentence sentences[], int num_sentences, int word_counts[]) {
    for (int i = 0; i < num_sentences; i++) {
        char *token = strtok(sentences[i].text, ",.?!;:");
        while (token!= NULL) {
            word_counts[i]++;
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_summary(Sentence sentences[], int num_sentences, int word_counts[]) {
    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        if (word_counts[i] == 0) {
            printf("Sentence %d has no words.\n", i + 1);
        } else {
            printf("Sentence %d: %d words\n", i + 1, word_counts[i]);
        }
    }
}

int main() {
    int num_sentences;
    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);

    Sentence sentences[MAX_SENTENCES];
    read_sentences(sentences, num_sentences);

    int word_counts[MAX_SENTENCES];
    count_words(sentences, num_sentences, word_counts);

    print_summary(sentences, num_sentences, word_counts);

    return 0;
}