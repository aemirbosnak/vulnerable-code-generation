//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

struct word {
    char *word;
    int frequency;
};

struct word dictionary[MAX_WORDS];

int loadDictionary(void) {
    FILE *fp;
    char line[MAX_WORD_LENGTH + 1];
    int i = 0;

    fp = fopen(DICTIONARY_FILE, "r");

    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH + 1, fp)!= NULL) {
        dictionary[i].word = strdup(line);
        dictionary[i].frequency = 1;
        i++;
    }

    fclose(fp);

    return 0;
}

int compareWords(const void *a, const void *b) {
    struct word *wordA = (struct word *)a;
    struct word *wordB = (struct word *)b;

    return strcmp(wordA->word, wordB->word);
}

int spellCheck(char *text) {
    int i, j, k, wordLength;
    char word[MAX_WORD_LENGTH + 1];
    char *wordEnd;
    int found = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[0] = toupper(text[i]);
            wordLength = 1;

            while (i < strlen(text) && isalpha(text[i])) {
                strcat(word, text[i]);
                i++;
                wordLength++;
            }

            wordEnd = word + wordLength - 1;
            word[wordLength] = '\0';

            // Check if the word is in the dictionary
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(dictionary[j].word, word) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Possible spelling error: %s\n", word);
            }

            found = 0;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char text[MAX_WORD_LENGTH + 1];

    printf("Enter the text to spell check:\n");
    fgets(text, MAX_WORD_LENGTH + 1, stdin);

    loadDictionary();

    qsort(dictionary, MAX_WORDS, sizeof(struct word), compareWords);

    spellCheck(text);

    return 0;
}