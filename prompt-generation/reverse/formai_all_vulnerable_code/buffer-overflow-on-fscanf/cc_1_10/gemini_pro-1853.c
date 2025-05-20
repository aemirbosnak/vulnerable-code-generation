//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    FILE *fp;
    char word[MAX_WORD_SIZE];
    Word words[MAX_WORDS];
    int numWords = 0;

    // Read in the dictionary
    if ((fp = fopen("dictionary.txt", "r")) == NULL) {
        perror("Error opening dictionary");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }
    fclose(fp);

    // Sort the dictionary
    qsort(words, numWords, sizeof(Word), compareWords);

    // Read in the text file
    if ((fp = fopen("text.txt", "r")) == NULL) {
        perror("Error opening text file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is in the dictionary
        int index = bsearch(word, words, numWords, sizeof(Word), compareWords);
        if (index < 0) {
            printf("%s is not in the dictionary\n", word);
        } else {
            words[index].count++;
        }
    }
    fclose(fp);

    // Print the words that were not in the dictionary
    for (int i = 0; i < numWords; i++) {
        if (words[i].count == 0) {
            printf("%s is not in the dictionary\n", words[i].word);
        }
    }

    return 0;
}