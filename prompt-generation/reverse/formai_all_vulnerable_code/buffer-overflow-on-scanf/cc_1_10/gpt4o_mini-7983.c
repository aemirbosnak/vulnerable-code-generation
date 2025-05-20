//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
} Element;

Element elements[MAX_ELEMENTS] = {
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

void quizUser() {
    int score = 0;
    
    printf("Periodic Table Quiz!\n");
    printf("Answer the following questions:\n\n");
    
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        char answer[3];

        printf("What is the symbol for %s? ", elements[i].name);
        fgets(answer, sizeof(answer), stdin);
        
        // Remove newline character from input
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n\n", elements[i].symbol);
        }
    }
    
    printf("You scored %d out of %d.\n", score, MAX_ELEMENTS);
}

void listElements() {
    printf("\nElements in the Periodic Table:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d: %s (Symbol: %s)\n", elements[i].atomicNumber, elements[i].name, elements[i].symbol);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("Periodic Table Application\n");
        printf("1. Take the Quiz\n");
        printf("2. List Elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                quizUser();
                break;
            case 2:
                listElements();
                break;
            case 3:
                printf("Exiting the application...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}