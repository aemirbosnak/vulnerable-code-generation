//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct for periodic table elements */
struct Element {
    int atomicNum;
    char name[20];
    char symbol[3];
    float atomicWeight;
};

/* Define array of struct Element for periodic table */
struct Element periodicTable[118] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.003},
    {3, "Lithium", "Li", 6.941},
    /* ... Rest of the elements organized by atomic number */
    {118, "Oganesson", "Og", 294},
};

int main() {
    int numQuestions = 10; // Number of quiz questions
    int score = 0; // Counter for correct answers
    int questionNum, answerNum; // Variables for tracking current question and user's answer input
    char answer[3]; // Input buffer for user's answer
    struct Element currentElement; // Struct for current quiz element
    
    // Seed random number generator
    srand(time(NULL));
    
    // Print welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given %d multiple-choice questions.\n", numQuestions);
    printf("Select the correct element symbol (e.g. H for Hydrogen) for each atomic number.\n\n");
    
    // Loop through the quiz questions
    for (int i = 0; i < numQuestions; i++) {
        // Get a random atomic number for the current question
        questionNum = rand() % 118 + 1;
        
        // Get the element associated with the current question number
        currentElement = periodicTable[questionNum-1];
        
        // Print the question and answer options
        printf("Question %d: What is the symbol for element %d?\n", i+1, questionNum);
        printf("A) %s\n", periodicTable[rand() % 118].symbol); // Random option A
        printf("B) %s\n", periodicTable[rand() % 118].symbol); // Random option B
        printf("C) %s\n", periodicTable[rand() % 118].symbol); // Random option C
        printf("D) %s\n", currentElement.symbol); // Correct answer D
        
        // Get the user's answer
        printf("Enter your answer (A, B, C, or D): ");
        scanf("%s", answer);
        printf("\n");
        
        // Check if the user's answer is correct
        if (strcmp(answer, "D") == 0 || strcmp(answer, "d") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", currentElement.symbol);
        }
    }
    
    // Print final score and exit
    printf("\nThank you for taking the quiz!\n");
    printf("Your final score is %d out of %d.\n", score, numQuestions);
    
    return 0; 
}