//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomicWeight;
    char category[MAX_NAME_LENGTH];
} Element;

// Function prototypes
void initializePeriodicTable(Element elements[]);
void displayQuiz(Element elements[], int numQuestions);
void askQuestion(Element element);
int getAnswer(char *expectedAnswer);
void toLowerCase(char *str);

int main() {
    Element elements[MAX_ELEMENTS];
    int numQuestions = 10; // Number of questions to ask

    initializePeriodicTable(elements);
    displayQuiz(elements, numQuestions);

    return 0;
}

void initializePeriodicTable(Element elements[]) {
    // Fill in the first few elements for the sake of demonstration
    elements[0] = (Element) {1, "Hydrogen", "H", 1.008, "Non-metal"};
    elements[1] = (Element) {2, "Helium", "He", 4.0026, "Noble gas"};
    elements[2] = (Element) {3, "Lithium", "Li", 6.94, "Alkali metal"};
    elements[3] = (Element) {4, "Beryllium", "Be", 9.0122, "Alkaline earth metal"};
    elements[4] = (Element) {5, "Boron", "B", 10.81, "Metalloid"};
    elements[5] = (Element) {6, "Carbon", "C", 12.011, "Non-metal"};
    elements[6] = (Element) {7, "Nitrogen", "N", 14.007, "Non-metal"};
    elements[7] = (Element) {8, "Oxygen", "O", 15.999, "Non-metal"};
    elements[8] = (Element) {9, "Fluorine", "F", 18.998, "Non-metal"};
    elements[9] = (Element) {10, "Neon", "Ne", 20.180, "Noble gas"};
    // Add more elements as needed...
}

void displayQuiz(Element elements[], int numQuestions) {
    int askedQuestions = 0;
    int totalElements = 10; // For simplicity, limiting to the first 10 elements
    int selectedIndices[10] = {0};
    int i, index, answeredCorrectly;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", numQuestions);

    while (askedQuestions < numQuestions) {
        // Select a random element that hasn't been asked
        int unique = 0;
        while (!unique) {
            index = rand() % totalElements;
            // Check if the index has already been used
            int alreadyAsked = 0;
            for (i = 0; i < askedQuestions; i++) {
                if (selectedIndices[i] == index) {
                    alreadyAsked = 1;
                    break;
                }
            }
            if (!alreadyAsked) {
                unique = 1;
                selectedIndices[askedQuestions] = index;
            }
        }
        askQuestion(elements[index]);
        askedQuestions++;
    }

    printf("Thank you for participating in the quiz!\n");
}

void askQuestion(Element element) {
    char userAnswer[MAX_NAME_LENGTH];
    
    printf("Question: What is the symbol of %s? ", element.name);
    scanf("%s", userAnswer);
    
    // Normalize the case of the user input
    toLowerCase(userAnswer);
    toLowerCase(element.symbol);

    if (getAnswer(userAnswer) == getAnswer(element.symbol)) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct symbol is %s.\n", element.symbol);
    }
}

int getAnswer(char *expectedAnswer) {
    // Simply return the answer as an integer to compare
    int answer = 0;
    for (int i = 0; expectedAnswer[i] != '\0'; i++) {
        answer += expectedAnswer[i];
    }
    return answer;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}