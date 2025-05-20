//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 20
#define THRESHOLD 10

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int numWords = 0;

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words from file!\n");
        exit(1);
    }

    char word[MAX_WORD_LEN+1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LEN && strlen(word) <= MAX_WORD_LEN) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);
}

void train(char* filename) {
    loadWords(filename);
}

int isSpam(char* email) {
    int spamCount = 0;
    int wordCount = 0;

    char word[MAX_WORD_LEN+1];
    char* token = strtok(email, " ");
    while (token!= NULL) {
        if (isalpha(token[0])) {
            strcpy(word, tolower(token));
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    spamCount += words[i].count;
                    break;
                }
            }
        }
        wordCount++;
        token = strtok(NULL, " ");
    }

    if (spamCount >= THRESHOLD && wordCount >= MIN_WORD_LEN) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    train(filename);

    char email[1000];
    while (1) {
        printf("Enter email: ");
        scanf("%s", email);
        if (isSpam(email)) {
            printf("Spam!\n");
        } else {
            printf("Not spam.\n");
        }
    }

    return 0;
}