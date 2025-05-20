//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
// C Periodic Table Quiz

#include <stdio.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the elements and their properties
struct element {
    char name[30];
    char symbol[10];
    int atomic_number;
    int atomic_weight;
    char group;
};

// Function to display the periodic table
void display_periodic_table(struct element elements[NUM_ELEMENTS]) {
    printf("\n");
    printf("+----+-----------------+------+--------+\n");
    printf("| #  | Element          | Symbol | Atomic Number | Atomic Weight |\n");
    printf("+----+-----------------+------+--------+\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("| %3d | %-25s | %-10s | %4d | %4d |\n", i+1, elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_weight);
    }

    printf("+----+-----------------+------+--------+\n");
}

// Function to ask a question and check the answer
void ask_question(struct element elements[NUM_ELEMENTS], int num_questions, int current_question) {
    printf("\n");
    printf("Question %d of %d:\n", current_question+1, num_questions);
    printf("What is the name of the element with symbol '%s'?\n", elements[current_question].symbol);

    char answer[30];
    scanf("%s", answer);

    if (strcmp(answer, elements[current_question].name) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is '%s'.\n", elements[current_question].name);
    }
}

// Main function
int main() {

    // Define the elements and their properties
    struct element elements[NUM_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008, 'A'},
        {"Helium", "He", 2, 4.003, 'A'},
        {"Lithium", "Li", 3, 6.941, 'A'},
        // Add more elements here...
    };

    // Define the number of questions to ask
    int num_questions = 10;

    // Ask the questions
    for (int i = 0; i < num_questions; i++) {
        ask_question(elements, num_questions, i);
    }

    // Display the periodic table
    display_periodic_table(elements);

    return 0;
}