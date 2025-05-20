//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadWords(char *filename, WordFrequency *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        WordFrequency *current = words;
        while (current->frequency!= 0) {
            current++;
        }
        strcpy(current->word, word);
        current->frequency = 1;
    }

    fclose(file);
}

void analyzeSentiment(char *text, WordFrequency *words) {
    int totalWords = 0;
    int positiveWords = 0;
    int negativeWords = 0;

    char *token = strtok(text, " ");
    while (token!= NULL) {
        totalWords++;

        WordFrequency *current = words;
        while (current->frequency!= 0) {
            if (strcmp(current->word, token) == 0) {
                if (current->frequency > 0) {
                    positiveWords++;
                } else {
                    negativeWords++;
                }
                break;
            }
            current++;
        }

        token = strtok(NULL, " ");
    }

    printf("Total words: %d\n", totalWords);
    printf("Positive words: %d\n", positiveWords);
    printf("Negative words: %d\n", negativeWords);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <words_file> <text_file>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    loadWords(argv[1], words);

    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        printf("Error loading text file.\n");
        return 1;
    }

    char text[MAX_WORD_LENGTH * 100];
    fgets(text, sizeof(text), textFile);
    fclose(textFile);

    analyzeSentiment(text, words);

    return 0;
}