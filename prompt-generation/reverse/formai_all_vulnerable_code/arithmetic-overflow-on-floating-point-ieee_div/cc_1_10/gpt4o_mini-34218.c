//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to display typing test instructions
void displayInstructions() {
    printf("Welcome to the Shape-Shifting Typing Speed Test!\n");
    printf("You will be given a random quote to type.\n");
    printf("Type the quote as quickly and accurately as you can!\n");
    printf("Press Enter when you are ready to start...\n");
    getchar(); // Wait for user to press Enter
}

// Function to select a random quote
const char* getRandomQuote() {
    const char* quotes[] = {
        "The only way to do great work is to love what you do.",
        "Life is what happens when you're busy making other plans.",
        "Get busy living or get busy dying.",
        "You have within you right now, everything you need to deal with whatever the world can throw at you.",
        "It does not matter how slowly you go as long as you do not stop."
    };
    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);
    return quotes[rand() % numQuotes];
}

// Function to calculate WPM
float calculateWPM(int charactersTyped, double timeTaken) {
    return (charactersTyped / 5.0) / (timeTaken / 60.0);
}

// Typing test function
void typingTest() {
    const char* quote = getRandomQuote();
    printf("Your quote to type:\n\n\"%s\"\n\n", quote);
    printf("Start typing below:\n");

    char input[256];
    clock_t start = clock();
    fgets(input, sizeof(input), stdin);
    clock_t end = clock();

    // Process results
    int charactersTyped = strlen(input) - 1; // Subtract 1 for newline character
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC; // Time in seconds
    float wpm = calculateWPM(charactersTyped, timeTaken);

    // Accuracy calculation
    int errors = 0, length = strlen(quote);
    for (int i = 0; i < length; i++) {
        if (quote[i] != input[i]) {
            errors++;
        }
    }

    // Display the results
    printf("\n----- Results -----\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Characters typed: %d\n", charactersTyped);
    printf("Words per minute: %.2f\n", wpm);
    printf("Errors: %d out of %d\n", errors, length);
    printf("-------------------\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    displayInstructions();
    typingTest();
    printf("Thank you for playing! Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter
    return 0;
}