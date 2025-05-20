//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 30

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void loadWords(struct Word words[], char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 0;
            numWords++;
        }
    }
    fclose(file);
}

int isSpam(char *message, struct Word words[], int numWords) {
    int totalWords = 0;
    int spamWords = 0;
    char *token = strtok(message, " \n\t\r");
    while (token!= NULL) {
        totalWords++;
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                spamWords++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }
        token = strtok(NULL, " \n\t\r");
    }
    if (totalWords == 0) {
        return 0;
    }
    return ((float)spamWords / totalWords) * 100;
}

int main() {
    char filename[100];
    printf("Enter the name of the file containing spam words: ");
    scanf("%s", filename);
    struct Word words[MAX_WORDS];
    int numWords = 0;
    loadWords(words, filename);
    char message[1000];
    printf("Enter the message to be checked for spam: ");
    fgets(message, 1000, stdin);
    int result = isSpam(message, words, numWords);
    if (result >= 50) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }
    return 0;
}