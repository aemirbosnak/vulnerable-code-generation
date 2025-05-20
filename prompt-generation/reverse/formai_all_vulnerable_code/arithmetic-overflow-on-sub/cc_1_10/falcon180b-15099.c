//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define NUM_WORDS 10

char *words[] = {"the", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog", "in", "the", "middle", "of", "the", "night"};

int main() {
    srand(time(NULL));
    int wordIndex = rand() % NUM_WORDS;
    char *word = words[wordIndex];

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following word:\n");
    printf("%s\n", word);

    int length = strlen(word);
    char *buffer = malloc(length + 1);
    strcpy(buffer, word);

    int correctLetters = 0;
    int incorrectLetters = 0;
    int lettersTyped = 0;

    printf("Press enter to begin the test...\n");
    getchar();

    clock_t start = clock();
    while (lettersTyped < length) {
        char c = getchar();
        if (c == '\n') {
            printf("\n");
            break;
        }

        if (c == buffer[lettersTyped]) {
            correctLetters++;
        } else {
            incorrectLetters++;
        }

        lettersTyped++;
    }

    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTest complete!\n");
    printf("You typed %d letters correctly, %d letters incorrectly, and %d letters in total.\n", correctLetters, incorrectLetters, lettersTyped);
    printf("Your typing speed was %d letters per second.\n", (int)(lettersTyped / elapsed));

    free(buffer);
    return 0;
}