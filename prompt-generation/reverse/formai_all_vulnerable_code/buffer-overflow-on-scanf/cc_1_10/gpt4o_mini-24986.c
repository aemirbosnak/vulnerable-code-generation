//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void initialize_word_frequency(WordFrequency *wf, const char *word) {
    strncpy(wf->word, word, MAX_WORD_LENGTH);
    wf->count = 1;
}

int is_word_in_list(const char *word, WordFrequency *wordList, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void clean_word(char *word) {
    char *p = word;
    while (*p) {
        if (ispunct((unsigned char) *p)) {
            *p = ' ';
        }
        p++;
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char currentWord[MAX_WORD_LENGTH];
    WordFrequency wordList[MAX_WORDS];
    int numWords = 0;

    printf("Enter the filename to count word frequencies: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", currentWord) != EOF) {
        clean_word(currentWord);
        to_lowercase(currentWord);

        if (strlen(currentWord) == 0) {
            continue;
        }

        int index = is_word_in_list(currentWord, wordList, numWords);
        if (index == -1) {
            if (numWords < MAX_WORDS) {
                initialize_word_frequency(&wordList[numWords], currentWord);
                numWords++;
            } else {
                printf("Word limit reached, cannot count additional words.\n");
                break;
            }
        } else {
            wordList[index].count++;
        }
    }

    fclose(file);

    // Sorting the word frequencies in descending order
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (wordList[j].count < wordList[j + 1].count) {
                WordFrequency temp = wordList[j];
                wordList[j] = wordList[j + 1];
                wordList[j + 1] = temp;
            }
        }
    }

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return EXIT_SUCCESS;
}