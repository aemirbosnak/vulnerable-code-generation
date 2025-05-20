//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Structure to hold element information
typedef struct {
    int atomicNumber;
    char name[20];
    char symbol[3];
    double atomicWeight;
} Element;

// Function declarations
void displayElement(Element elem);
void displayQuizInstructions();
int getRandomElementIndex();
void populateElements(Element elements[]);
void quizUser(Element elements[]);

int main() {
    Element elements[MAX_ELEMENTS];

    // Populate the elements array with data
    populateElements(elements);

    // Display instructions
    displayQuizInstructions();

    // Start the periodic table quiz
    quizUser(elements);
    
    return 0;
}

void populateElements(Element elements[]) {
    // Sample data for elements (just a few for demonstration)
    elements[0] = (Element){1, "Hydrogen", "H", 1.008};
    elements[1] = (Element){2, "Helium", "He", 4.0026};
    elements[2] = (Element){3, "Lithium", "Li", 6.94};
    elements[3] = (Element){4, "Beryllium", "Be", 9.0122};
    elements[4] = (Element){5, "Boron", "B", 10.81};
    elements[5] = (Element){6, "Carbon", "C", 12.011};
    elements[6] = (Element){7, "Nitrogen", "N", 14.007};
    elements[7] = (Element){8, "Oxygen", "O", 15.999};
    elements[8] = (Element){9, "Fluorine", "F", 18.998};
    elements[9] = (Element){10, "Neon", "Ne", 20.180};
    // ... (More elements can be added here)
}

void displayElement(Element elem) {
    printf("\nElement: %s (%s)\n", elem.name, elem.symbol);
    printf("Atomic Number: %d\n", elem.atomicNumber);
    printf("Atomic Weight: %.3f\n", elem.atomicWeight);
}

void displayQuizInstructions() {
    printf("Periodic Table Quiz Instructions:\n");
    printf("1. You will be quizzed on the names or symbols of elements.\n");
    printf("2. A random element will be chosen and you will have to provide the correct answer.\n");
    printf("3. Try to get as many as you can correct!\n");
    printf("4. Type 'exit' at any time to finish the quiz.\n\n");
}

int getRandomElementIndex() {
    return rand() % MAX_ELEMENTS; 
}

void quizUser(Element elements[]) {
    char answer[3];
    
    while (1) {
        int index = getRandomElementIndex();
        Element selectedElement = elements[index];

        printf("What is the symbol of the element with atomic number %d? ", selectedElement.atomicNumber);
        scanf("%s", answer);

        if (strcmp(answer, "exit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (strcasecmp(answer, selectedElement.symbol) == 0) {
            printf("Correct! The symbol of %s is %s.\n", selectedElement.name, selectedElement.symbol);
        } else {
            printf("Incorrect. The correct answer is %s.\n", selectedElement.symbol);
        }
    }
}