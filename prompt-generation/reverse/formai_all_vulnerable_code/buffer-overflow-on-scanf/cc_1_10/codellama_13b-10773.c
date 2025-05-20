//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_NUM_SENTENCES 100

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int sentiment;
} Sentence;

void read_sentences(Sentence sentences[], int num_sentences) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        printf("Enter sentence %d: ", i + 1);
        scanf("%s", sentences[i].sentence);
        sentences[i].sentiment = 0;
    }
}

void analyze_sentences(Sentence sentences[], int num_sentences) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        if (strstr(sentences[i].sentence, "good") != NULL) {
            sentences[i].sentiment = 1;
        } else if (strstr(sentences[i].sentence, "bad") != NULL) {
            sentences[i].sentiment = -1;
        }
    }
}

void print_sentiment(Sentence sentences[], int num_sentences) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        printf("Sentence %d: %s\n", i + 1, sentences[i].sentence);
        if (sentences[i].sentiment == 1) {
            printf("Sentiment: Positive\n\n");
        } else if (sentences[i].sentiment == -1) {
            printf("Sentiment: Negative\n\n");
        } else {
            printf("Sentiment: Neutral\n\n");
        }
    }
}

int main() {
    Sentence sentences[MAX_NUM_SENTENCES];
    int num_sentences;

    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);

    read_sentences(sentences, num_sentences);
    analyze_sentences(sentences, num_sentences);
    print_sentiment(sentences, num_sentences);

    return 0;
}