//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the structure for each element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    char category[10];
} Element;

// Function to generate a random element
Element getRandomElement() {
    Element element;
    element.atomic_number = rand() % NUM_ELEMENTS + 1;
    switch(element.atomic_number) {
        case 1:
            strcpy(element.symbol, "H");
            strcpy(element.name, "Hydrogen");
            strcpy(element.category, "Nonmetal");
            break;
        case 2:
            strcpy(element.symbol, "He");
            strcpy(element.name, "Helium");
            strcpy(element.category, "Noble gas");
            break;
        case 6:
            strcpy(element.symbol, "C");
            strcpy(element.name, "Carbon");
            strcpy(element.category, "Nonmetal");
            break;
        case 7:
            strcpy(element.symbol, "N");
            strcpy(element.name, "Nitrogen");
            strcpy(element.category, "Nonmetal");
            break;
        case 8:
            strcpy(element.symbol, "O");
            strcpy(element.name, "Oxygen");
            strcpy(element.category, "Nonmetal");
            break;
        // Add more cases for other elements
    }
    return element;
}

// Function to print the periodic table
void printPeriodicTable() {
    Element element;
    int i, j;
    for(i=0; i<NUM_ELEMENTS; i++) {
        element = getRandomElement();
        printf("%-4s %-20s %d %-10s\n", element.symbol, element.name, element.atomic_number, element.category);
    }
}

// Function to quiz the user on the periodic table
void quiz() {
    char answer[20];
    int correct_answers = 0;
    int total_questions = 5;
    Element element;
    srand(time(NULL));
    while(total_questions > 0) {
        element = getRandomElement();
        printf("What is the symbol for element %d? ", element.atomic_number);
        scanf("%s", answer);
        if(strcmp(answer, element.symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element.symbol);
        }
        total_questions--;
    }
    printf("You got %d out of %d correct.\n", correct_answers, total_questions);
}

int main() {
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Print the periodic table\n");
        printf("2. Take a quiz\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printPeriodicTable();
                break;
            case 2:
                quiz();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(1);
    return 0;
}