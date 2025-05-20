//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("Welcome to the C Word Frequency Counter!\n\n");

    char filename[50];
    printf("Please enter the name of the file you want to analyze: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file.\n");
        return 1;
    }

    printf("\nAnalyzing file...\n\n");

    char *word = malloc(50 * sizeof(char)); // allocate memory for word
    int count = 0;
    int totalWords = 0;
    int uniqueWords = 0;

    // create dynamic array to store individual words and their respective counts
    typedef struct {
        char *word;
        int count;
    } WordCount;

    WordCount *wordCounts = malloc(sizeof(WordCount));
    int numWordCounts = 0;

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            word[count++] = tolower(c);
        } else if (count > 0) {
            word[count] = '\0';

            // check if word already exists in wordCounts array
            int found = 0;
            for (int i = 0; i < numWordCounts; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }

            // if word doesn't exist in wordCounts array, add it
            if (!found) {
                wordCounts = realloc(wordCounts, (numWordCounts + 1) * sizeof(WordCount));
                wordCounts[numWordCounts].word = malloc(strlen(word) + 1);
                strcpy(wordCounts[numWordCounts].word, word);
                wordCounts[numWordCounts].count = 1;
                numWordCounts++;
            }

            count = 0;
            totalWords++;
        }
    }

    // sort wordCounts array in descending order by count using bubble sort algorithm
    for (int i = 0; i < numWordCounts - 1; i++) {
        for (int j = 0; j < numWordCounts - i - 1; j++) {
            if (wordCounts[j].count < wordCounts[j + 1].count) {
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
        }
    }

    // print top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
    printf("\n");

    uniqueWords = numWordCounts;

    printf("Total words analyzed: %d\n", totalWords);
    printf("Total unique words: %d\n", uniqueWords);

    // free memory
    for (int i = 0; i < numWordCounts; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);
    free(word);

    return 0;
}