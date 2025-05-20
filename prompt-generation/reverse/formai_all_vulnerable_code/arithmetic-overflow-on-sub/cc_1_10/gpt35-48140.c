//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENTS 118

// Element structure
typedef struct {
    char name[20];
    int atomic_number;
    char symbol[3];
    float atomic_weight;
} Element;

// Initialize array of elements
void initialize_elements(Element elements[MAX_ELEMENTS]);

int main() {
    // Variable declaration
    int i, j, k, answer, num_questions, correct_answers;
    char choice;
    Element elements[MAX_ELEMENTS];
    
    // Initialize array of elements
    initialize_elements(elements);
    
    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");
    
    // Prompt user for number of questions
    printf("How many questions would you like to answer? (1-10): ");
    scanf("%d", &num_questions);
    
    // Check if number of questions is valid
    if (num_questions < 1 || num_questions > 10) {
        printf("Invalid number of questions. Please try again.\n");
        return 0;
    }
    
    // Loop through questions
    correct_answers = 0;
    for (i = 0; i < num_questions; i++) {
        // Randomly select an element from the array
        j = rand() % MAX_ELEMENTS;
        
        // Print question and answer choices
        printf("Question #%d: What is the atomic number of %s?\n", i + 1, elements[j].name);
        printf("A. %d\tB. %d\tC. %d\tD. %d\n", elements[j].atomic_number - 1, elements[j].atomic_number, elements[j].atomic_number + 1, elements[j].atomic_number + 2);
        
        // Get user's answer choice
        printf("Enter your answer (A, B, C, or D): ");
        fflush(stdin); // Clear input buffer to prevent skipping questions
        scanf("%c", &choice);
        
        // Check if user's choice is valid
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
            printf("Invalid choice. Skipping question...\n\n");
            continue;
        }
        
        // Convert user's choice to integer value
        switch (choice) {
            case 'A':
                answer = elements[j].atomic_number - 1;
                break;
            case 'B':
                answer = elements[j].atomic_number;
                break;
            case 'C':
                answer = elements[j].atomic_number + 1;
                break;
            case 'D':
                answer = elements[j].atomic_number + 2;
                break;
        }
        
        // Check if user's answer is correct
        if (answer == elements[j].atomic_number) {
            printf("Correct!\n\n");
            correct_answers++;
        } else {
            printf("Sorry, the correct answer was %d.\n\n", elements[j].atomic_number);
        }
    }
    
    // Print final score
    printf("Quiz complete! You scored %d out of %d.\n", correct_answers, num_questions);
    
    return 0;
}

void initialize_elements(Element elements[MAX_ELEMENTS]) {
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_weight = 1.008;
    
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;
    strcpy(elements[1].symbol, "He");
    elements[1].atomic_weight = 4.003;
    
    // Add more elements...
}