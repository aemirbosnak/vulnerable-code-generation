//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentence;
    int length;
    int *word_counts;
} Sentence;

void read_sentences(Sentence sentences[], int num_sentences) {
    char input[MAX_SENTENCES][MAX_SENTENCES];
    int i = 0;
    while (i < num_sentences && fgets(input[i], MAX_SENTENCES, stdin)!= NULL) {
        input[i][strcspn(input[i], "\n")] = '\0';
        i++;
    }
    for (i = 0; i < num_sentences; i++) {
        char *sentence = strdup(input[i]);
        char *word = strtok(sentence, " ");
        int length = 0;
        int num_words = 0;
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                break;
            }
            if (strlen(word) >= MAX_WORD_LENGTH) {
                break;
            }
            if (isalpha(word[0])) {
                WordCount *wc = malloc(sizeof(WordCount));
                wc->word = strdup(word);
                wc->count = 1;
                sentences[i].word_counts[length] = wc;
                length++;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
        sentences[i].length = length;
    }
}

void print_sentences(Sentence sentences[], int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        printf("Sentence %d:\n", i + 1);
        for (int j = 0; j < sentences[i].length; j++) {
            WordCount *wc = sentences[i].word_counts[j];
            printf("%s: %d\n", wc->word, wc->count);
        }
    }
}

int main() {
    int num_sentences;
    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);
    Sentence sentences[num_sentences];
    read_sentences(sentences, num_sentences);
    print_sentences(sentences, num_sentences);
    return 0;
}