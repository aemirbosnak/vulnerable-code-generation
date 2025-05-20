//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Display welcome message and instructions
    printf("Welcome to the Typing Speed Test, my dear Watson!\n");
    printf("Type the prompted words as fast as you can and press ENTER to continue.\n\n");

    // Words for typing test
    char* words[] = {"elementary", "my", "dear", "Watson", "capital", "letters", "are", "the", "best", 
                     "I", "have", "a", "consequence", "of", "thinking", "aloud", "I", "always", "say", 
                     "what", "I", "think", "or", "feel", "exactly", "half", "a", "pound", "more", "than",
                     "seven", "pounds", "in", "weight", "three", "stories", "high", "four", "windows",
                     "wide", "sixteen", "stairs", "to", "the", "landlord's", "room", "perfect", "perfect", "perfect"};
    int num_words = sizeof(words) / sizeof(words[0]);

    // Variables for tracking test progress
    int correct = 0;
    int total_time = 0;
    int num_attempts = 0;

    while (1) {
        // Prompt user for next word
        int index = rand() % num_words;
        printf("%s ", words[index]);
        fflush(stdout);

        // Measure response time
        clock_t start_time = clock();
        char response[50];
        fgets(response, sizeof(response), stdin);
        clock_t end_time = clock();
        int response_time = (int) ((end_time - start_time) * 1000 / CLOCKS_PER_SEC);

        // Determine if response is correct
        char* trimmed_response = response;
        while (*trimmed_response == ' ' || *trimmed_response == '\t' || *trimmed_response == '\r' || *trimmed_response == '\n') {
            trimmed_response++;
        }
        if (strcmp(trimmed_response, words[index]) == 0) {
            correct++;
            printf("Correct! ");
        } else {
            printf("Incorrect. ");
        }

        // Display stats
        if (num_attempts > 0) {
            int average_time = total_time / num_attempts;
            printf("[%d / %d correct, Avg: %dms]\n", correct, num_attempts, average_time);
        } else {
            printf("\n");
        }

        // Check if user wants to continue
        printf("Press ENTER to continue, or 'q' to quit: ");
        char option[2];
        fgets(option, sizeof(option), stdin);
        if (option[0] == 'q') {
            break;
        }

        // Update progress variables
        total_time += response_time;
        num_attempts++;
    }

    // Display final stats
    if (num_attempts > 0) {
        int average_time = total_time / num_attempts;
        printf("\nFinal Stats: [%d / %d correct, Avg: %dms]\n", correct, num_attempts, average_time);
    } else {
        printf("\nFinal Stats: [0 / 0 correct, Avg: 0ms]\n");
    }

    return 0;
}