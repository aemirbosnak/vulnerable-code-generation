//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_PER_TEST 10
#define MAX_WORD_LENGTH 20

char *words[] = {
    "ability", "above", "accord", "across", "action", "active", "actor", "actual", "advice", "after",
    "again", "against", "age", "agent", "ahead", "air", "all", "allow", "almost", "alone", "along",
    "already", "also", "although", "always", "amount", "ancient", "and", "another", "answer", "any",
    "appear", "apple", "apply", "around", "arrive", "art", "article", "artist", "as", "ask", "away"
};

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Select a random sample of words from the list.
    char *test_words[WORDS_PER_TEST];
    for (int i = 0; i < WORDS_PER_TEST; i++) {
        test_words[i] = words[rand() % (sizeof(words) / sizeof(char *))];
    }

    // Clear the screen and display the instructions.
    printf("\n\nTyping Speed Test\n\nInstructions:\n");
    printf("Type the following words as quickly and accurately as possible:\n\n");

    // Display the test words.
    for (int i = 0; i < WORDS_PER_TEST; i++) {
        printf("%s ", test_words[i]);
    }

    // Start the timer.
    clock_t start_time = clock();

    // Get the user's input.
    char input[MAX_WORD_LENGTH * WORDS_PER_TEST + 1];
    scanf("%s", input);

    // Stop the timer.
    clock_t end_time = clock();

    // Calculate the typing speed.
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int num_errors = 0;
    for (int i = 0; i < WORDS_PER_TEST; i++) {
        if (strcmp(test_words[i], input + (MAX_WORD_LENGTH * i)) != 0) {
            num_errors++;
        }
    }
    double typing_speed = (double)(WORDS_PER_TEST - num_errors) / time_taken;

    // Display the results.
    printf("\n\nResults:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Number of errors: %d\n", num_errors);
    printf("Typing speed: %.2f words per minute\n\n", typing_speed * 60);

    return 0;
}