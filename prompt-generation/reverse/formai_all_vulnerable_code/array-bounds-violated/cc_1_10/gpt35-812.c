//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char input[50]; // Input string to be typed
    char typed[50]; // String typed by user
    int errors = 0; // Number of errors made by user
    int time_taken = 0; // Time taken by user to type the string
    float wpm = 0; // Words per minute typed
    time_t start, end; // Time variables to measure time taken

    printf("Welcome to the typing speed test challenge!\n\n"
           "You will be given a random string of characters to type accurately "
           "in the shortest possible time!\n\n");

    // String to be typed by user generated randomly
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                 "sed do eiusmod tempor incididunt ut labore et dolore "
                 "magna aliqua. Ut enim ad minim veniam, quis nostrud "
                 "exercitation ullamco laboris nisi ut aliquip ex ea "
                 "commodo consequat. Duis aute irure dolor in reprehenderit "
                 "in voluptate velit esse cillum dolore eu fugiat nulla "
                 "pariatur. Excepteur sint occaecat cupidatat non proident, "
                 "sunt in culpa qui officia deserunt mollit anim id est laborum.";

    printf("Type the following string as fast as you can:\n\n"
           "\t%s\n\n"
           "Press enter to start the timer!", str);

    getchar();

    // Measure start time
    time(&start);

    printf("Type now:\n");

    fgets(typed, sizeof(typed), stdin); // Get input from user

    // Measure end time
    time(&end);

    printf("\nTime taken: %d seconds!\n", (int) difftime(end, start));

    // Calculate time taken in seconds
    time_taken = (int) difftime(end, start);

    // Remove newline character from input
    if (typed[strlen(typed) - 1] == '\n') {
        typed[strlen(typed) - 1] = '\0';
    }

    // Calculate number of errors made
    for (int i = 0; i < strlen(str); i++) {
        if (typed[i] != str[i]) {
            errors++;
        }
    }

    printf("\nNumber of errors made: %d\n", errors);

    // Calculate words per minute
    wpm = (strlen(str) / 5.0 / time_taken) * 60.0;

    printf("\nYour typing speed is: %.2f WPM (words per minute)!\n", wpm);

    if (wpm > 60) {
        printf("\nWell done, you have achieved a great typing speed!\n");
    } else if (wpm > 40) {
        printf("\nGood job, you have achieved a good typing speed!\n");
    } else {
        printf("\nYou need more practice, keep typing to improve your speed!\n");
    }

    return 0;
}