//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 3

// Represents a single element in the periodic table
typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    float atomicMass;
} Element;

// Initializes an array of elements with data from a file
void initializeElements(Element* elements, const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", fileName);
        exit(EXIT_FAILURE);
    }

    // Read each line of the file and create a corresponding element
    int atomicNumber;
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    float atomicMass;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (fscanf(file, "%d,%[^,],%[^,],%f\n", &atomicNumber, name, symbol, &atomicMass) != 4) {
            printf("Error: invalid file format\n");
            exit(EXIT_FAILURE);
        }
        Element element = { atomicNumber, "", "", 0.0f };
        strncpy(element.name, name, MAX_NAME_LEN);
        strncpy(element.symbol, symbol, MAX_SYMBOL_LEN);
        element.atomicMass = atomicMass;
        elements[i] = element;
    }

    fclose(file);
}

// Prints the details of a single element
void printElement(const Element* element) {
    printf("%-2d %-20s %-2s %8.4f\n", element->atomicNumber, element->name, element->symbol, element->atomicMass);
}

// Runs a quiz on the periodic table
void periodicTableQuiz(const Element* elements, int numQuestions) {
    printf("Welcome to the periodic table quiz!\n");
    printf("You will be asked %d questions about the elements.\n", numQuestions);

    int correctAnswers = 0;
    for (int i = 0; i < numQuestions; i++) {
        // Randomly select an element for the question
        int index = rand() % MAX_ELEMENTS;
        const Element* element = &elements[index];

        // Print the question
        printf("\nQuestion %d:\n", i+1);
        printf("What is the atomic number of the element '%s' with symbol '%s'? ", element->name, element->symbol);

        // Read the user's answer and validate it
        int userAnswer;
        if (scanf("%d", &userAnswer) != 1) {
            printf("Error: invalid input\n");
            exit(EXIT_FAILURE);
        }
        if (userAnswer == element->atomicNumber) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d\n", element->atomicNumber);
        }
    }

    // Calculate and report the quiz score
    float score = (float) correctAnswers / numQuestions * 100;
    printf("\nCongratulations, you scored %.2f%% on the quiz!\n", score);
}

int main() {
    // Initialize the array of elements
    Element elements[MAX_ELEMENTS];
    initializeElements(elements, "elements.csv");

    // Seed the random number generator
    srand((unsigned int) time(NULL));

    // Run the quiz
    periodicTableQuiz(elements, 10);

    return 0;
}