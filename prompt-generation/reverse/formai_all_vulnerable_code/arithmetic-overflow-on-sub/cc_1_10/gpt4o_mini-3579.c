//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_OPTION_LENGTH 50

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    char options[4][MAX_OPTION_LENGTH];
    int correctOption;
} Element;

void setupElements(Element elements[]) {
    // Setup a small sample of elements for the quiz
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;
    strcpy(elements[0].options[0], "G");
    strcpy(elements[0].options[1], "H");
    strcpy(elements[0].options[2], "He");
    strcpy(elements[0].options[3], "O");
    elements[0].correctOption = 1;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;
    strcpy(elements[1].options[0], "H");
    strcpy(elements[1].options[1], "He");
    strcpy(elements[1].options[2], "Ne");
    strcpy(elements[1].options[3], "Xe");
    elements[1].correctOption = 1;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomicNumber = 3;
    strcpy(elements[2].options[0], "Li");
    strcpy(elements[2].options[1], "Na");
    strcpy(elements[2].options[2], "K");
    strcpy(elements[2].options[3], "Cs");
    elements[2].correctOption = 0;

    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomicNumber = 4;
    strcpy(elements[3].options[0], "Be");
    strcpy(elements[3].options[1], "Mg");
    strcpy(elements[3].options[2], "Ca");
    strcpy(elements[3].options[3], "Sr");
    elements[3].correctOption = 0;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomicNumber = 5;
    strcpy(elements[4].options[0], "C");
    strcpy(elements[4].options[1], "B");
    strcpy(elements[4].options[2], "N");
    strcpy(elements[4].options[3], "F");
    elements[4].correctOption = 1;

    // Add more elements as needed to reach MAX_ELEMENTS
}

void displayQuestion(Element elem, int questionNumber) {
    printf("Question %d: What is the symbol for %s (Atomic Number: %d)?\n", 
        questionNumber + 1, elem.name, elem.atomicNumber);
    for (int i = 0; i < 4; i++) {
        printf("%d: %s\n", i + 1, elem.options[i]);
    }
}

int getAnswer() {
    int answer;
    printf("Your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1; // Convert to zero-based index
}

int main() {
    Element elements[MAX_ELEMENTS];
    setupElements(elements);

    int score = 0;
    int totalQuestions = 5; // Update based on how many elements are added
    printf("Welcome to the Periodic Table Quiz!\n");

    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(elements[i], i);
        int userAnswer = getAnswer();

        if (userAnswer == elements[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", elements[i].options[elements[i].correctOption]);
        }
        printf("\n");
    }

    printf("Quiz Complete! Your score: %d out of %d\n", score, totalQuestions);

    return 0;
}