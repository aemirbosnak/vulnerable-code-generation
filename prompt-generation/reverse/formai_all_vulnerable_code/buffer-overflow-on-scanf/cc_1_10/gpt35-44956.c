//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 200
#define WORD_LENGTH 6

char words[MAX_WORDS][WORD_LENGTH] = {
    "hello",
    "world",
    "keyboard",
    "computer",
    "mouse",
    "language",
    "programming",
    "software",
    "hardware",
    "debugging",
    "testing",
    "design",
    "algorithm",
    "iteration",
    "variable",
    "function",
    "integer",
    "floating",
    "operator",
    "statement",
    "conditional",
    "loop",
    "array",
    "pointer",
    "structure",
    "memory",
    "bitwise",
    "shift",
    "logic",
    "comparison",
    "assignment",
    "increment",
    "decrement",
    "address",
    "dereference",
    "initialization",
    "declaration",
    "scope",
    "namespace",
    "library",
    "header",
    "newline",
    "tab",
    "character",
    "string",
    "input",
    "output",
    "file",
    "stream",
    "error",
    "debugger"
};

int main() {
    srand(time(NULL));
    int i, num_words, random_index, correct_words, incorrect_words;
    char input[WORD_LENGTH];
    double start_time, end_time, total_time, typing_speed;

    printf("Welcome to Typing Speed Test!\n");
    printf("You will be given %d random words to type. Press ENTER after each word.\n", MAX_WORDS);
    printf("Are you ready to start? Press ENTER to begin.\n\n");
    getchar();

    num_words = MAX_WORDS;
    correct_words = 0;
    incorrect_words = 0;
    start_time = (double) clock() / CLOCKS_PER_SEC;

    for (i = 0; i < num_words; i++) {
        random_index = rand() % (sizeof(words) / sizeof(words[0]));
        printf("Word %d: %s\n", i + 1, words[random_index]);
        scanf("%s", input);

        if (strcmp(input, words[random_index]) == 0) {
            printf("Correct!\n");
            correct_words++;
        } else {
            printf("Incorrect!\n");
            incorrect_words++;
        }
    }

    end_time = (double) clock() / CLOCKS_PER_SEC;
    total_time = end_time - start_time;
    typing_speed = (double) (correct_words * WORD_LENGTH * 60) / total_time;

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Total time taken: %.2f seconds\n", total_time);
    printf("Your typing speed is: %.2f words per minute\n", typing_speed);
    printf("Thank you for taking the Typing Speed Test!\n");

    return 0;
}