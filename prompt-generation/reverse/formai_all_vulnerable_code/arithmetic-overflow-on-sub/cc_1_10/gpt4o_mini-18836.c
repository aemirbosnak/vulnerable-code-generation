//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 255
#define TEST_DURATION 30 // Duration of the typing test in seconds
#define RANDOM_TEXT_COUNT 5

const char *sampleTexts[RANDOM_TEXT_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "In a galaxy far, far away, a cat learned to type.",
    "Supercalifragilisticexpialidocious, but nobody knows how to spell it!",
    "Why did the programmer quit his job? Because he didn't get arrays.",
    "To be or not to be, that is a question programmers ponder at 3 AM."
};

// Function to display an instruction on how to start the test
void printInstructions() {
    printf("Welcome to the C Typing Speed Test! 🐢\n");
    printf("You have %d seconds to type the following phrase:\n", TEST_DURATION);
    printf("---------------------------------------------------------\n");
    printf("Just type the sentence as fast as you can. Ready? GO! 🚀\n");
    sleep(2);
}

// Function to select a random text from the sample texts
const char *getRandomText() {
    srand(time(NULL));
    return sampleTexts[rand() % RANDOM_TEXT_COUNT];
}

// Function to check the user's input against the correct text and compute speed
void checkTypingSpeed(const char *text) {
    char userInput[MAX_TEXT_LENGTH];
    int typedChars = 0;
    clock_t start = clock();
    
    printf("Your text: \n%s\n", text);
    printf("Type here: ");
    
    // Start the typing test for the specified duration
    time_t startTime, endTime;
    time(&startTime);
    
    while(1) {
        // Get user input
        fgets(userInput, MAX_TEXT_LENGTH, stdin);
        
        // Remove newline character from fgets
        userInput[strcspn(userInput, "\n")] = 0; // Safe way to remove newline
        
        // Count the number of characters typed correctly
        typedChars += strlen(userInput);
        
        // Check if the user typed the correct sentence
        if (strcmp(userInput, text) == 0) {
            printf("Well done! You typed it correctly! 👍\n");
            break;
        }
        
        // Capture the end time
        time(&endTime);
        
        // Check if the duration has passed
        if (difftime(endTime, startTime) >= TEST_DURATION) {
            printf("Time's up! ⏰ You typed %d characters in %d seconds.\n", typedChars, TEST_DURATION);
            printf("You should've typed: \"%s\"\n", text);
            break;
        }
        
        // Provide feedback on incorrect attempts
        printf("Oops! That wasn't it. Keep going! 🏃\n");
        printf("Keep typing... 🩰 \n");
    }
    
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("You typed %d characters in %.2f seconds.\n", typedChars, duration);
    
    if (duration > 0) {
        double speed = (typedChars / duration) * 60; // Speed in characters per minute
        printf("Your typing speed is: %.2f characters per minute! 💨\n", speed);
    } else {
        printf("You typed too fast for the clock to keep up! 🤯\n");
    }
}

// Entry point of the program
int main() {
    printInstructions();
    
    const char *randomText = getRandomText();
    
    checkTypingSpeed(randomText);
    
    printf("Thanks for playing the C Typing Speed Test! 🎉\n");
    
    // A random ending message
    printf("If you see a bug, don't squish it! Just type 'bug' next time! 🐞\n");
    
    return 0;
}