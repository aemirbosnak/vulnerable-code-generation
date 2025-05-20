//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions
#define NUM_QUESTIONS 10

// Define the elements and their corresponding symbols
char* elements[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
char* symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};

// Define the questions
char* questions[] = {"What element has the symbol 'H'?", "What element has the symbol 'He'?", "What element has the symbol 'Li'?", "What element has the symbol 'Be'?", "What element has the symbol 'B'?", "What element has the symbol 'C'?", "What element has the symbol 'N'?", "What element has the symbol 'O'?", "What element has the symbol 'F'?", "What element has the symbol 'Ne'?"};

// Define the number of attempts and the correct answers
int attempts = 0;
int correctAnswers = 0;

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Loop through the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Print the question
        printf("%s\n", questions[i]);

        // Get the user's answer
        char answer[100];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, symbols[i]) == 0) {
            // Print a success message
            printf("Correct!\n");

            // Increment the correct answers counter
            correctAnswers++;
        } else {
            // Print an incorrect message
            printf("Incorrect. The correct answer is '%s'.\n", symbols[i]);

            // Increment the attempts counter
            attempts++;
        }
    }

    // Print the results
    printf("You got %d out of %d correct.\n", correctAnswers, NUM_QUESTIONS);

    return 0;
}