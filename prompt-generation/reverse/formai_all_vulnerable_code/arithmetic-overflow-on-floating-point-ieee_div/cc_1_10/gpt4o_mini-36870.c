//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define NUM_SENTENCES 5

const char *sentences[NUM_SENTENCES] = {
    "In the hush of twilight, love whispers softly.",
    "Your laughter is the melody that dances in my heart.",
    "Each moment spent with you is a cherished eternity.",
    "Under the stars, we weave dreams together.",
    "With every heartbeat, my soul knows you are the one."
};

// Function to calculate typing speed in words per minute
int calculate_speed(int typed_chars, double time_taken) {
    double minutes = time_taken / 60.0;
    return (int)((typed_chars / 5.0) / minutes);
}

// Function to display a romantic sentence and capture user input
void typing_test() {
    char input[MAX_LENGTH];
    int correct = 0;

    // Select a random sentence
    srand(time(0));
    int index = rand() % NUM_SENTENCES;
    
    printf("Type the following sentence as quickly and accurately as you can:\n");
    printf("\"%s\"\n\n", sentences[index]);
    
    // Get the start time
    time_t start_time = time(NULL);
    
    // Get user input
    fgets(input, MAX_LENGTH, stdin);
    
    // Get the end time
    time_t end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    // Calculate correct characters
    for (int i = 0; i < strlen(sentences[index]); i++) {
        if (input[i] == sentences[index][i]) {
            correct++;
        }
    }
    
    // Calculate and display speed
    int speed = calculate_speed(correct, time_taken);
    
    // Display results
    printf("\nYou typed %d/%d characters correctly!\n", correct, (int)strlen(sentences[index]));
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %d words per minute.\n", speed);
}

// Main function
int main() {
    printf("Welcome to the Romantic Typing Speed Test!\n");
    printf("Let your fingers dance upon the keys as you share your heart through the words.\n");
    printf("Press Enter to begin...\n");
    getchar(); // Wait for user to press Enter

    // Run the typing test
    typing_test();

    printf("\nThank you for joining this romantic journey through typing!\n");
    printf("May love always inspire you, both in words and in deeds.\n");

    return 0;
}