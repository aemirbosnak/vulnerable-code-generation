//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    int atomicNumber;
    char name[30];
    char symbol[3];
    float atomicWeight;
} Element;

void initializeElements(Element elements[]) {
    // A few example elements for demonstration
    elements[0] = (Element){1, "Hydrogen", "H", 1.008};
    elements[1] = (Element){2, "Helium", "He", 4.0026};
    elements[2] = (Element){3, "Lithium", "Li", 6.94};
    elements[3] = (Element){4, "Beryllium", "Be", 9.0122};
    elements[4] = (Element){5, "Boron", "B", 10.81};
    elements[5] = (Element){6, "Carbon", "C", 12.011};
    // Add more elements as desired...
}

void displayElement(Element element) {
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Weight: %.4f\n", element.atomicWeight);
}

void quizUser(Element elements[]) {
    int score = 0;
    int totalQuestions = 5; // Sample size for quiz
    int askedQuestions = 0;

    while (askedQuestions < totalQuestions) {
        int randomIndex = rand() % MAX_ELEMENTS;

        // Ensure the element exists and is initialized
        if (elements[randomIndex].atomicNumber != 0) {
            printf("Question %d: What is the symbol for %s? ", askedQuestions + 1, elements[randomIndex].name);
            char userAnswer[3];
            scanf("%s", userAnswer);

            if (strcmp(userAnswer, elements[randomIndex].symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %s.\n", elements[randomIndex].symbol);
            }
            askedQuestions++;
        }
    }

    printf("You got %d out of %d questions correct.\n", score, totalQuestions);
}

int main() {
    srand(time(0));
    Element elements[MAX_ELEMENTS] = {0};
    
    initializeElements(elements);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of chemical elements.\n\n");
    
    quizUser(elements);

    printf("Thank you for playing!\n");
    return 0;
}