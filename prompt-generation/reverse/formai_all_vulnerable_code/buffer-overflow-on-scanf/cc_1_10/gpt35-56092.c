//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20
#define DELAY 1000

// Function to generate a random word from the given list
char* get_random_word(char* words[]) {
    srand(time(NULL));
    int random_index = rand() % MAX_WORDS;
    return words[random_index];
}

int main() {
    char* words[MAX_WORDS] = { "programming", "algorithm", "computer", "keyboard", "language", 
                                "software", "application", "internet", "database", "network" };
    char input[MAX_LENGTH];
    int word_count = 0;
    int correct_count = 0;
    int incorrect_count = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Instructions: Type the given word and press Enter to move to the next word.\n");
    printf("Type 'exit' to end the test.\n\n");

    // Wait for user to hit enter to start the test
    printf("Hit Enter to start...\n\n");
    while (getchar() != '\n');

    // Loop to get random words from the list and compare with user input
    while (1) {
        char* word = get_random_word(words);
        printf("Type the word: %s\n", word);

        time_t start_time = time(NULL);  // Start timer
        scanf("%s", input);
        time_t end_time = time(NULL);  // Stop timer

        // Check if user wants to exit
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Calculate time taken to type the word
        double time_taken = difftime(end_time, start_time);
        int speed = (int)((strlen(word) / time_taken) * 60);

        // Compare user input with word
        if (strcmp(input, word) == 0) {
            printf("Correct! Time taken: %.2f seconds. Speed: %d wpm.\n\n", time_taken, speed);
            correct_count++;
        }
        else {
            printf("Incorrect! Time taken: %.2f seconds. Speed: %d wpm.\n\n", time_taken, speed);
            incorrect_count++;
        }

        word_count++;

        if (word_count == MAX_WORDS) {
            break;
        }

        // Pause for a second before displaying the next word
        usleep(DELAY);
    }

    printf("Test Completed!\n");
    printf("Words typed correctly: %d\n", correct_count);
    printf("Words typed incorrectly: %d\n", incorrect_count);
    printf("Total words typed: %d\n", word_count);

    return 0;
}