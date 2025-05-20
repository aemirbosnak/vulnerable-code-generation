//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum length of the element name and symbol
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Define a struct to hold an element's information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    double atomic_mass;
} element_t;

// Define a struct to hold user input for a quiz question
typedef struct {
    int atomic_number;
    char symbol[MAX_SYMBOL_LENGTH];
} quiz_question_t;

// Define an array of elements for the quiz
element_t elements[] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.003},
    {"Lithium", "Li", 3, 6.941},
    {"Beryllium", "Be", 4, 9.012},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.01},
    {"Nitrogen", "N", 7, 14.01},
    {"Oxygen", "O", 8, 16.00},
    {"Fluorine", "F", 9, 19.00},
    {"Neon", "Ne", 10, 20.18},
    {"Sodium", "Na", 11, 22.99},
    {"Magnesium", "Mg", 12, 24.31},
    {"Aluminum", "Al", 13, 26.98},
    {"Silicon", "Si", 14, 28.09},
    {"Phosphorus", "P", 15, 30.97},
    {"Sulfur", "S", 16, 32.06},
    {"Chlorine", "Cl", 17, 35.45},
    {"Argon", "Ar", 18, 39.95},
    {"Potassium", "K", 19, 39.10},
    {"Calcium", "Ca", 20, 40.08},
};

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare variables
    int num_questions = 0;
    int num_correct = 0;
    quiz_question_t* questions = NULL;
    char answer[MAX_SYMBOL_LENGTH];
    
    // Get the number of quiz questions from the user
    printf("How many quiz questions would you like to answer? ");
    scanf("%d", &num_questions);
    
    // Allocate memory for the quiz questions
    questions = (quiz_question_t*) malloc(num_questions * sizeof(quiz_question_t));
    
    // Generate random quiz questions
    for (int i = 0; i < num_questions; i++) {
        // Get a random element from the array
        element_t element = elements[rand() % (sizeof(elements) / sizeof(element_t))];
        
        // Create a quiz question from the element
        quiz_question_t question;
        question.atomic_number = element.atomic_number;
        strcpy(question.symbol, element.symbol);
        
        // Add the quiz question to the array
        questions[i] = question;
    }
    
    // Print the quiz questions
    printf("\n");
    for (int i = 0; i < num_questions; i++) {
        printf("%d. What is the symbol for element #%d? ", i + 1, questions[i].atomic_number);
        scanf("%s", &answer);
        if (strcmp(answer, questions[i].symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct symbol for element #%d is %s.\n", questions[i].atomic_number, questions[i].symbol);
        }
    }
    
    // Print the quiz results
    printf("\nYou answered %d out of %d questions correctly.\n", num_correct, num_questions);
    
    // Free the quiz questions memory
    free(questions);
    
    return 0;
}