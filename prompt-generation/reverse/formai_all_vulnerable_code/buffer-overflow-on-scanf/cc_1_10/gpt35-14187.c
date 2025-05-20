//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random atomic number
int getRandomElement() {
    srand(time(NULL));
    return rand() % 118 + 1; // There are 118 elements in the periodic table
}

// Function to get the corresponding element symbol for a given atomic number
char* getSymbol(int atomic_number) {
    switch(atomic_number) {
        case 1:
            return "H";
        case 2:
            return "He";
        case 3:
            return "Li";
        // more cases for all the elements in the periodic table...
        default:
            return "Invalid";
    }
}

int main() {
    int number_of_questions = 5; // Number of questions in the quiz
    int score = 0; // Initialize score to 0
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be given %d questions to answer.\n",number_of_questions);
    for(int i=0;i<number_of_questions;i++) {
        // Generate a random atomic number
        int atomic_number = getRandomElement();
        // Get the corresponding element symbol
        char* symbol = getSymbol(atomic_number);
        // Ask the question
        printf("\nQuestion %d:\n",i+1);
        printf("What is the element symbol for atomic number %d?\n",atomic_number);
        // Get the user's answer
        char answer[3];
        scanf("%s",answer);
        // Check if the answer is correct
        if(strcmp(answer,symbol)==0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n",symbol);
        }
    }
    // Display the final score
    printf("\nQuiz complete!\n");
    printf("You scored %d out of %d.\n",score,number_of_questions);
    return 0;
}