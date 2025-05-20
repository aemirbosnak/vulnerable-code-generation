//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <string.h>

// struct for elements
typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
} Element;

// function to initialize elements array
void initialize_elements(Element *elements) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomic_number = 3;

    // continuing with rest of the elements (up to Carbon/C)
}

// function for quiz
void periodic_table_quiz() {
    Element elements[118];
    initialize_elements(elements);
    int score = 0;
    int num_questions = 10;

    printf("Welcome to the Periodic Table Quiz! You will be presented with %d multiple choice questions.\n\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % 118;
        printf("Question %d:\n", i+1);
        printf("What is the symbol for %s?\n", elements[index].name);
        printf("a) %s\n", elements[(index+1)%118].symbol);
        printf("b) %s\n", elements[(index+2)%118].symbol);
        printf("c) %s\n\n", elements[index].symbol);

        char answer;
        printf("Enter your answer (a, b, or c): \n");
        scanf(" %c", &answer);

        if (answer == 'c') {
            printf("\nCongratulations! You got it right!\n\n");
            score++;
        } else {
            printf("\nSorry, that was incorrect. The answer was %c) %s.\n\n", 'c', elements[index].symbol);
        }
    }

    printf("\nYou scored %d out of %d!\n", score, num_questions);
}

// main function
int main() {
    periodic_table_quiz();

    return 0;
}