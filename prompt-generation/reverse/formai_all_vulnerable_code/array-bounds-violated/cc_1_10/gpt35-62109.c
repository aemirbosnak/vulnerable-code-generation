//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_elements(char* elements[], int size) {
    for(int i=0; i<size; i++) {
        printf("%s ", elements[i]);
    }
    printf("\n");
}

int main() {
    char* symbols[10] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
    char* names[10] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron",
                       "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
    int atomic_numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double atomic_weights[10] = {1.00794, 4.002602, 6.941, 9.012182, 10.81,
                                 12.01, 14.01, 16, 19, 20.18};

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You are Sherlock Holmes and you have to answer 10 questions.\n\n");

    printf("QUESTION 1:\n");
    printf("What is the symbol of the element with 8 protons? ");
    char answer[10];
    fgets(answer, 10, stdin);
    if(strcmp(answer, symbols[7]) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", symbols[7]);
    }

    printf("QUESTION 2:\n");
    printf("What is the name of the element with the symbol C? ");
    fgets(answer, 10, stdin);
    answer[strlen(answer)-1] = '\0'; // remove newline character
    if(strcmp(answer, names[5]) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", names[5]);
    }

    printf("QUESTION 3:\n");
    printf("What is the atomic number of the element with the symbol Na? ");
    fgets(answer, 10, stdin);
    int num_answer = atoi(answer);
    if(num_answer == atomic_numbers[10-3]) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %d.\n", atomic_numbers[10-3]);
    }

    printf("QUESTION 4:\n");
    printf("What is the atomic weight of the element with the symbol He? ");
    fgets(answer, 10, stdin);
    double weight_answer = atof(answer);
    if(abs(weight_answer - atomic_weights[1]) < 0.001) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %.2f.\n", atomic_weights[1]);
    }

    printf("QUESTION 5:\n");
    printf("Which of the following elements is a noble gas?\n");
    print_elements(symbols+5, 5);
    fgets(answer, 10, stdin);
    answer[strlen(answer)-1] = '\0'; // remove newline character
    if(strcmp(answer, symbols[9]) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", symbols[9]);
    }

    printf("QUESTION 6:\n");
    printf("What is the name of the element with 3 electrons in its outer shell? ");
    fgets(answer, 10, stdin);
    answer[strlen(answer)-1] = '\0'; // remove newline character
    if(strcmp(answer, names[2]) == 0) {
        printf("Correct!\n");
    } else if(strcmp(answer, names[3]) == 0) { // alternate correct answer
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s or %s.\n", names[2], names[3]);
    }

    printf("QUESTION 7:\n");
    printf("What is the symbol of the element with the highest atomic number?\n");
    fgets(answer, 10, stdin);
    answer[strlen(answer)-1] = '\0'; // remove newline character
    if(strcmp(answer, symbols[9]) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", symbols[9]);
    }

    printf("QUESTION 8:\n");
    printf("What is the atomic number of the element with 10 electrons in its second shell? ");
    fgets(answer, 10, stdin);
    num_answer = atoi(answer);
    if(num_answer == atomic_numbers[10-2]) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %d.\n", atomic_numbers[10-2]);
    }

    printf("QUESTION 9:\n");
    printf("What is the name of the lightest halogen? ");
    fgets(answer, 10, stdin);
    answer[strlen(answer)-1] = '\0'; // remove newline character
    if(strcmp(answer, names[8]) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", names[8]);
    }

    printf("QUESTION 10:\n");
    printf("What is the atomic weight of the element with the symbol Br? ");
    fgets(answer, 10, stdin);
    weight_answer = atof(answer);
    if(abs(weight_answer - atomic_weights[9]) < 0.001) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %.2f.\n", atomic_weights[9]);
    }

    printf("\nCongratulations, you have completed the quiz!\n");
    return 0;
}