//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

// Function to get a single character input with no buffering
char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to measure typing speed
void typing_test() {
    const char *text = "The quick brown fox jumps over the lazy dog.";
    char input[100];
    int i;

    printf("Type the following sentence as fast as you can:\n");
    printf("\"%s\"\n", text);
    printf("Press Enter to start...\n");
    
    // Wait for user to press Enter
    getch();
    printf("Start typing!\n");

    // Record start time
    clock_t start_time = clock();
    
    // Start Input Capture
    fgets(input, sizeof(input), stdin);

    // Record end time
    clock_t end_time = clock();

    // Calculate typing duration
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Check for accuracy
    int correct_chars = 0;
    for (i = 0; i < strlen(text); i++) {
        if (input[i] == text[i]) {
            correct_chars++;
        }
    }

    // Calculate typing speed in words per minute
    double words_per_minute = (correct_chars / 5.0) / (duration / 60.0);

    printf("\nYour typing result:\n");
    printf("Time taken: %.2f seconds\n", duration);
    printf("Correct characters: %d\n", correct_chars);
    printf("Words per minute: %.2f\n", words_per_minute);
}

// Function to display welcome message and instructions
void welcome_message() {
    printf("========================================\n");
    printf("          Typing Speed Test\n");
    printf("========================================\n");
    printf("Instructions:\n");
    printf("1. You will be presented with a sentence to type.\n");
    printf("2. Your goal is to type it as quickly and accurately as possible.\n");
    printf("3. Hit Enter when you're ready to start the test.\n");
    printf("========================================\n");
}

// Main Function
int main() {
    welcome_message();
    
    while (1) {
        typing_test();
        printf("\nDo you want to try again? (y/n): ");
        char choice = getch();
        if (choice == 'n' || choice == 'N') {
            printf("\nThank you for participating! Goodbye!\n");
            break;
        } else if (choice == 'y' || choice == 'Y') {
            printf("\nRestarting the typing test...\n");
        } else {
            printf("\nInvalid choice, exiting.\n");
            break;
        }
    }

    return 0;
}