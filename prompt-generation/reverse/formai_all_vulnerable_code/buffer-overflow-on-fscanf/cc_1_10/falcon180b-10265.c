//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void loadWords(struct word words[], int *numWords, FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: too many words in dictionary\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].count = 0;
        (*numWords)++;
    }
}

void countWords(struct word words[], int numWords, char *text) {
    char word[MAX_WORD_LENGTH];
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            strcpy(word, "");
            while (isalpha(text[i])) {
                strcat(word, text[i]);
                i++;
            }
            for (int j = 0; j < numWords; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                }
            }
        }
    }
}

void printWords(struct word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *dict;
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: dictionary file not found\n");
        exit(1);
    }
    struct word words[MAX_WORDS];
    int numWords = 0;
    loadWords(words, &numWords, dict);
    fclose(dict);

    char text[100000];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    countWords(words, numWords, text);

    printf("Spell check complete.\n");
    printWords(words, numWords);

    return 0;
}