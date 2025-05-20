//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Initialize variables
    char input[100], target[100];
    int i, j, errors = 0, startTime, endTime, timeTaken;
    float speed;

    // Display a welcome message
    printf("Welcome to the Typing Speed Test!\n");
    printf("Get ready to test your fingers' agility!\n\n");

    // Get the target text
    printf("Enter the target text:\n");
    scanf("%[^\n]s", target);

    // Start the timer
    startTime = clock();

    // Get the input from the user
    printf("Start typing when ready!\n");
    scanf("%[^\n]s", input);

    // Stop the timer
    endTime = clock();

    // Calculate the time taken
    timeTaken = (endTime - startTime) / CLOCKS_PER_SEC;

    // Calculate the errors
    for (i = 0; i < strlen(target); i++) {
        if (input[i] != target[i]) {
            errors++;
        }
    }

    // Calculate the speed
    speed = (float)(strlen(target) - errors) / timeTaken;

    // Display the results
    printf("\nYour typing speed is: %.2f words per minute\n", speed);
    printf("You made %d errors.\n", errors);

    // Cheer the user up
    if (speed > 50) {
        printf("Wow, you're a typing wizard!\n");
    } else if (speed > 40) {
        printf("Not bad, keep practicing and you'll be a pro in no time!\n");
    } else {
        printf("Hey, don't give up! Practice makes perfect!\n");
    }

    return 0;
}