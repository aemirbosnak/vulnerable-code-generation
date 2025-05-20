//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define MAX_LEN 256
#define TEST_DURATION 30

void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void resetTerminal() {
    struct termios initialSettings;
    tcgetattr(STDIN_FILENO, &initialSettings);
    initialSettings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &initialSettings);
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void countdown() {
    for (int i = 3; i > 0; i--) {
        printf("\nStarting in %d...\n", i);
        sleep(1);
    }
}

void showInstructions() {
    clearScreen();
    printf("\033[1;32mWelcome to the Typing Speed Test!\033[0m\n");
    printf("You will have %d seconds to type the following text as fast as possible.\n", TEST_DURATION);
    printf("Let's see how fast you can type!\n");
    printf("Press any key to start...\n");
    getchar();
}

int calculateSpeed(int charCount, double timeTaken) {
    return (int)((charCount / timeTaken) * 60);
}

void displayResult(int speed, int errors) {
    clearScreen();
    printf("\033[1;34mCongratulations!\033[0m\n");
    printf("Your typing speed is: \033[1;31m%d WPM\033[0m\n", speed);
    if (errors > 0) {
        printf("You made \033[1;31m%d errors\033[0m. Keep practicing!\n", errors);
    } else {
        printf("Great job! No errors!\n");
    }
}

int main() {
    const char *sampleText = "The quick brown fox jumps over the lazy dog.";
    char input[MAX_LEN];
    int charCount = strlen(sampleText);
    
    enableRawMode();
    showInstructions();
    countdown();

    printf("\n\033[1;33mType the following text:\n\"\033[1;35m%s\033[1;33m\"\033[0m\n", sampleText);
    printf("\033[1;33mGo!\033[0m\n");

    time_t start = time(NULL);
    int index = 0;
    int errors = 0;

    while (1) {
        char ch = getchar();
        if (time(NULL) - start >= TEST_DURATION) {
            break;
        }

        if (index < charCount) {
            if (ch == sampleText[index]) {
                index++;
            } else {
                errors++;
            }
        }
    }

    double timeTaken = difftime(time(NULL), start);
    int speed = calculateSpeed(index, timeTaken);
    displayResult(speed, errors);

    resetTerminal();
    return 0;
}