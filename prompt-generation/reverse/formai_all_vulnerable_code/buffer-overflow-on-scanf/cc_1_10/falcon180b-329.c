//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Function prototypes
void generateQuiz(int numQuestions);
int getRandomElement();
char* getElementName(int element);
char* getElementSymbol(int element);

int main() {
    int numQuestions;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of questions
    printf("Enter the number of questions (1-100): ");
    scanf("%d", &numQuestions);

    // Generate the quiz
    generateQuiz(numQuestions);

    return 0;
}

void generateQuiz(int numQuestions) {
    int i, correctAnswers = 0;
    char answer[3];

    // Loop through the number of questions
    for (i = 0; i < numQuestions; i++) {
        // Generate a random element
        int element = getRandomElement();

        // Print the question
        printf("Question %d: What is the symbol for element %d?\n", i+1, element);

        // Read the answer from the user
        scanf(" %s", answer);

        // Check if the answer is correct
        if (strcmp(answer, getElementSymbol(element)) == 0) {
            correctAnswers++;
        }
    }

    // Print the results
    printf("\nYou got %d out of %d questions correct.\n", correctAnswers, numQuestions);
}

int getRandomElement() {
    return rand() % MAX_ELEMENTS + 1;
}

char* getElementName(int element) {
    // Map the element number to its name
    switch(element) {
        case 1: return "Hydrogen";
        case 2: return "Helium";
        //...
        default: return "Unknown";
    }
}

char* getElementSymbol(int element) {
    // Map the element number to its symbol
    switch(element) {
        case 1: return "H";
        case 2: return "He";
        //...
        default: return "?";
    }
}