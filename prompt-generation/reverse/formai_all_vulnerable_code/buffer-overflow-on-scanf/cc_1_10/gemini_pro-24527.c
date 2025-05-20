//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Terminal colors
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Typing test text
char *text = "The quick brown fox jumps over the lazy dog.";

// Function to generate a random string
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'a';
    }
    string[length] = '\0';
    return string;
}

// Function to test typing speed
void test_typing_speed() {
    // Get the current time
    time_t start_time = time(NULL);

    // Print the test text
    printf("%s%s%s\n", BOLD, GREEN, text);

    // Get the user's input
    char *input = malloc(strlen(text) + 1);
    scanf("%s", input);

    // Get the current time
    time_t end_time = time(NULL);

    // Calculate the time taken
    double time_taken = difftime(end_time, start_time);

    // Calculate the typing speed
    double typing_speed = strlen(text) / time_taken;

    // Print the results
    printf("\n%sYour typing speed is %f words per minute.%s\n", BOLD, typing_speed, RESET);

    // Free the allocated memory
    free(input);
}

// Function to play a typing game
void play_typing_game() {
    // Generate a random string
    char *string = generate_string(100);

    // Print the string
    printf("%s%s%s\n", BOLD, BLUE, string);

    // Get the user's input
    char *input = malloc(strlen(string) + 1);
    scanf("%s", input);

    // Check if the user's input is correct
    if (strcmp(input, string) == 0) {
        printf("%s%sCorrect!%s\n", BOLD, GREEN, RESET);
    } else {
        printf("%s%sIncorrect!%s\n", BOLD, RED, RESET);
    }

    // Free the allocated memory
    free(input);
    free(string);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Print the welcome message
    printf("%s%sWelcome to the Typing Speed Test!%s\n", BOLD, MAGENTA, RESET);

    // Get the user's choice
    int choice;
    do {
        printf("\n%s1. Test Typing Speed%s\n", BOLD, RESET);
        printf("%s2. Play Typing Game%s\n", BOLD, RESET);
        printf("%s3. Quit%s\n", BOLD, RESET);
        printf("%sEnter your choice: %s", BOLD, RESET);
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);

    // Call the appropriate function based on the user's choice
    switch (choice) {
        case 1:
            test_typing_speed();
            break;
        case 2:
            play_typing_game();
            break;
        case 3:
            printf("%s%sGoodbye!%s\n", BOLD, YELLOW, RESET);
            break;
    }

    return 0;
}