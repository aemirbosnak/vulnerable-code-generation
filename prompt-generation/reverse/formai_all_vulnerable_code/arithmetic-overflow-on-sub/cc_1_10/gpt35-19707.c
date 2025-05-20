//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

// function to get a random character
char getRandomChar() {
    char randomChar;
    do {
        randomChar = (char)(rand() % 128);
    } while (!isprint(randomChar));
    return randomChar;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // introduction
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be prompted to type random characters, and your typing speed will be measured.\n");
    printf("Press Enter when you are ready to begin.\n");
    getchar(); // wait for user to press Enter

    int correctCount = 0; // number of characters typed correctly
    int totalCount = 0; // total number of characters typed
    time_t startTime = time(NULL); // start time

    while (1) { // loop until user presses Ctrl+C
        char randomChar = getRandomChar(); // get a random character
        printf("Type the following character: %c\n", randomChar);
        time_t promptTime = time(NULL); // time at which character was prompted
        char userChar = getchar(); // get the character typed by the user
        time_t endTime = time(NULL); // time at which user finished typing
        if (userChar == '\n') { // user pressed Enter, so end the test
            break;
        } else if (userChar == randomChar) { // character typed correctly
            correctCount++;
        }
        totalCount++;
        printf("Time taken: %ld seconds.\n", endTime - promptTime);
        sleep(1); // pause for 1 second before prompting again
    }

    time_t totalTime = time(NULL) - startTime; // total time taken
    double accuracy = ((double)correctCount / totalCount) * 100; // calculate accuracy
    double speed = ((double)totalCount / totalTime) * 60; // calculate speed

    printf("Typing Speed Test Results:\n");
    printf("Total time taken: %ld seconds.\n", totalTime);
    printf("Total characters typed: %d.\n", totalCount);
    printf("Characters typed correctly: %d.\n", correctCount);
    printf("Accuracy: %.2f%%.\n", accuracy);
    printf("Speed: %.2f characters per minute.\n", speed);

    return 0;
}