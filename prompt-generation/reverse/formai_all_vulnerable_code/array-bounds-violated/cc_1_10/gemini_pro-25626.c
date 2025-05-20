//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct Word {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionarySize = 0;

void loadDictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        line[strlen(line) - 1] = '\0';  // Remove newline character
        strcpy(dictionary[dictionarySize].word, line);
        dictionary[dictionarySize].count = 0;
        dictionarySize++;
    }

    fclose(fp);
}

int compareWords(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

int findWord(const char *word) {
    int low = 0;
    int high = dictionarySize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int result = strcmp(word, dictionary[mid].word);

        if (result == 0) {
            return mid;
        } else if (result < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    loadDictionary();
    qsort(dictionary, dictionarySize, sizeof(Word), compareWords);

    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    char *word = strtok(text, " ");
    while (word != NULL) {
        int index = findWord(word);
        if (index == -1) {
            printf("%s is not in the dictionary.\n", word);
        } else {
            printf("%s is in the dictionary.\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}