//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

// Define a structure to hold information about an element
typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_mass;
} Element;

// Declare an array to hold information about all elements
Element elements[NUM_ELEMENTS] = {
    // hydrogen
    {"H", "Hydrogen", 1, 1.008},
    // helium
    {"He", "Helium", 2, 4.003},
    // ...
};

// Declare a function to quiz the user on the periodic table
void quiz();

int main() {
    // Welcome the user and explain the quiz
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("This quiz will ask you questions about the elements of the periodic table.\n");
    
    // Run the quiz
    quiz();
    
    // Exit the program
    return 0;
}

void quiz() {
    // Declare variables to keep track of user's score and current question
    int score = 0;
    int question = 0;
    
    // Loop through all elements and ask a question about each one
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // Increment the question number
        question++;
        
        // Print the question
        printf("Question %d: What is the symbol of %s?\n", question, elements[i].name);
        
        // Declare a buffer to hold the user's response
        char response[3];
        
        // Read the user's response from the console
        scanf("%s", response);
        
        // Check if the response is correct
        if (strcmp(response, elements[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The symbol of %s is %s.\n", elements[i].name, elements[i].symbol);
        }
    }
    
    // Print the user's final score
    printf("Quiz complete! You got %d out of %d questions correct.\n", score, NUM_ELEMENTS);
}