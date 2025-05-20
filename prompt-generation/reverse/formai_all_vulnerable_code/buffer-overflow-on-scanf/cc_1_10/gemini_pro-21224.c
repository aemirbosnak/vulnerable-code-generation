//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Colors for output
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// Function to generate random text
char* generate_text(int length) {
    char* text = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        text[i] = 'a' + rand() % 26;
    }
    text[length] = '\0';
    return text;
}

// Function to test typing speed
void test_typing_speed(int duration) {
    // Generate random text
    char* text = generate_text(50);

    // Start timer
    clock_t start = clock();

    // Get user input
    char* input = malloc(51);
    printf("Type the following text as fast as you can:\n");
    printf("%s", text);
    scanf("%s", input);

    // Stop timer
    clock_t end = clock();

    // Calculate typing speed in words per minute (WPM)
    int wpm = (strlen(input) / 5) * (60000.0 / (end - start));

    // Check if the input is correct
    int correct = strcmp(input, text) == 0;

    // Print results
    if (correct) {
        printf(GREEN "Congratulations! You typed %d words per minute with 100%% accuracy.\n" RESET, wpm);
    } else {
        printf(RED "Oops! Your input was incorrect. You typed %d words per minute with %d%% accuracy.\n" RESET, wpm, (int)(100.0 * strlen(input) / strlen(text)));
    }

    // Free memory
    free(text);
    free(input);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Get user input for duration
    int duration;
    printf("Enter the duration of the test (in seconds): ");
    scanf("%d", &duration);

    // Test typing speed
    test_typing_speed(duration);

    return 0;
}