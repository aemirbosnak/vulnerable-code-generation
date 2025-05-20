//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int rating;
} WordRating;

int main() {
    FILE *inputFile;
    char line[1000];
    int numWords = 0;
    WordRating *wordRatings = (WordRating *) malloc(MAX_WORDS * sizeof(WordRating));
    int i, j;

    inputFile = fopen("movie_reviews.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordRatings[i].word) == 0) {
                    wordRatings[i].rating++;
                    break;
                }
            }

            if (i == numWords) {
                numWords++;
                wordRatings[numWords-1].word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
                strcpy(wordRatings[numWords-1].word, word);
                wordRatings[numWords-1].rating = 1;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordRatings[i].word, wordRatings[i].rating);
    }

    for (i = 0; i < numWords; i++) {
        free(wordRatings[i].word);
    }

    free(wordRatings);

    return 0;
}