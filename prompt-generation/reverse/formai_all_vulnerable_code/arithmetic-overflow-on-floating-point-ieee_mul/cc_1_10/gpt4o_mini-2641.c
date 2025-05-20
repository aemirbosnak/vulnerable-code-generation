//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

// Function to get a single character from user input (without pressing Enter)
char getch() {
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

// Function to change terminal text color
void changeColor(int color) {
    printf("\033[1;%dm", color);
}

// Function to reset terminal colors
void resetColor() {
    printf("\033[0m");
}

// Function to clear the terminal
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to display typing test
void typingTest(const char *textToType) {
    char userInput[256];
    time_t start, end;
    double elapsedTime;

    printf("Type the following text:\n\n");
    printf("%s\n", textToType);
    printf("\nPress any key to start...\n");
    getch(); // Wait for user to start

    clearScreen();
    printf("%s\n", textToType);
    start = time(NULL);

    // Get user input
    fgets(userInput, sizeof(userInput), stdin);

    end = time(NULL);
    elapsedTime = difftime(end, start);

    // Calculate typing speed
    int typedWords = 0;
    char *token = strtok(userInput, " \n");
    while (token != NULL) {
        typedWords++;
        token = strtok(NULL, " \n");
    }

    // Calculate words per minute (WPM)
    double wpm = (typedWords / elapsedTime) * 60;

    clearScreen();
    
    // Shape-shifting results based on typing speed
    if (wpm < 20) {
        changeColor(31); // Red for slow
        printf("Your typing speed is: %.2f WPM. Keep practicing!\n", wpm);
    } else if (wpm < 40) {
        changeColor(33); // Yellow for average
        printf("Your typing speed is: %.2f WPM. Not bad!\n", wpm);
    } else {
        changeColor(32); // Green for fast
        printf("Your typing speed is: %.2f WPM. Great job!\n", wpm);
    }

    resetColor();
}

int main() {
    const char *sampleText = "The quick brown fox jumps over the lazy dog";
    
    while (1) {
        typingTest(sampleText);
        printf("\nDo you want to test again? (y/n): ");
        char choice = getch();
        if (choice != 'y' && choice != 'Y') {
            break;
        }
        clearScreen();
    }
    
    printf("Thank you for using the Typing Speed Test!\n");
    return 0;
}