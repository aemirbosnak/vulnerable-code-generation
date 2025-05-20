//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define MAX_LENGTH 200
#define TIME_LIMIT 30 // seconds

// Function to configure terminal to disable echo and raw mode 
void configureTerminal(struct termios *original) {
    struct termios new;
    tcgetattr(STDIN_FILENO, original);
    new = *original;
    new.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

// Function to reset terminal settings to original state
void resetTerminal(const struct termios *original) {
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

// Function to generate a random typing prompt
void generatePrompt(char* prompt) {
    const char* phrases[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Programming in C is fun and exciting!",
        "Let's build a typing speed test together!",
        "Cheerful programming makes us happy!",
        "Type as fast as you can and enjoy!",
        "Practice makes perfect, let's get started!",
        "Consistency is the key to improvement.",
        "Challenge yourself and type this without errors!"
    };
    
    int index = rand() % (sizeof(phrases) / sizeof(phrases[0]));
    strcpy(prompt, phrases[index]);
}

// Function to calculate the typing speed
float calculateSpeed(const char* input, const char* prompt, int seconds) {
    int correctChars = 0;
    int totalChars = strlen(prompt);

    for (int i = 0; i < totalChars; i++) {
        if (input[i] == prompt[i]) {
            correctChars++;
        }
    }
    return ((float)correctChars / totalChars) * 60 / seconds; // words per minute
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    struct termios original;
    char prompt[MAX_LENGTH];
    char userInput[MAX_LENGTH];
    int secondsPassed = 0;

    // Configure terminal settings
    configureTerminal(&original);
    
    // Show a cheerful greeting
    printf("🎉 Welcome to the Typing Speed Test! 🎉\n");
    printf("You have %d seconds to type the following phrase:\n\n", TIME_LIMIT);
    
    // Generate a typing prompt
    generatePrompt(prompt);
    printf("🎈 %s 🎈\n\n", prompt);
    
    // Start the timer
    time_t startTime = time(NULL);
    time_t currentTime;
    
    // Prompt user to start typing
    printf("🚀 Ready, Set, Type! 🚀\n\n");
    
    // Get user input
    while (secondsPassed < TIME_LIMIT) {
        currentTime = time(NULL);
        secondsPassed = difftime(currentTime, startTime);
        
        // Read user input character by character
        char c = getchar();
        
        // Exit if the user presses Enter
        if (c == '\n') {
            break;
        }
        
        // Append to userInput
        if (strlen(userInput) < MAX_LENGTH - 1) {
            userInput[strlen(userInput)] = c;
            userInput[strlen(userInput) + 1] = '\0';  // Null terminate
        }
        
        // Display user input in real time
        printf("\rYou've typed: %s", userInput);
        fflush(stdout);
    }
    
    // Clean up user input string
    userInput[strlen(userInput)] = '\0'; // Null terminate
    
    // Calculate typing speed
    float speed = calculateSpeed(userInput, prompt, secondsPassed);
    
    // Show results
    printf("\n\n🎊 Time's up! 🎊\n");
    printf("You typed: \"%s\"\n", userInput);
    printf("Your typing speed is: %.2f words per minute! 🌟\n", speed);
    
    // Reset terminal settings
    resetTerminal(&original);
    
    // End the program cheerfully
    printf("Thank you for playing! 😊\n");
    printf("Keep practicing and you'll get even better! 💪\n");
    
    return 0;
}