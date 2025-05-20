//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random characters
char randChar() {
    char c = (char)(rand() % 26 + 65); // Generate a random uppercase letter
    return c;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("\n*** Welcome to the Typing Speed Test! ***\n\n");
    printf("You will be given a string of random uppercase letters to type.\n");
    printf("To begin, press enter!\n\n");
    getchar(); // Wait for the user to press enter

    char testString[51]; // Declare an array to hold the test string
    for (int i = 0; i < 50; i++) { // Generate a string of 50 random uppercase letters
        testString[i] = randChar();
    }
    testString[50] = '\0'; // Add null terminator at the end of the string

    printf("Your typing test starts now:\n\n");
    printf("%s\n\n", testString); // Display the test string

    clock_t start = clock(); // Record the start time
    
    char inputString[51]; // Declare an array to hold the user's input
    fgets(inputString, sizeof(inputString), stdin); // Get user's input string

    clock_t end = clock(); // Record the end time

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the time taken in seconds
    int numOfMistakes = 0; // Initialize the number of mistakes made to 0

    for (int i = 0; i < strlen(testString); i++) {
        if (testString[i] != inputString[i]) {
            numOfMistakes++; // Increment the number of mistakes made
        }
    }

    printf("\nTime taken: %.2lf seconds\n", timeTaken);
    printf("Number of mistakes: %d\n", numOfMistakes);

    if (timeTaken < 10 && numOfMistakes == 0) { // Cheerful message for those who type fast with no errors
        printf("Congratulations! You're a super fast typist with no mistakes!\n");
    }
    else if (timeTaken < 15 && numOfMistakes <= 3) { // Cheerful message for those who type fast with a few errors
        printf("Great job! You're a fast typist with just a few mistakes!\n");
    }
    else { // Cheerful message for everyone else
        printf("Good effort! Keep practicing to improve your typing speed!\n");
    }

    return 0;
}