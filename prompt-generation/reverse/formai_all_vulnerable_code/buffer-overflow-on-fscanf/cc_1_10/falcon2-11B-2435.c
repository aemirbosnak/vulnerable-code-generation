//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 10

typedef struct {
    char word[MAX_WORD_SIZE];
    char frequency[MAX_WORD_SIZE];
} Word;

void loadWords(Word words[], int numWords) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_SIZE];
    int frequency = 0;
    while (fscanf(fp, "%s %d", word, &frequency)!= EOF) {
        strcpy(words[numWords].word, word);
        strcpy(words[numWords].frequency, &frequency);
        numWords++;
    }
    fclose(fp);
}

void freeWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
        free(words[i].frequency);
    }
}

void spellCheck(Word words[], int numWords) {
    int numMispelled = 0;
    char word[MAX_WORD_SIZE];
    int frequency;
    int i;

    printf("Enter a sentence: ");
    fgets(word, MAX_WORD_SIZE, stdin);

    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            printf("%s is spelled correctly.\n", word);
        } else {
            printf("%s is spelled incorrectly.\n", word);
            numMispelled++;
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    break;
                }
            }
            if (j == numWords) {
                printf("Sorry, I don't know how to spell that.\n");
            } else {
                printf("Did you mean %s?", words[j].word);
            }
        }
    }

    if (numMispelled == 0) {
        printf("Congratulations! Your sentence was spelled correctly.\n");
    } else {
        printf("There were %d misspelled words in your sentence.\n", numMispelled);
    }
}

int main() {
    Word words[MAX_NUM_WORDS];
    int numWords = 0;

    loadWords(words, numWords);
    printf("Loaded %d words from the dictionary.\n", numWords);

    spellCheck(words, numWords);

    freeWords(words, numWords);

    return 0;
}