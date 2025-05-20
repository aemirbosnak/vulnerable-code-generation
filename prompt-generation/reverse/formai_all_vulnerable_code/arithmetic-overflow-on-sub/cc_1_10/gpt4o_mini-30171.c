//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Function to calculate typing speed
double calculateSpeed(int wordsCount, double timeTaken) {
    return (wordsCount / timeTaken) * 60;
}

// Function to get a random quote
const char* getRandomQuote() {
    const char* quotes[] = {
        "The journey of a thousand miles begins with one step.",
        "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
        "You must be the change you wish to see in the world.",
        "Life is what happens when you’re busy making other plans.",
        "The only way to do great work is to love what you do."
    };
    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);
    return quotes[rand() % numQuotes];
}

int main() {
    char input[256];
    const char* quote;
    
    srand(time(NULL)); // Seed the random number generator
    
    quote = getRandomQuote(); // Get a random quote
    printf("Type the following quote:\n\n\"%s\"\n\n", quote);
    
    printf("Press Enter when you are ready to start...\n");
    clearInputBuffer();
    
    clock_t start = clock(); // Start timing
    fgets(input, sizeof(input), stdin); // Get user input
    clock_t end = clock(); // End timing

    // Calculate time taken
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    // Count words entered by user
    int wordsCount = 0;
    char* token = strtok(input, " \n"); // Split input into words
    while (token != NULL) {
        wordsCount++;
        token = strtok(NULL, " \n");
    }
    
    // Calculate speed in WPM
    double wpm = calculateSpeed(wordsCount, timeTaken);
    
    // Output results
    printf("You typed %d words in %.2f seconds.\n", wordsCount, timeTaken);
    printf("Your typing speed is %.2f words per minute.\n", wpm);
    
    return 0;
}