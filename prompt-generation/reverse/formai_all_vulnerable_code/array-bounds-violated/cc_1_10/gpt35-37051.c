//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define number of elements in periodic table
#define NUM_ELEMENTS 118

// define structure for element properties
typedef struct ELEM_PROPS {
    char symbol[3];
    char name[30];
    int atomic_num;
    float atomic_weight;
    char electron_config[30];
} elem_props;

// define array of element properties
elem_props elements[NUM_ELEMENTS];

// function to populate array of element properties
void initialize_elements() {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_num = 1;
    elements[0].atomic_weight = 1.008;
    strcpy(elements[0].electron_config, "1s1");

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_num = 2;
    elements[1].atomic_weight = 4.003;
    strcpy(elements[1].electron_config, "1s2");

    // continue initializing rest of array up to element 118...
}

// function to present quiz questions and return user's answer
int get_user_answer(char *symbol) {
    printf("What is the atomic number of %s?\n", symbol);
    int user_answer;
    scanf("%d", &user_answer);
    return user_answer;
}

// function to check if user's answer is correct and present feedback
void check_answer(char *symbol, int user_answer) {
    int correct_answer = elements[user_answer-1].atomic_num;
    if (user_answer == correct_answer) {
        printf("Correct! The atomic number of %s is %d.\n", symbol, correct_answer);
    } else {
        printf("Incorrect. The atomic number of %s is %d.\n", symbol, correct_answer);
    }
}

// main function to execute periodic table quiz
int main() {
    // initialize array of element properties
    initialize_elements();

    // loop through each element and present quiz question
    for (int i=0; i<NUM_ELEMENTS; i++) {
        char *symbol = elements[i].symbol;
        int user_answer = get_user_answer(symbol);
        check_answer(symbol, user_answer);
    }

    printf("Congratulations! You have completed the periodic table quiz.\n");

    return 0;
}