//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// function to get a random character
char getRandomChar() {
    char c;
    int r = rand() % 26; // get a random number between 0 and 25
    c = 'a' + r; // map the random number to an alphabetic character
    return c;
}

// function to get the user's input character
char getUserChar() {
    struct termios old_tio, new_tio;
    char c;

    // change the terminal settings to turn off canonical mode and echo
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    // read one character from the user
    c = getchar();

    // restore the terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    return c;
}

int main() {
    int numChars = 0; // number of characters typed
    int numMistakes = 0; // number of mistakes made
    char targetChar; // character the user is supposed to type
    char userChar; // character the user typed
    float elapsedTime; // elapsed time in seconds
    time_t startTime, endTime; // start and end time in seconds

    // seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type as many characters as you can in 30 seconds.\n");
    printf("Press enter to start.\n");
    getchar();

    startTime = time(NULL); // record the start time
    endTime = startTime + 30; // set the end time to be 30 seconds from now

    while (time(NULL) < endTime) { // loop until the time is up
        targetChar = getRandomChar(); // get a random character
        printf("%c", targetChar); // display the character for the user to type
        userChar = getUserChar(); // get the user's input character
        if (userChar == targetChar) { // if the user typed the correct character
            printf("\b \b"); // erase the character from the screen
            numChars++; // increment the number of characters typed
        } else { // if the user made a mistake
            printf("\a"); // beep to indicate a mistake
            numMistakes++; // increment the number of mistakes made
        }
    }

    elapsedTime = difftime(time(NULL), startTime); // calculate the elapsed time in seconds

    printf("\n\nTime's up!\n");
    printf("You typed %d characters with %d mistakes in %.2f seconds.\n", numChars, numMistakes, elapsedTime);
    printf("Your typing speed was %.2f characters per minute.\n", (numChars / elapsedTime) * 60);

    return 0;
}