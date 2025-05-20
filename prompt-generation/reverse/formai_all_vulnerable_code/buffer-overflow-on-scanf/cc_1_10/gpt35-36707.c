//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding element data
typedef struct {
    int atomic_num;
    char name[20];
    char symbol[3];
    float atomic_weight;
} element;

// Function for displaying quiz questions and getting user answers
int takeQuiz(element *elements, int num_elements) {
    int score = 0;
    // Loop through elements and ask a question for each
    for (int i = 0; i < num_elements; i++) {
        printf("Question %d:\n", i+1);
        printf("What is the atomic number of %s?\n", elements[i].name);
        // Get user input
        int answer;
        scanf("%d", &answer);
        // Check if answer is correct
        if (answer == elements[i].atomic_num) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d.\n", elements[i].atomic_num);
        }
    }
    return score;
}

int main() {
    // Create an array of element objects
    element elements[10];
    // Set element data
    elements[0].atomic_num = 1;
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_weight = 1.008;

    elements[1].atomic_num = 2;
    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomic_weight = 4.003;

    elements[2].atomic_num = 3;
    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomic_weight = 6.941;

    elements[3].atomic_num = 4;
    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomic_weight = 9.012;

    elements[4].atomic_num = 5;
    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomic_weight = 10.81;

    elements[5].atomic_num = 6;
    strcpy(elements[5].name, "Carbon");
    strcpy(elements[5].symbol, "C");
    elements[5].atomic_weight = 12.01;

    elements[6].atomic_num = 7;
    strcpy(elements[6].name, "Nitrogen");
    strcpy(elements[6].symbol, "N");
    elements[6].atomic_weight = 14.01;

    elements[7].atomic_num = 8;
    strcpy(elements[7].name, "Oxygen");
    strcpy(elements[7].symbol, "O");
    elements[7].atomic_weight = 16.00;

    elements[8].atomic_num = 9;
    strcpy(elements[8].name, "Fluorine");
    strcpy(elements[8].symbol, "F");
    elements[8].atomic_weight = 19.00;

    elements[9].atomic_num = 10;
    strcpy(elements[9].name, "Neon");
    strcpy(elements[9].symbol, "Ne");
    elements[9].atomic_weight = 20.18;

    // Call takeQuiz function to start quiz
    printf("Welcome to the Periodic Table Quiz!\n");
    int score = takeQuiz(elements, 10);
    printf("Quiz complete! You scored %d out of 10.\n", score);

    return 0;
}