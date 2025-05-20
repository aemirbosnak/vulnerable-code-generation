//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount **words;
    int numWords;
} WordList;

void initializeWordList(WordList *list) {
    list->numWords = 0;
    list->words = NULL;
}

void addWord(WordList *list, char *word) {
    WordCount *count = NULL;
    for (int i = 0; i < list->numWords; i++) {
        if (strcmp(list->words[i]->word, word) == 0) {
            count = list->words[i];
            break;
        }
    }
    if (count == NULL) {
        count = malloc(sizeof(WordCount));
        count->word = strdup(word);
        count->count = 0;
        list->words = realloc(list->words, (list->numWords + 1) * sizeof(WordCount*));
        list->words[list->numWords] = count;
        list->numWords++;
    }
    count->count++;
}

int isSpam(WordList *list, char *text) {
    int totalWords = 0;
    int spamWords = 0;
    char *word = strtok(text, " ");
    while (word!= NULL) {
        totalWords++;
        WordCount *count = NULL;
        for (int i = 0; i < list->numWords; i++) {
            if (strcmp(list->words[i]->word, word) == 0) {
                count = list->words[i];
                break;
            }
        }
        if (count!= NULL) {
            spamWords++;
        }
        word = strtok(NULL, " ");
    }
    return ((float)spamWords / totalWords) * 100;
}

int main() {
    WordList spamWords;
    initializeWordList(&spamWords);
    FILE *file = fopen("spam_words.txt", "r");
    if (file == NULL) {
        printf("Error opening spam_words.txt\n");
        return 1;
    }
    char word[MAX_STRING_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(&spamWords, word);
    }
    fclose(file);

    char text[MAX_STRING_LENGTH];
    printf("Enter text to check for spam:\n");
    fgets(text, MAX_STRING_LENGTH, stdin);
    int spamPercentage = isSpam(&spamWords, text);
    printf("Spam percentage: %d%%\n", spamPercentage);

    return 0;
}