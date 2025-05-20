//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PHRASES 10
#define PHRASE_LENGTH 256

// Cyberpunk phrases for typing test
const char *phrases[MAX_PHRASES] = {
    "Neon lights flicker in the endless night.",
    "The hacker types furiously, breaking firewalls.",
    "Beneath the chrome, humanity fights for freedom.",
    "A razor-thin lens reveals the truth behind lies.",
    "Data streams pulse like the heartbeat of the city.",
    "Synthwave beats resonate off the neon walls.",
    "The cybernetic eye sees all, records everything.",
    "Virtual realities blur with the gritty streets.",
    "In the shadows, a rogue AI plots its escape.",
    "Revolutions are sparked in the depths of cyberspace."
};

// Function to calculate typing speed
double calculate_speed(double time_taken, int characters_typed) {
    return (characters_typed / 5.0) / (time_taken / 60.0);  // WPM calculation
}

int main() {
    char user_input[PHRASE_LENGTH];
    clock_t start_time, end_time;
    double time_taken;
    int phrase_index, characters_typed;

    printf("Welcome to the Cyberpunk Typing Speed Test!\n");
    printf("Type the following phrases as fast as you can:\n\n");

    srand(time(NULL)); // Seed random number generator
    phrase_index = rand() % MAX_PHRASES; // Select a random phrase

    printf("=== Phrase ===\n");
    printf("%s\n\n", phrases[phrase_index]);
    
    printf("Start typing... (press Enter when done)\n");
    start_time = clock(); // Start the timer

    // Get user input
    fgets(user_input, PHRASE_LENGTH, stdin);
    end_time = clock(); // End the timer

    // Remove newline character from user input
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate time taken for typing
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of characters typed
    characters_typed = strlen(user_input);
    
    // Display results
    printf("\n--- Results ---\n");
    printf("You typed: %s\n", user_input);
    printf("Target phrase: %s\n", phrases[phrase_index]);
    
    if (strcmp(user_input, phrases[phrase_index]) == 0) {
        printf("Perfect typing!\n");
    } else {
        printf("There were some errors in your typing...\n");
    }
    
    // Calculate and display the typing speed in words per minute
    double speed = calculate_speed(time_taken, characters_typed);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f WPM\n", speed);

    return 0;
}