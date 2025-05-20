//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 20
#define WORD_COUNT 10

// Function to print a random word
void print_word(char word[WORD_LENGTH]) {
    printf("%s ", word);
}

// Function to generate a random word
void generate_word(char word[WORD_LENGTH]) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[WORD_LENGTH - 1] = '\0';
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char words[WORD_COUNT][WORD_LENGTH];

    // Generate random words
    for (int i = 0; i < WORD_COUNT; i++) {
        generate_word(words[i]);
    }

    int correct_count = 0;
    int incorrect_count = 0;

    // Test the user's typing speed
    for (int i = 0; i < WORD_COUNT; i++) {
        printf("\nWord %d: ", i + 1);
        fflush(stdout);
        char user_input[WORD_LENGTH];
        scanf("%s", user_input);
        if (strcmp(user_input, words[i]) == 0) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

    // Print the results
    printf("\nResults:\n");
    printf("Correct: %d\n", correct_count);
    printf("Incorrect: %d\n", incorrect_count);

    return 0;
}