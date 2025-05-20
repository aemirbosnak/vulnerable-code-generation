//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog."

int main() {
    srand(time(NULL));
    char sentence[] = SENTENCE;
    char input[100];
    int len = sizeof(sentence) - 1; // -1 to omit the null terminating character
    int mistakes = 0, correct_chars = 0;

    printf("=======================\n");
    printf("TYPING SPEED TEST\n");
    printf("=======================\n");

    printf("Type the following sentence:\n%s\n", sentence);

    clock_t start = clock();

    for (int i = 0; i < len; i++) {
        input[i] = getchar();
        if (input[i] != sentence[i]) {
            mistakes++;
        }
        if (input[i] == '\n') {
            input[i] = '\0'; // replace the newline character with the null character
            break;
        }
        correct_chars++;
    }

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nResults:\n");
    printf("Time taken: %.2lf seconds\n", time_taken);

    if (strcmp(input, sentence) == 0) {
        printf("You typed the sentence correctly!\n");
    } else {
        printf("Mistakes made: %d\n", mistakes);
        printf("Accuracy: %.2lf%%\n", ((double)(len - mistakes) / len) * 100);
    }

    printf("Typing speed: %.2lf words per minute\n", (double)correct_chars / 5 / time_taken);

    return 0;
}