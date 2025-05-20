//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", line)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        words[numWords].length = strlen(line);
        strcpy(words[numWords].word, line);
        numWords++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    loadWords();

    int score = 0;
    int mistakes = 0;

    printf("Welcome to the Sherlock Holmes Typing Speed Test!\n");
    printf("You will be tested on your ability to type words quickly and accurately.\n");
    printf("Press enter to begin...\n");
    getchar();

    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        for (int j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        int correct = 0;
        for (int j = 0; j < words[i].length; j++) {
            if (input[j] == words[i].word[j]) {
                correct++;
            }
        }

        if (correct == words[i].length) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct word was: %s\n", words[i].word);
            mistakes++;
        }
    }

    printf("\nTest complete.\n");
    printf("Score: %d out of %d\n", score, numWords);
    printf("Mistakes: %d\n", mistakes);

    return 0;
}