//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define MAX_CHOICE_LENGTH 10

const char *sampleTexts[] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
    "In three words I can sum up everything I've learned about life: it goes on.",
    "That which does not kill us makes us stronger.",
    "Life is what happens when you're busy making other plans.",
    "Get busy living or get busy dying.",
    "You only live once, but if you do it right, once is enough.",
    "The purpose of our lives is to be happy.",
    "Life is really simple, but we insist on making it complicated."
};

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the terminal
}

void displayIntro() {
    clearScreen();
    printf("===================================================\n");
    printf("            Welcome to the Typing Speed Test!    \n");
    printf("===================================================\n");
    printf("Get ready to test your typing skills!\n\n");
    printf("Press Enter to start...\n");
    getchar();
}

const char* getRandomText() {
    srand(time(0)); // Seed for random number generation
    int randomIndex = rand() % (sizeof(sampleTexts) / sizeof(sampleTexts[0]));
    return sampleTexts[randomIndex];
}

void countTypingTime(clock_t start, clock_t end) {
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", timeTaken);
}

void displayResult(int typedCorrectly, int totalLength) {
    printf("===================================================\n");
    printf("Results:\n");
    printf("You typed: %d out of %d characters correctly.\n", typedCorrectly, totalLength);
    double accuracy = ((double)typedCorrectly / totalLength) * 100;
    printf("Accuracy: %.2f%%\n", accuracy);
}

void typingTest() {
    const char *textToType = getRandomText();
    printf("Type the following text:\n\n");
    printf("\"%s\"\n\n", textToType);

    char userInput[MAX_TEXT_LENGTH];
    
    clock_t startTime = clock();
    printf("Start typing now! (Press Enter when you are done)\n");

    fgets(userInput, sizeof(userInput), stdin);
    clock_t endTime = clock();

    int typedLength = strlen(userInput);
    int correctCount = 0;
    
    for (int i = 0; i < typedLength && i < strlen(textToType); ++i) {
        if (userInput[i] == textToType[i]) {
            correctCount++;
        }
    }

    countTypingTime(startTime, endTime);
    displayResult(correctCount, strlen(textToType));
}

void showGoodbyeMessage() {
    printf("===================================================\n");
    printf("Thanks for playing the Typing Speed Test!\n");
    printf("Keep practicing to improve your speed and accuracy!\n");
    printf("Goodbye!\n");
    printf("===================================================\n");
}

int main() {
    int continueTesting = 1;

    while (continueTesting) {
        displayIntro();
        typingTest();
        
        printf("\nDo you want to try again? (type 'yes' or 'no'): ");
        char choice[MAX_CHOICE_LENGTH];
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Strip newline character

        if (strcasecmp(choice, "yes") != 0) {
            continueTesting = 0;
        }
    }
    
    showGoodbyeMessage();
    return 0;
}