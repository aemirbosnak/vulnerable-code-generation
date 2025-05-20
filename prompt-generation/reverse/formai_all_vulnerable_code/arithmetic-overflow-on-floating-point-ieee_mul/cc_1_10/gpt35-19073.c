//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function to generate random letters
char generateRandomLetter() {
    char letter;
    int randomNum = rand() % 26;
    letter = 'a' + randomNum; // generate a lowercase letter
    return letter;
}

int main() {
    // welcome message
    printf("Welcome to the Grateful Typing Speed Test!\n");
    printf("Type the character as fast as you can!\n\n");
    
    // generate a random string of length 50
    char randomString[50];
    for (int i = 0; i < 50; i++) {
        randomString[i] = generateRandomLetter();
    }
    randomString[50] = '\0';

    int correctCount = 0; // tracks number of correct keystrokes
    time_t startTime = time(NULL); // get current time

    // loop through the string and ask the user to type each character
    for (int i = 0; i < 50; i++) {
        char userInput;
        printf("%c ", randomString[i]); // display the current character to type
        scanf(" %c", &userInput); // read user input

        // check if user input is correct
        if (tolower(userInput) == randomString[i]) {
            correctCount++;
        }

        // clear screen to hide the previously typed character
        system("clear");
    }

    time_t endTime = time(NULL); // get current time
    double totalTime = difftime(endTime, startTime); // calculate time difference

    // display results
    printf("You typed %d out of 50 characters correctly.\n", correctCount);
    printf("Your typing speed is %.2f characters per minute.\n", (double) (correctCount/totalTime) * 60);

    return 0;
}