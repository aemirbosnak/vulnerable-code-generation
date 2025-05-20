//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 15

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    srand(time(NULL));
    char *words[MAX_WORDS];
    int numWords = 0;
    int totalWords = 0;

    // Load words into array
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words file.\n");
        return 1;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            fclose(file);
            return 1;
        }
        words[numWords] = strdup(word);
        numWords++;
        totalWords++;
    }
    fclose(file);

    // Generate conspiracy theory
    char theory[MAX_WORD_LENGTH * 10];
    strcpy(theory, "The ");
    int wordIndex = rand() % numWords;
    strcat(theory, words[wordIndex]);
    strcat(theory, " conspiracy is real!");

    printf("Conspiracy theory: %s\n", theory);

    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    return 0;
}