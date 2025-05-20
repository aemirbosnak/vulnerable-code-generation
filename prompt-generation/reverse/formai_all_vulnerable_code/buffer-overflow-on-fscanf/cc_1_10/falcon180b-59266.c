//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 10
#define MAX_WORDS 100

char words[MAX_WORDS][WORD_LENGTH + 1];
int numWords;

void initWords() {
    FILE *file;
    char line[WORD_LENGTH + 1];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s", line)!= EOF) {
        strcpy(words[i], line);
        i++;
    }

    numWords = i;
    fclose(file);
}

void displayWords() {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    srand(time(NULL));
    initWords();

    int score = 0;
    int numErrors = 0;
    int timeLimit = 60;
    int wordIndex = rand() % numWords;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", timeLimit);
    printf("Press enter to begin:\n");

    fflush(stdin);
    scanf("%c", &score);

    while (timeLimit > 0) {
        displayWords();
        char input[WORD_LENGTH + 1];
        scanf("%s", input);

        if (strcmp(input, words[wordIndex]) == 0) {
            wordIndex = (wordIndex + 1) % numWords;
            score++;
        } else {
            numErrors++;
            wordIndex = rand() % numWords;
        }

        if (timeLimit == 0) {
            break;
        }

        usleep(100000);
        timeLimit--;
    }

    printf("\nTime's up! Your final score is %d.\n", score);
    printf("You made %d errors.\n", numErrors);

    return 0;
}