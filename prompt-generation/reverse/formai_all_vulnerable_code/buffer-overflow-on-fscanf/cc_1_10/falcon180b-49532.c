//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void loadWords(Word words[], int* numWords) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    *numWords = 0;
    Word word;
    while (fscanf(file, "%s", word.word)!= EOF) {
        word.count = 0;
        words[*numWords] = word;
        (*numWords)++;
    }

    fclose(file);
}

void checkSpelling(char* text, Word words[], int numWords, FILE* output) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    int found = 0;

    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            int j = 1;

            while (isalpha(text[i + j])) {
                word[j] = tolower(text[i + j]);
                j++;
            }

            word[j] = '\0';

            found = 0;
            for (int k = 0; k < numWords; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                fprintf(output, "Possible spelling error: %s\n", word);
            }
        }

        i++;
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;

    loadWords(words, &numWords);

    char* text = "This is a sample text to check the spelling of words.";
    FILE* output = fopen("output.txt", "w");

    checkSpelling(text, words, numWords, output);

    fclose(output);

    return 0;
}