//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void process_sentence(char *sentence, WordCount *word_counts) {
    char *word;
    int i;

    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            word = (char *) malloc(strlen(sentence) - i + 1);
            strncpy(word, &sentence[i], strlen(sentence) - i);
            word[strlen(sentence) - i] = '\0';

            int j;
            for (j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }

            int found = false;
            for (j = 0; j < MAX_TOKENS; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (word_counts->count == MAX_TOKENS) {
                    printf("Error: Maximum number of tokens reached.\n");
                    exit(1);
                }
                strcpy(word_counts[word_counts->count].word, word);
                word_counts[word_counts->count].count = 1;
                word_counts->count++;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        exit(1);
    }

    char sentence[MAX_WORD_LEN];
    strcpy(sentence, argv[1]);

    WordCount word_counts[MAX_TOKENS];
    int num_tokens = 0;

    process_sentence(sentence, word_counts);

    printf("Sentiment analysis:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}