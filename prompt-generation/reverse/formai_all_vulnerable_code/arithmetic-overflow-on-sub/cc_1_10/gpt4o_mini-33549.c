//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 256
#define MAX_PROMPTS 5

const char *prompts[MAX_PROMPTS] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming is like writing a book, except when you miss a chapter!",
    "In a world where you can be anything, be kind.",
    "Code is like humor. When you have to explain it, it’s bad.",
    "Debugging is like being the detective in a crime movie where you are also the murderer."
};

void clearInputBuffer() {
    while (getchar() != '\n');
}

void getUserInput(char *input, size_t length) {
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character if present
}

void displayPrompt(int promptIndex) {
    printf("\nType the following text:\n\n");
    printf("%s\n\n", prompts[promptIndex]);
}

void calculateTypingSpeed(int seconds, int charactersTyped) {
    float speed = (float)charactersTyped / 5; // Speed in WPM (Words Per Minute)
    printf("You typed %d characters in %d seconds.\n", charactersTyped, seconds);
    printf("Your typing speed is: %.2f WPM\n", speed);
}

int main() {
    char input[MAX_TEXT_LENGTH];
    int promptIndex;
    clock_t start, end;
    double elapsedTime;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be provided with a prompt to type. Let's begin!\n\n");

    for (promptIndex = 0; promptIndex < MAX_PROMPTS; promptIndex++) {
        displayPrompt(promptIndex);
        
        printf("Press Enter to start the timer...\n");
        clearInputBuffer();
        start = clock();

        getUserInput(input, sizeof(input));

        end = clock();
        elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
        int charactersTyped = strlen(input);

        if (strcmp(input, prompts[promptIndex]) == 0) {
            printf("Well done! Your input matches the prompt.\n");
        } else {
            printf("Your input didn't match the prompt. Keep practicing!\n");
        }
        
        calculateTypingSpeed((int)elapsedTime, charactersTyped);
        
        printf("\nPress Enter to continue to the next prompt...\n");
        clearInputBuffer();
    }

    printf("\nYou have completed the typing test! Thanks for participating!\n");
    return 0;
}