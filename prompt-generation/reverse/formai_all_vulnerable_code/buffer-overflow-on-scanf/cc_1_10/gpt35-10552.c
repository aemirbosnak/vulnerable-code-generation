//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
} Element;

// Function to print the periodic table
void printPeriodicTable(Element *elements) {
    printf("==============================================\n");
    printf("    C Periodic Table Quiz - All Elements\n");
    printf("==============================================\n");
    printf("Symbol\t Name\t\t Atomic Number\t Atomic Mass\n");
    printf("------------------------------------------------\n");

    for(int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%s\t %-15s\t %d\t\t %.4f\n", elements[i].symbol, elements[i].name, elements[i].atomic_number, elements[i].atomic_mass);
    }
}

// Function to generate a random number
int getRandomNumber(int lower, int upper) {
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to shuffle the array of elements
void shuffleElements(Element *elements) {
    for(int i = NUM_ELEMENTS - 1; i > 0; i--) {
        int j = getRandomNumber(0, i);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Function to take quiz
void takeQuiz(Element *elements, int num_questions) {
    int correct_answers = 0;

    printf("==============================================\n");
    printf("         C Periodic Table Quiz - Quiz\n");
    printf("==============================================\n");

    for(int i = 0; i < num_questions; i++) {
        int element_index = getRandomNumber(0, NUM_ELEMENTS-1);
        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i+1, elements[element_index].atomic_number);

        char user_answer[3];
        scanf("%s", user_answer);

        if(strcmp(user_answer, elements[element_index].symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        }
        else {
            printf("Incorrect. The correct answer is %s.\n", elements[element_index].symbol);
        }
    }

    float percentage = (float)correct_answers/(float)num_questions*100;
    printf("\nYou answered %d out of %d questions correctly. (%.2f%)\n", correct_answers, num_questions, percentage);
}

int main() {
    Element elements[NUM_ELEMENTS] = {
        {"H", "Hydrogen", 1, 1.008},
        {"He", "Helium", 2, 4.0026},
        {"Li", "Lithium", 3, 6.94},
        // ... rest of the elements go here
        {"Og", "Oganesson", 118, 294.21}
    };

    int choice;
    do {
        printf("==============================================\n");
        printf("         C Periodic Table Quiz - Main Menu\n");
        printf("==============================================\n");
        printf("1. Print the periodic table\n");
        printf("2. Take a quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printPeriodicTable(elements);
                break;

            case 2:
                shuffleElements(elements);
                int num_questions;
                printf("\nEnter the number of questions (between 1 and %d): ", NUM_ELEMENTS);
                scanf("%d", &num_questions);
                takeQuiz(elements, num_questions);
                break;

            case 3:
                printf("\nThank you for using the C Periodic Table Quiz!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please choose from the menu.\n");
                break;
        }
        printf("\n");
    } while(choice != 3);

    return 0;
}