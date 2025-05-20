//Falcon-180B DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    char input[MAX_WORD_LEN];
    FILE *file;
    WordCount words[MAX_WORDS] = {{0}};
    int numWords = 0;

    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file line by line
    while (fscanf(file, "%s", input)!= EOF) {
        // Convert input string to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Check if input string is a valid word
        if (input[0] == '\0' ||!isalpha(input[0])) {
            continue;
        }

        // Check if input string is already a word in the array
        for (int i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        // Add input string as a new word to the array
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        strcpy(words[numWords].word, input);
        words[numWords].count = 1;
        numWords++;
    }

    // Sort words alphabetically
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print word count
    printf("Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}