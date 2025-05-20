//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCES 1000
#define NUM_SENTIMENTS 3

struct Sentence {
    char *text;
    int length;
    int sentiment;
};

struct Word {
    char *text;
    int length;
    int sentiment;
};

int analyzeSentiment(char *sentence) {
    int sentiment = 0;
    int i = 0;
    while (sentence[i]!= '\0') {
        if (isalpha(sentence[i])) {
            int wordLength = 0;
            while (isalpha(sentence[i + wordLength]) && wordLength < MAX_WORD_LENGTH) {
                wordLength++;
            }
            char *word = malloc(wordLength + 1);
            strncpy(word, &sentence[i], wordLength);
            word[wordLength] = '\0';
            sentiment += analyzeWordSentiment(word);
            free(word);
        }
        i++;
    }
    return sentiment;
}

int analyzeWordSentiment(char *word) {
    int sentiment = 0;
    if (strcmp(word, "happy") == 0) {
        sentiment = 1;
    } else if (strcmp(word, "sad") == 0) {
        sentiment = -1;
    }
    return sentiment;
}

void printSentences(struct Sentence sentences[], int numSentences) {
    for (int i = 0; i < numSentences; i++) {
        printf("%s (%d)\n", sentences[i].text, sentences[i].sentiment);
    }
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    int numSentences = 0;
    struct Sentence sentences[MAX_SENTENCES];

    printf("Enter sentences (type 'done' when finished):\n");
    while (numSentences < MAX_SENTENCES && fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }
        int sentenceLength = strlen(input);
        if (sentenceLength > MAX_SENTENCE_LENGTH) {
            printf("Sentence too long.\n");
            continue;
        }
        struct Sentence sentence = {
           .text = strdup(input),
           .length = sentenceLength,
           .sentiment = analyzeSentiment(input)
        };
        sentences[numSentences++] = sentence;
    }

    printf("Sentences:\n");
    printSentences(sentences, numSentences);

    return 0;
}