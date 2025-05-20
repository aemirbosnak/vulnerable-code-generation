//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

// Structure to hold element data
typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
} Element;

// Function declarations
void initializeElements(Element elements[]);
void displayElements(Element elements[], int count);
void quizUser(Element elements[], int count);
void provideHints(Element element);

int main() {
    Element elements[MAX_ELEMENTS];

    // Initialize element data
    initializeElements(elements);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be prompted to guess the attributes of elements.\n");
    quizUser(elements, MAX_ELEMENTS);

    return 0;
}

// Initialize periodic table elements
void initializeElements(Element elements[]) {
    elements[0] = (Element){1, "Hydrogen", "H", 1.008};
    elements[1] = (Element){2, "Helium", "He", 4.0026};
    elements[2] = (Element){3, "Lithium", "Li", 6.94};
    // [Add additional elements as needed, truncated for brevity]
    elements[117] = (Element){118, "Oganesson", "Og", 294.2};
}

// Function to display all elements
void displayElements(Element elements[], int count) {
    printf("\nPeriodic Table Elements:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (%s), Atomic Weight: %.2f\n",
                elements[i].atomicNumber,
                elements[i].name,
                elements[i].symbol,
                elements[i].atomicWeight);
    }
}

// Quiz functionality
void quizUser(Element elements[], int count) {
    int score = 0;
    char answer[MAX_NAME_LENGTH];
    int index;
    char answerType;

    for (int i = 0; i < 5; i++) { // Quiz for 5 random elements
        index = rand() % count; // Random index from 0 to count-1

        // Randomly choose whether to ask for name, symbol, or atomic weight
        answerType = "nsa"[rand() % 3]; // n = name, s = symbol, a = atomic weight
        if (answerType == 'n') {
            printf("\nWhat is the name of the element with atomic number %d?\n", elements[index].atomicNumber);
            printf("Your Answer: ");
            scanf("%s", answer);
            if (strcmp(answer, elements[index].name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %s.\n", elements[index].name);
                provideHints(elements[index]);
            }
        } else if (answerType == 's') {
            printf("\nWhat is the symbol of the element with atomic number %d?\n", elements[index].atomicNumber);
            printf("Your Answer: ");
            scanf("%s", answer);
            if (strcmp(answer, elements[index].symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %s.\n", elements[index].symbol);
                provideHints(elements[index]);
            }
        } else {
            printf("\nWhat is the atomic weight of %s? (to 2 decimal places)\n", elements[index].name);
            printf("Your Answer: ");
            float userAnswer;
            scanf("%f", &userAnswer);
            if (fabs(userAnswer - elements[index].atomicWeight) < 0.01) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %.2f.\n", elements[index].atomicWeight);
                provideHints(elements[index]);
            }
        }
    }
    printf("\nYour total score is: %d out of 5\n", score);
}

// Provide hints based on element attributes
void provideHints(Element element) {
    printf("Hints:\n");
    printf(" - Atomic Number: %d\n", element.atomicNumber);
    printf(" - Symbol: %s\n", element.symbol);
    if (element.atomicWeight < 10) {
        printf(" - Atomic Weight is less than 10.\n");
    } else if (element.atomicWeight < 50) {
        printf(" - Atomic Weight is between 10 and 50.\n");
    } else {
        printf(" - Atomic Weight is greater than 50.\n");
    }
}