//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
    char category[20];
} element;

int main() {

    element periodicTable[118];     // array of elements
    FILE * fptr;                    // file pointer
    int i = 0;                      // index variable for array
    char buffer[100];               // buffer to store current line from file

    // open file in read-only mode
    if ((fptr = fopen("periodic_table.csv", "r")) == NULL) {
        printf("Error opening file. Exiting program.\n");
        return 1;
    }

    // read each line from file and parse data into array of elements
    while (fgets(buffer, 100, fptr) != NULL) {
        sscanf(buffer, "%[A-Za-z],%[A-Za-z],%d,%[A-Za-z ]", periodicTable[i].symbol, periodicTable[i].name, &periodicTable[i].atomicNumber, periodicTable[i].category);
        i++;
    }

    // close file
    fclose(fptr);

    // quiz app to guess element based on atomic number
    int score = 0;              // number of correct guesses
    int totalQuestions = 0;     // total number of questions asked
    char userInput[10];         // buffer to store user input
    int guesses = 0;            // number of guesses for current question
    int numQuestions;           // number of questions user wants to answer
    int randomNumber;           // randomly generated atomic number
    int index;                  // index of corresponding element in periodicTable array

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want to attempt? Enter a number: ");
    scanf("%d", &numQuestions);

    // loop through the number of quiz questions
    for (int q = 0; q < numQuestions; q++) {
        guesses = 0;
        totalQuestions++;

        // generate random atomic number for current question
        randomNumber = (rand() % 118) + 1;

        // find the corresponding element in the array
        for (int j = 0; j < i; j++) {
            if (periodicTable[j].atomicNumber == randomNumber) {
                index = j;
                break;
            }
        }

        // loop through guesses for current question
        while (guesses < 3) {
            printf("Question %d\n", totalQuestions);
            printf("What element has an atomic number of %d?\n", randomNumber);
            printf("Guess %d: ", guesses+1);
            scanf("%s", userInput);

            // check if user input matches element symbol or element name
            if (strcmp(userInput, periodicTable[index].symbol) == 0 || strcmp(userInput, periodicTable[index].name) == 0) {
                printf("Correct!\n");
                score++;
                break;
            } else {
                printf("Incorrect. Please try again.\n");
                guesses++;
            }
        }

        // if user runs out of guesses for current question
        if (guesses == 3) {
            printf("Sorry, you ran out of guesses. The answer was %s.\n", periodicTable[index].name);
        }
    }

    // display final score
    printf("Quiz complete! You scored %d out of %d. Thanks for playing!\n", score, totalQuestions);

    return 0;
}