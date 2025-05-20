//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ATOMIC_SYMBOL_SIZE 3
#define ELEMENT_NAME_SIZE 30

struct element {
    char atomic_symbol[ATOMIC_SYMBOL_SIZE];
    char name[ELEMENT_NAME_SIZE];
    int atomic_number;
    float atomic_weight;
};

typedef struct element Element;

Element periodic_table[] = {  // Array of structs containing periodic table information
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.01},
    {"N", "Nitrogen", 7, 14.01},
    {"O", "Oxygen", 8, 16.00},
    {"F", "Fluorine", 9, 19.00},
    {"Ne", "Neon", 10, 20.18},
    {"Na", "Sodium", 11, 22.99},
    {"Mg", "Magnesium", 12, 24.31},
    {"Al", "Aluminum", 13, 26.98},
    {"Si", "Silicon", 14, 28.09},
    {"P", "Phosphorus", 15, 30.97},
    {"S", "Sulfur", 16, 32.07},
    {"Cl", "Chlorine", 17, 35.45},
    {"Ar", "Argon", 18, 39.95},
    {"K", "Potassium", 19, 39.10},
    {"Ca", "Calcium", 20, 40.08}
};

int main() {
    int correct_answers = 0;
    int incorrect_answers = 0;
    char input[ATOMIC_SYMBOL_SIZE];
    int total_questions = sizeof(periodic_table) / sizeof(Element);
    srand(time(NULL));  // Seed random number generator with current time
    
    printf("Welcome to the Periodic Table quiz!\n\n");
    printf("You will be given a chemical symbol and must provide the element's name.\n");
    printf("There are %d questions in total. Good luck!\n\n", total_questions);
    
    for (int i = 0; i < total_questions; i++) {
        int random_index = rand() % total_questions;  // Choose a random index from the array
        Element current_element = periodic_table[random_index];
        
        printf("Question %d:\n", i+1);
        printf("What element has the chemical symbol %s?\n", current_element.atomic_symbol);
        printf("Enter your answer: ");
        fgets(input, ATOMIC_SYMBOL_SIZE+1, stdin);  // Read input from user
        
        // Remove trailing newline character from user input
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }
        
        // Check if user's input is correct
        if (strcmp(input, current_element.name) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else {
            printf("Incorrect. The correct answer is %s.\n\n", current_element.name);
            incorrect_answers++;
        }
    }
    
    // Display final score
    printf("Quiz complete!\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);
    float percentage = ((float)correct_answers / total_questions) * 100;
    printf("Your overall score was %.2f%%.\n", percentage);
    
    return 0;
}