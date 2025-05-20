//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numQuestions, correctAnswers = 0;
    char choice;
    struct tm startTime;
    time_t start, end;

    // Seed the random number generator
    srand(time(NULL));

    // Get the starting time
    time(&start);
    localtime_r(&start, &startTime);

    // Print the starting time
    printf("Quiz started at %d:%d:%d\n", startTime.tm_hour, startTime.tm_min, startTime.tm_sec);

    // Ask the user how many questions they want to answer
    printf("How many questions do you want to answer? ");
    scanf("%d", &numQuestions);

    // Loop through the desired number of questions
    for (int i = 0; i < numQuestions; i++) {
        // Generate a random element symbol
        char elementSymbol[3] = { 'A', 'a' + rand() % 26, '\0' };

        // Print the question
        printf("What is the symbol for element %s? ", elementSymbol);

        // Get the user's choice
        scanf(" %c", &choice);

        // Convert the choice to uppercase
        choice = toupper(choice);

        // Check if the user's choice is correct
        if (choice == elementSymbol[0]) {
            correctAnswers++;
        }
    }

    // Print the results
    printf("\nYou got %d out of %d correct.\n", correctAnswers, numQuestions);

    // Get the ending time
    time(&end);
    localtime_r(&end, &startTime);

    // Print the ending time
    printf("Quiz ended at %d:%d:%d\n", startTime.tm_hour, startTime.tm_min, startTime.tm_sec);

    return 0;
}