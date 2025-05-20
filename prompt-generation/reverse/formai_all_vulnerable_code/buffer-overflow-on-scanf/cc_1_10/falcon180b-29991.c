//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void loadWords(WordFreq words[], int numWords) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    fp = fopen("spam_words.txt", "r");

    if (fp == NULL) {
        printf("Error loading spam words.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, " \n");

        while (word!= NULL) {
            strcpy(words[i].word, word);
            words[i].count = 0;
            i++;

            if (i >= numWords) {
                break;
            }

            word = strtok(NULL, " \n");
        }
    }

    fclose(fp);
}

int isSpam(char *message, WordFreq words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    int i, j;
    int numSpamWords = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            strncpy(word, &message[i], MAX_WORD_LENGTH);
            word[strcspn(word, " \n")] = '\0';

            for (j = 0; j < numWords; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].count++;
                    numSpamWords++;
                }
            }
        }
    }

    return numSpamWords;
}

int main() {
    char message[MAX_WORDS];
    WordFreq words[MAX_WORDS];
    int numWords;

    printf("Enter number of spam words to load: ");
    scanf("%d", &numWords);

    loadWords(words, numWords);

    printf("Enter message to check for spam: ");
    fgets(message, MAX_WORDS, stdin);

    int numSpamWords = isSpam(message, words, numWords);

    if (numSpamWords > 0) {
        printf("Message contains %d spam word(s).\n", numSpamWords);
    } else {
        printf("Message does not contain any spam words.\n");
    }

    return 0;
}