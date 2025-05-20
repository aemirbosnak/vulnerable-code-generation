//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
} Element;

Element elements[NUM_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void shuffleArray(int *array, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quizUser(int index) {
    int correctAnswer;
    printf("What is the atomic number of %s (%s)? ", elements[index].name, elements[index].symbol);
    scanf("%d", &correctAnswer);
    if (correctAnswer == elements[index].atomicNumber) {
        printf("Correct! Well done.\n");
    } else {
        printf("Oops! The correct atomic number is %d.\n", elements[index].atomicNumber);
    }
}

void startQuiz() {
    int indexes[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        indexes[i] = i;
    }

    shuffleArray(indexes, NUM_ELEMENTS);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked about the atomic numbers of elements.\n\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        quizUser(indexes[i]);
    }

    printf("\nThank you for playing!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nPeriodic Table Quiz:\n");
        printf("1. Start Quiz\n");
        printf("2. Exit\n");
        printf("Choose an option (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            startQuiz();
        } else if (choice == 2) {
            printf("Exiting the quiz. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please choose 1 or 2.\n");
        }
    }

    return 0;
}