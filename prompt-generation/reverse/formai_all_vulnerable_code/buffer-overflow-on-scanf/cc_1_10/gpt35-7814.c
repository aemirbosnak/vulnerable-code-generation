//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 10

// Define element struct
typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// Function prototypes
void add_element(Element* elements, int* num_elements);
void display_table(Element* elements, int num_elements);
void take_quiz(Element* elements, int num_elements);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create array of elements
    Element elements[NUM_ELEMENTS];
    int num_elements = 0;
    
    // Display menu options
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add element to table\n");
        printf("2. Display periodic table\n");
        printf("3. Take quiz on periodic table\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_element(elements, &num_elements);
                break;
            case 2:
                display_table(elements, num_elements);
                break;
            case 3:
                take_quiz(elements, num_elements);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

// Function to add a new element to the array
void add_element(Element* elements, int* num_elements) {
    // Check if array is full
    if (*num_elements == NUM_ELEMENTS) {
        printf("Periodic table is full!\n");
        return;
    }
    
    // Get user input for new element
    printf("Enter symbol: ");
    scanf("%s", elements[*num_elements].symbol);
    printf("Enter name: ");
    scanf("%s", elements[*num_elements].name);
    printf("Enter atomic number: ");
    scanf("%d", &elements[*num_elements].atomic_number);
    
    // Increment number of elements
    (*num_elements)++;
}

// Function to display the periodic table
void display_table(Element* elements, int num_elements) {
    // Print headers
    printf("\n%-5s%-20s%s\n", "Symbol", "Name", "Atomic Number");
    
    // Loop through elements and print information
    for (int i = 0; i < num_elements; i++) {
        printf("%-5s%-20s%d\n", elements[i].symbol, elements[i].name, elements[i].atomic_number);
    }
}

// Function to take a quiz on the periodic table
void take_quiz(Element* elements, int num_elements) {
    // Set up variables for quiz
    int num_questions = 10;
    char user_answer[3];
    int total_correct = 0;
    
    // Loop through quiz questions
    for (int i = 0; i < num_questions; i++) {
        // Get random element from table
        int random_index = rand() % num_elements;
        Element random_element = elements[random_index];
        
        // Print question
        printf("\nQuestion %d: What is the symbol for %s?\n", i+1, random_element.name);
        
        // Get user input
        scanf("%s", user_answer);
        
        // Check if user answer is correct
        if (strcmp(user_answer, random_element.symbol) == 0) {
            printf("Correct!\n");
            total_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", random_element.symbol);
        }
    }
    
    // Print quiz results
    printf("\nQuiz complete! You got %d out of %d.\n", total_correct, num_questions);
}