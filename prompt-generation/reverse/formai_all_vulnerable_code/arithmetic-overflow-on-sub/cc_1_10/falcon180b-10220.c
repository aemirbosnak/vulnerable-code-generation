//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define WORD_LENGTH 5
#define WORD_COUNT 10
#define CHAR_COUNT (WORD_LENGTH * WORD_COUNT)
#define CHAR_PER_LINE 20

char* words[WORD_COUNT] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

int main() {
    int i, j, k, correct_count = 0, wrong_count = 0, total_count = 0;
    char input[CHAR_COUNT];
    char* word;
    clock_t start_time, end_time;
    double elapsed_time;
    int chars_per_sec;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following words:\n");

    for (i = 0; i < WORD_COUNT; i++) {
        printf("%s ", words[i]);
    }

    printf("\n");

    start_time = clock();

    for (i = 0; i < WORD_COUNT; i++) {
        word = words[i];
        printf("Type the word '%s': ", word);
        fgets(input, CHAR_COUNT, stdin);

        if (strlen(input)!= WORD_LENGTH) {
            printf("Error: You typed %d characters instead of %d.\n", strlen(input), WORD_LENGTH);
            continue;
        }

        for (j = 0; j < WORD_LENGTH; j++) {
            if (tolower(input[j])!= tolower(word[j])) {
                wrong_count++;
                break;
            }
        }

        if (j == WORD_LENGTH) {
            correct_count++;
        }

        total_count++;
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    chars_per_sec = CHAR_PER_LINE * total_count / elapsed_time;

    printf("\n");
    printf("You typed %d characters in %0.2f seconds.\n", total_count, elapsed_time);
    printf("Your typing speed is %d characters per second.\n", chars_per_sec);
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_count, wrong_count);

    return 0;
}