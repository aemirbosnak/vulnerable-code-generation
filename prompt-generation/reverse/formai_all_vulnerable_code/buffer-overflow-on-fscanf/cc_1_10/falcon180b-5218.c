//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 30
#define MAX_WORD_FREQUENCY 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct Word* words[MAX_WORDS];
int numWords = 0;

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        struct Word* newWord = (struct Word*)malloc(sizeof(struct Word));
        strcpy(newWord->word, word);
        newWord->frequency = 1;
        words[numWords++] = newWord;
    }

    fclose(file);
}

int isSpam(char* message) {
    int numWordsInMessage = 0;
    int totalFrequency = 0;

    char word[MAX_WORD_LENGTH];
    char* messageCopy = strdup(message);
    char* token = strtok(messageCopy, " ");

    while (token!= NULL) {
        int length = strlen(token);
        if (length >= MIN_WORD_LENGTH && length <= MAX_WORD_LENGTH) {
            totalFrequency += words[0]->frequency;
            numWordsInMessage++;
        }

        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, words[i]->word) == 0) {
                totalFrequency += words[i]->frequency;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    free(messageCopy);

    if (numWordsInMessage == 0) {
        return 0;
    }

    return totalFrequency / numWordsInMessage;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <words_file>\n", argv[0]);
        return 1;
    }

    loadWords(argv[1]);

    char message[1000];
    while (fgets(message, sizeof(message), stdin)!= NULL) {
        int spamScore = isSpam(message);
        if (spamScore > 0) {
            printf("Spam score: %d\n", spamScore);
        } else {
            printf("Not spam\n");
        }
    }

    return 0;
}