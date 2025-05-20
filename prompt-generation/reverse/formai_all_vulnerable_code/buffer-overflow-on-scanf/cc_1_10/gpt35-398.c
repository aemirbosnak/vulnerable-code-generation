//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_LENGTH 15

int main() {
    srand(time(0)); // Initialize random seed based on time

    char words[MAX_WORDS][MAX_LENGTH] = {"apple", "banana", "cat", "dog", "elephant", "frog", "gorilla", "hello", "indigo", "jacket", "kite", "lion", "mouse", "noodle", "orange", "pie", "question", "rapid", "sandal", "turtle"};
    int num_words = sizeof(words) / sizeof(words[0]); // Calculate number of words

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be shown a list of words to type as fast as you can.\n");
    printf("Press ENTER to start. Press CTRL + C to quit at any time.\n\n");
    getchar(); // Wait for user to press ENTER

    while (1) {
        printf("Get Ready!\n");
        printf("3...");
        fflush(stdout); // Force output to be printed
        sleep(1); // Wait for 1 second
        printf("2...");
        fflush(stdout);
        sleep(1);
        printf("1...");
        fflush(stdout);
        sleep(1);
        printf("GO!\n\n");
        fflush(stdout);

        int correct = 0, incorrect = 0, total_time = 0;

        for (int i = 0; i < 10; i++) {
            int random_index = rand() % num_words; // Generate random word index
            printf("%s ", words[random_index]);
            fflush(stdout);

            time_t start_time = time(0); // Get start time
            char input[MAX_LENGTH];
            scanf("%s", input); // Get user input
            time_t end_time = time(0); // Get end time

            int elapsed_time = (int) difftime(end_time, start_time); // Calculate elapsed time in seconds
            total_time += elapsed_time;

            if (strcmp(input, words[random_index]) == 0) { // Compare user input with expected word
                correct++;
                printf("CORRECT (%d seconds)\n", elapsed_time);
            } else {
                incorrect++;
                printf("INCORRECT\n");
            }
        }

        printf("\nRESULTS:\n");
        printf("Total Time Taken: %d seconds\n", total_time);
        printf("Accuracy: %.2f%%\n", ((float) correct / 10) * 100);
        printf("Words Per Minute: %.2f\n\n", (float) correct / ((float) total_time / 60));

        printf("Press ENTER to try again or CTRL + C to quit.\n");
        getchar(); // Wait for user to press ENTER
    }

    return 0;
}