//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Constants for the typing test
#define MAX_TEXT_LENGTH 1000
#define TIMER_DURATION 30  // seconds

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 30 seconds to type the following text:\n");
    printf("Please type as quickly and accurately as you can.\n");
    printf("Press Enter when you are ready to start.\n\n");
    getchar();
}

// Function to generate a random text
void generateRandomText(char *text) {
    const char *sampleText[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Pack my box with five dozen liquor jugs.",
        "How razorback-jumping frogs can level six piqued gymnasts!",
        "Sphinx of black quartz, judge my vow.",
        "Jinxed wizards pluck ivy from the big quilt."
    };

    srand(time(NULL));
    strcpy(text, sampleText[rand() % (sizeof(sampleText) / sizeof(sampleText[0]))]);
}

// Function to calculate typing speed
float calculateSpeed(int charactersTyped, time_t duration) {
    return (float)charactersTyped / 5;  // words are considered 5 characters
}

// Function to execute the typing test
void typingTest() {
    char text[MAX_TEXT_LENGTH];
    char userInput[MAX_TEXT_LENGTH];
    time_t startTime, endTime;
    int charactersTyped = 0;

    generateRandomText(text);
    displayInstructions();

    printf("Your text: \n%s\n", text);
    printf("\nReady? Go!\n\n");

    startTime = time(NULL);
    
    // Get user input
    fgets(userInput, MAX_TEXT_LENGTH, stdin);
    endTime = time(NULL);

    // Trim input to calculate the actual length typed
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == userInput[i]) {
            charactersTyped++;
        } else {
            break;  // Stop counting on first mismatch
        }
    }

    // Calculate total time taken
    time_t duration = difftime(endTime, startTime);
    
    // Display results
    printf("\nTest completed!\n");
    printf("Characters matched: %d\n", charactersTyped);
    printf("Duration: %ld seconds\n", duration);
    printf("Your typing speed: %.2f words per minute.\n", calculateSpeed(charactersTyped, duration) * 60);

    // Encourage improvement
    if (charactersTyped < strlen(text)) {
        printf("Don't worry! Practice makes perfect!\n");
    } else {
        printf("Fantastic job! You've typed the entire text correctly!\n");
    }
}

int main() {
    char continueTest = 'y';
    while (continueTest == 'y' || continueTest == 'Y') {
        typingTest();
        printf("\nWould you like to try again? (y/n): ");
        scanf(" %c", &continueTest);

        // Clear the input buffer
        while (getchar() != '\n');
    }
    
    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}