//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void loadWords(FILE *file, WordFrequency *words) {
    char line[MAX_WORD_LENGTH];
    char *word = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        // Remove trailing newline character
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        // Convert line to lowercase
        for (size_t i = 0; i < read; i++) {
            line[i] = tolower(line[i]);
        }

        // Count frequency of each word
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int index = 0;
            for (size_t i = 0; i < MAX_WORD_LENGTH; i++) {
                if (isalnum(word[i])) {
                    words[index].word[i] = word[i];
                    i++;
                } else {
                    words[index].word[i] = '\0';
                    break;
                }
            }
            words[index].count++;
            index++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void displayWordFrequencies(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    loadWords(file, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            numWords++;
        }
    }

    displayWordFrequencies(words, numWords);

    fclose(file);
    return 0;
}