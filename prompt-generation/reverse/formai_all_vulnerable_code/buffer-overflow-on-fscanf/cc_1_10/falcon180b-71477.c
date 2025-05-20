//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file: %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Too many words in file: %s\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

int isSpam(char* message, WordCount* words) {
    int numWords = 0;
    int numSpamWords = 0;

    char* tokens = strtok(message, " ");
    while (tokens!= NULL) {
        numWords++;

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(tokens, words[i].word) == 0) {
                numSpamWords++;
                break;
            }
        }

        if (i == numWords) {
            WordCount newWord;
            strcpy(newWord.word, tokens);
            newWord.count = 1;
            words[numWords] = newWord;
        }

        tokens = strtok(NULL, " ");
    }

    return numSpamWords > 0;
}

int main() {
    WordCount words[MAX_WORDS];
    loadWords("spam_words.txt", words);

    char message[1024];
    while (fgets(message, sizeof(message), stdin)!= NULL) {
        if (isSpam(message, words)) {
            printf("Spam detected!\n");
        } else {
            printf("No spam detected.\n");
        }
    }

    return 0;
}