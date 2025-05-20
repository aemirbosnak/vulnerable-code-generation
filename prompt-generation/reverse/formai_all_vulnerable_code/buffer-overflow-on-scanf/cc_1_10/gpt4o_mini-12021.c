//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_QUESTIONS 5

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

typedef struct {
    char question[100];
    char answer[20];
} Question;

Element elements[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10}
};

Question questions[MAX_QUESTIONS] = {
    {"What is the atomic number of Hydrogen?", "1"},
    {"What is the chemical symbol for Oxygen?", "O"},
    {"What element has the atomic number 4?", "Be"},
    {"What is the most abundant element in the universe?", "H"},
    {"Which element is represented by the symbol 'C'?", "Carbon"}
};

void displayMenu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Start Quiz\n");
    printf("2. Show Elements\n");
    printf("3. Exit\n");
}

void showElements() {
    printf("Elements in the Periodic Table:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("Atomic Number: %d, Symbol: %s, Name: %s\n", 
                elements[i].atomicNumber, elements[i].symbol, elements[i].name);
    }
}

void startQuiz() {
    int score = 0;
    char userAnswer[20];

    printf("Starting the Quiz! Answer the following questions:\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        printf("Your answer: ");
        scanf("%s", userAnswer);
        
        if (strcasecmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The correct answer is: %s\n", questions[i].answer);
        }
    }
    printf("Your final score: %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                startQuiz();
                break;
            case 2:
                showElements();
                break;
            case 3:
                printf("Exiting the quiz. Thank you for participating!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}