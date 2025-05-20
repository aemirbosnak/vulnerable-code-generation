//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 40
#define NUM_WORDS 10
#define BUFFER_SIZE 200
#define MIN_SPEED 30
#define MAX_ATTEMPTS 3
#define SECONDS_PER_MINUTE 60

char *words[NUM_WORDS] = {
    "The quick brown fox jumps over the lazy dog.",
    "A long time ago in a galaxy far, far away.",
    "One if by land, two if by sea.",
    "The early bird gets the worm.",
    "In four hundred pages, Herman Melville tells the story of the whale.",
    "We hold these truths to be self-evident, that all men are created equal.",
    "It was a dark and stormy night.",
    "To be, or not to be, that is the question.",
    "Play it again, Sam.",
    "An apple a day keeps the doctor away."
};

void print_instructions() {
    printf("\nWelcome to the C Typing Speed Test!\n");
    printf("------------------------------------\n");
    printf("Type the given word as fast as you can.\n");
    printf("------------------------------------\n");
    printf("You will be given a total of %d words.\n", NUM_WORDS);
    printf("------------------------------------\n");
    printf("Your typing speed will be measured in words per minute.\n");
    printf("------------------------------------\n");
    printf("Your minimum target typing speed is %d wpm.\n", MIN_SPEED);
    printf("------------------------------------\n");
}

int main() {
    char input_buffer[BUFFER_SIZE];
    char *current_word;
    int attempts = 0;
    int words_typed = 0;
    double elapsed_time = 0.0;
    double wpm = 0.0;
    clock_t start, end;

    print_instructions();

    current_word = words[0];

    start = clock();

    while (words_typed < NUM_WORDS) {
        printf("\n%s", current_word);
        fgets(input_buffer, BUFFER_SIZE, stdin);
        input_buffer[strlen(input_buffer)] = '\0';

        if (strcmp(input_buffer, current_word) == 0) {
            printf("Correct!\n");
            words_typed++;
            current_word = words[words_typed];
        } else {
            if (attempts < MAX_ATTEMPTS) {
                printf("Incorrect! Try again.\n");
                attempts++;
            } else {
                printf("Incorrect! The correct answer was: %s\n", current_word);
                printf("Better luck next time.\n");
                break;
            }
        }
    }

    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    wpm = (double)NUM_WORDS / elapsed_time * SECONDS_PER_MINUTE;

    printf("\nYour typing speed is: %f wpm\n", wpm);

    if (wpm < MIN_SPEED) {
        printf("Sorry, you didn't meet the minimum typing speed.\n");
    } else {
        printf("Congratulations, you exceeded the minimum typing speed!\n");
    }

    return 0;
}