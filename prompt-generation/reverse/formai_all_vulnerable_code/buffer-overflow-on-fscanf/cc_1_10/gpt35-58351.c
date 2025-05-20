//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118  // number of elements in the periodic table
#define NUM_COLS 3  // number of columns to display element information
#define MAX_GUESSES 3  // maximum number of guesses for each element

// function to print the header of the periodic table
void printHeader() {
    printf("%-3s%-15s%-15s%-15s\n", "No.", "Symbol", "Name", "Atomic Mass");
}

// function to print the information of an element
void printElement(int n, char symbol[3], char name[15], float mass) {
    printf("%-3d%-15s%-15s%-15.2f\n", n, symbol, name, mass);
}

// function to check if two strings are equal, ignoring case
bool stringEqualIgnoreCase(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return false;
        }
    }
    return (s1[i] == '\0' && s2[i] == '\0');
}

// function to generate a random integer between a and b
int randInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    // variables to store element information
    int number[NUM_ELEMENTS];
    char symbol[NUM_ELEMENTS][3];
    char name[NUM_ELEMENTS][15];
    float mass[NUM_ELEMENTS];
    
    // populate arrays with element information from file
    FILE* file = fopen("elements.txt", "r");
    int i;
    for (i = 0; i < NUM_ELEMENTS; i++) {
        fscanf(file, "%d %s %s %f", &number[i], symbol[i], name[i], &mass[i]);
    }
    fclose(file);
    
    // seed random number generator
    srand(time(NULL));
    
    // welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    
    // get user input
    int numQuestions;
    printf("How many elements would you like to be tested on (1-%d): ", NUM_ELEMENTS);
    scanf("%d", &numQuestions);
    
    // validate user input
    if (numQuestions < 1 || numQuestions > NUM_ELEMENTS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", NUM_ELEMENTS);
        return 1;
    }
    
    // shuffle elements array
    for (i = 0; i < NUM_ELEMENTS; i++) {
        int j = randInt(i, NUM_ELEMENTS - 1);
        int tempNum = number[i];
        char tempSymbol[3];
        char tempName[15];
        float tempMass = mass[i];
        number[i] = number[j];
        strcpy(tempSymbol, symbol[i]);
        strcpy(tempName, name[i]);
        mass[i] = mass[j];
        number[j] = tempNum;
        strcpy(symbol[i], symbol[j]);
        strcpy(name[i], name[j]);
        mass[j] = tempMass;
        strcpy(symbol[j], tempSymbol);
        strcpy(name[j], tempName);
    }
    
    // loop through questions
    int score = 0;
    for (i = 1; i <= numQuestions; i++) {
        int randIndex = randInt(0, NUM_ELEMENTS - 1);
        int numGuesses = 0;
        bool correct = false;
        printf("\nElement %d/%d: ", i, numQuestions);
        
        // loop through guesses
        while (!correct && numGuesses < MAX_GUESSES) {
            char guess[15];
            printf("What is the symbol of %s? ", name[randIndex]);
            scanf("%s", guess);
            
            // check if guess is correct
            if (stringEqualIgnoreCase(guess, symbol[randIndex])) {
                printf("Correct!\n");
                correct = true;
                score++;
            } else {
                printf("Incorrect. Try again.\n");
                numGuesses++;
            }
        }
        
        // if no correct guesses, reveal the answer
        if (!correct) {
            printf("The correct answer was %s.\n", symbol[randIndex]);
        }
    }
    
    // display final score
    printf("\nCongratulations, you scored %d/%d!\n", score, numQuestions);
    
    return 0;
}