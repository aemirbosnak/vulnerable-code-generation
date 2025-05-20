//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int word_count = 0;

    printf("Enter the filename to process: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%99s", word) == 1) {
        to_lowercase(word);

        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (word_count < MAX_WORDS) {
                strcpy(words[word_count].word, word);
                words[word_count].count = 1;
                word_count++;
            } else {
                printf("Word limit reached, some words may not be counted.\n");
                break;
            }
        }
    }

    fclose(file);

    // Sort words
    qsort(words, word_count, sizeof(WordCount), compare);

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return EXIT_SUCCESS;
}