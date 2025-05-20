//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define a struct to hold information about an element
typedef struct {
    int atomic_number;
    char symbol[3];
    char name[25];
    float atomic_weight;
} element_t;

// Define an array to hold all of the elements
element_t elements[MAX_ELEMENTS] = {
    {1,"H","Hydrogen",1.008},
    {2,"He","Helium",4.003},
    {3,"Li","Lithium",6.941},
    {4,"Be","Beryllium",9.012},
    // Rest of the elements ...
};

int main() {
    int num_questions, i, j, question_num, answer_num, correct_answers;
    char answer[3];

    // Seed the random number generator
    srand(time(NULL));

    // Ask the user how many questions they want to answer
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    // Generate that many random questions
    correct_answers = 0;
    for (i = 0; i < num_questions; i++) {
        // Choose a random element from the array
        question_num = rand() % MAX_ELEMENTS;

        // Print the question
        printf("What is the symbol for element %s? ", elements[question_num].name);

        // Get the user's answer
        scanf("%s", answer);

        // Check the answer against the correct symbol
        if (strcmp(answer, elements[question_num].symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", elements[question_num].symbol);
        }
    }

    // Print the user's score
    printf("You answered %d out of %d questions correctly.\n", correct_answers, num_questions);

    return 0;
}