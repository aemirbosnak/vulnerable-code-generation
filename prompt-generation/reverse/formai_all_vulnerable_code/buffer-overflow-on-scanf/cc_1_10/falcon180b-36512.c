//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_ATTEMPTS 10 // maximum number of attempts per question
#define CORRECT_SCORE 1 // score for a correct answer
#define INCORRECT_SCORE 0 // score for an incorrect answer

// structure to represent an element in the periodic table
typedef struct {
    char symbol[3]; // chemical symbol (e.g. "H" for hydrogen)
    char name; // element name (e.g. "hydrogen")
    int atomic_number; // atomic number (e.g. 1 for hydrogen)
} Element;

// function to generate a random element from the periodic table
Element generateRandomElement() {
    Element element;
    element.symbol[0] = 'A' + rand() % 26; // generate a random uppercase letter for the symbol
    element.symbol[1] = 'A' + rand() % 26;
    element.symbol[2] = '\0';
    element.name = 'A' + rand() % 26; // generate a random uppercase letter for the name
    element.atomic_number = rand() % MAX_ELEMENTS + 1; // generate a random atomic number between 1 and the maximum number of elements
    return element;
}

// function to print an element from the periodic table
void printElement(Element element) {
    printf("Symbol: %s\n", element.symbol);
    printf("Name: %c\n", element.name);
    printf("Atomic number: %d\n", element.atomic_number);
}

// function to ask a question about an element in the periodic table
int askQuestion(Element element) {
    char input[MAX_ELEMENTS];
    int score = 0;

    printf("Question: What is the symbol for %s?\n", element.name);
    scanf("%s", input);

    if (strcmp(input, element.symbol) == 0) {
        score = CORRECT_SCORE;
    } else {
        score = INCORRECT_SCORE;
    }

    return score;
}

// function to play the periodic table quiz game
void playGame() {
    Element element;
    int attempts = 0;
    int score = 0;

    srand(time(NULL)); // seed the random number generator with the current time

    while (attempts < MAX_ATTEMPTS) {
        element = generateRandomElement();
        printElement(element);

        score += askQuestion(element);
        attempts++;
    }

    printf("Your final score is: %d\n", score);
}

int main() {
    playGame();
    return 0;
}