//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define a struct for elements in the periodic table
typedef struct {
    int atomic_number;
    char symbol[4];
    char name[MAX_NAME_LENGTH];
} element;

// Define an array of element struct to store all the elements in the periodic table
element periodic_table[] = {
    {1, "H", "Hydrogen"},
    {2, "He", "Helium"},
    {3, "Li", "Lithium"},
    {4, "Be", "Beryllium"},
    // ... other elements
    {118, "Og", "Oganesson"}
};

// Define the number of elements in the periodic table
const int num_of_elements = sizeof(periodic_table) / sizeof(periodic_table[0]);

// Define a function to get the element by its symbol
element* get_element_by_symbol(char symbol[]) {
    for (int i = 0; i < num_of_elements; i++) {
        if (strcmp(periodic_table[i].symbol, symbol) == 0) {
            return &periodic_table[i];
        }
    }
    return NULL;
}

int main() {
    char symbol[4];
    element* e = NULL;
    int correct_answers = 0;
    int total_questions = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter 'quit' to exit the quiz.\n");
    
    while (1) {
        printf("Enter the symbol of an element: ");
        scanf("%s", symbol);
        
        // Check if the user wants to quit
        if (strcmp(symbol, "quit") == 0) {
            break;
        }
        
        // Get the element by its symbol
        e = get_element_by_symbol(symbol);
        
        if (e == NULL) {
            printf("Sorry, '%s' is not a valid symbol.\n", symbol);
        } else {
            char name[MAX_NAME_LENGTH];
            printf("What is the name of %s? ", symbol);
            scanf("%s", name);
            total_questions++;
            if (strcmp(name, e->name) == 0) {
                printf("Correct!\n");
                correct_answers++;
            } else {
                printf("Sorry, the correct name is '%s'.\n", e->name);
            }
        }
    }
    
    // Print out the quiz results
    printf("Quiz results:\n");
    printf("Total questions: %d\n", total_questions);
    printf("Correct answers: %d\n", correct_answers);
    printf("Incorrect answers: %d\n", total_questions - correct_answers);
    
    return 0;
}