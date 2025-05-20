//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer)!= EOF) {
        int length = strlen(buffer);
        if (length > 0 && length <= MAX_WORD_LENGTH) {
            strcpy(words[numWords].word, buffer);
            words[numWords].length = length;
            numWords++;
        }
    }

    fclose(file);
}

void shuffleWords() {
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    loadWords();
    shuffleWords();

    int score = 0;
    int mistakes = 0;
    int currentWordIndex = 0;
    int timeLeft = 60;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("Press enter to begin.\n");
    getchar();

    clock_t startTime = clock();
    while (timeLeft > 0 && currentWordIndex < numWords) {
        printf("\n%s\n", words[currentWordIndex].word);
        char input[MAX_WORD_LENGTH];
        fflush(stdout);
        if (fgets(input, MAX_WORD_LENGTH, stdin) == NULL) {
            printf("Error: could not read input\n");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[currentWordIndex].word) == 0) {
            score++;
        } else {
            mistakes++;
        }

        currentWordIndex++;
        if (currentWordIndex >= numWords) {
            break;
        }
    }

    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nTest complete!\n");
    printf("You scored %d points with %d mistakes.\n", score, mistakes);
    printf("Your typing speed is %d words per minute.\n", (int)(score / (elapsedTime / 60)));

    return 0;
}