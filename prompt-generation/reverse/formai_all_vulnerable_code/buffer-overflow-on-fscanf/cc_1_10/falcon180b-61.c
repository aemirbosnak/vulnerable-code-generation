//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords;
int wordLengths[MAX_WORDS];

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i])!= EOF) {
        wordLengths[i] = strlen(words[i]);
        i++;
        if (i == MAX_WORDS) {
            break;
        }
    }

    numWords = i;
    fclose(file);
}

int main() {
    srand(time(NULL));

    loadWords();

    char input[MAX_WORD_LENGTH];
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    float accuracy = 0.0;

    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i+1);
        for (int j = 0; j < wordLengths[i]; j++) {
            printf("_");
        }
        printf("\n");

        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;
    }

    accuracy = (float)correct / total;

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Accuracy: %.2f%%\n", accuracy * 100.0);

    return 0;
}