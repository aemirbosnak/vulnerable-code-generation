//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
/*
 * Dennis Ritchie style C Periodic Table Quiz example program
 * --------------------------------------
 * Author: [Your Name]
 * Date:  [Date]
 * --------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare and initialize variables
    char element[50];
    char symbol[50];
    int numElements = 0;
    int numSymbols = 0;
    int numQuizzes = 0;
    int quizScore = 0;
    int userInput;

    // Prompt user to enter number of quizzes
    printf("Enter the number of quizzes you want to play: ");
    scanf("%d", &numQuizzes);

    // Loop through each quiz
    for (int i = 0; i < numQuizzes; i++) {
        // Initialize quiz score to 0
        quizScore = 0;

        // Loop through each element
        for (int j = 0; j < numElements; j++) {
            // Prompt user to enter element
            printf("Enter the element %d: ", j + 1);
            scanf("%s", element);

            // Prompt user to enter symbol
            printf("Enter the symbol for element %s: ", element);
            scanf("%s", symbol);

            // Check if user input matches correct symbol
            if (strcmp(element, symbol) == 0) {
                printf("Correct!\n");
                quizScore++;
            } else {
                printf("Incorrect!\n");
            }
        }

        // Print quiz score
        printf("Quiz %d: Score = %d\n", i + 1, quizScore);

        // Update number of quizzes and elements
        numElements += numElements;
        numSymbols += numSymbols;
    }

    return 0;
}