//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Declare global variables */
char* random_word; // pointer to randomly generated word
int word_length; // length of the word
int typed_length; // length of user's typed text
int mistakes; // number of mistakes made by the user
double elapsed_time; // time taken by the user to type the word
clock_t start_time, end_time; // start and end time for time calculation

/* Function to generate a random word */
void generateRandomWord() {
    /* List of words for testing */
    char* words[] = {"programming", "keyboard", "internet", "speed", "software", "algorithm", "variable", "datatypes", "function", "integer", "decimal", "boolean", "character", "syntax", "statement", "loop", "string", "list", "array", "pointer", "structure", "union", "enum", "typedef", "header", "library"};

    /* Get number of words */
    int num_words = sizeof(words) / sizeof(char*);

    /* Get random index */
    int random_index = rand() % num_words;

    /* Get randomly generated word */
    random_word = words[random_index];

    /* Get length of the word */
    word_length = strlen(random_word);
}

/* Function to calculate elapsed time */
void calculateElapsedTime() {
    /* Calculate elapsed time */
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

/* Function to display results */
void displayResults() {
    /* Calculate WPM */
    double wpm = ((double)typed_length / 5) / (elapsed_time / 60);

    /* Display results */
    printf("\nWord: %s\n", random_word);
    printf("Time: %.2lf seconds\n", elapsed_time);
    printf("Typed: %d/%d characters\n", typed_length, word_length);
    printf("Mistakes: %d\n", mistakes);
    printf("WPM: %.2lf\n", wpm);
}

/* Main function */
int main() {
    /* Welcome message */
    printf("Welcome! This is a typing speed test.\n");
    printf("Type the given word as fast and accurately as possible.\n");

    /* Initialize random seed */
    srand(time(NULL));

    /* Generate random word */
    generateRandomWord();

    /* Display random word */
    printf("Type this word: %s\n\n", random_word);

    /* Get start time */
    start_time = clock();

    /* Get user input */
    char input_word[100]; // buffer for user input
    fgets(input_word, 100, stdin);

    /* Replace newline character with null character */
    input_word[strcspn(input_word, "\n")] = '\0';

    /* Get end time */
    end_time = clock();

    /* Calculate elapsed time */
    calculateElapsedTime();

    /* Get length of typed word */
    typed_length = strlen(input_word);

    /* Loop through characters to check for mistakes */
    mistakes = 0;
    for (int i = 0; i < word_length; ++i) {
        /* Check if character was typed correctly */
        if (i >= typed_length) {
            mistakes++;
            continue;
        }
        if (random_word[i] != input_word[i]) {
            mistakes++;
        }
    }

    /* Display results */
    displayResults();

    /* Check if user wants to play again */
    char play_again;
    printf("\nPlay again? (y/n): ");
    scanf(" %c", &play_again);
    if (play_again == 'y' || play_again == 'Y') {
        main();
    }
    else {
        printf("Thank you for playing!\n");
        return 0;
    }
}