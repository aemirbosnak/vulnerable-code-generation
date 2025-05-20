//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 5

typedef struct {
    char symbol[3];
    int atomicNumber;
    char name[30];
} Element;

void introScreen();
void quiz();
void populateArray(Element *elementArray);
Element *generateQuestion(Element *elementArray, int *usedIndices, int index);
int chooseRandomIndex(int *usedIndices);
int checkAnswer(Element *element, char *answer);
void endScreen(int score);

int main() {
    introScreen();
    quiz();
    return 0;
}

void introScreen() {
    printf("Welcome to the C Periodic Table Quiz!\n"
           "You will be given %d random elements to identify by their symbols, names or atomic numbers.\n"
           "You will receive 1 point for each correct answer and 0 points for each incorrect answer.\n"
           "Let's get started!\n\n", NUM_QUESTIONS);
}

void quiz() {
    srand(time(NULL)); //seed random generator with current time
    int i, score = 0;
    int usedIndices[NUM_ELEMENTS] = {0}; //initialize all array elements to 0
    Element elementArray[NUM_ELEMENTS];
    populateArray(elementArray);
    for (i = 0; i < NUM_QUESTIONS; i++) {
        Element *question = generateQuestion(elementArray, usedIndices, i);
        char answer[30];
        printf("Question %d: What is the ", i+1);
        int questionType = rand() % 3; //randomly choose question type
        switch(questionType) {
            case 0:
                printf("symbol for the element with atomic number %d?\n", question->atomicNumber);
                scanf("%s", answer);
                if (checkAnswer(question, answer)) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The answer was %s.\n", question->symbol);
                }
                break;
            case 1:
                printf("name for the element with atomic number %d?\n", question->atomicNumber);
                scanf("%s", answer);
                if (checkAnswer(question, answer)) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The answer was %s.\n", question->name);
                }
                break;
            case 2:
                printf("atomic number for the element with symbol %s?\n", question->symbol);
                scanf("%s", answer);
                if (checkAnswer(question, answer)) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The answer was %d.\n", question->atomicNumber);
                }
                break;
        }
        printf("\n");
    }
    endScreen(score); //display score and end of quiz message
}

void populateArray(Element *elementArray) {
    FILE *fp;
    fp = fopen("periodic_table.txt", "r"); //open file for reading
    if (fp == NULL) {
        printf("Error opening periodic_table.txt file.\n");
        exit(1);
    }
    int i = 0;
    char tempSymbol[3], tempName[30];
    int tempAtomicNumber;
    while (fscanf(fp, "%s %d %s\n", tempSymbol, &tempAtomicNumber, tempName) == 3) { //read data from file
        strcpy(elementArray[i].symbol, tempSymbol); //copy data to struct array
        elementArray[i].atomicNumber = tempAtomicNumber;
        strcpy(elementArray[i].name, tempName);
        i++;
    }
    fclose(fp); //close file
}

Element *generateQuestion(Element *elementArray, int *usedIndices, int index) {
    int randomIndex = chooseRandomIndex(usedIndices);
    usedIndices[index] = randomIndex; //mark index as used
    return &elementArray[randomIndex];
}

int chooseRandomIndex(int *usedIndices) {
    int randomIndex;
    do {
        randomIndex = rand() % NUM_ELEMENTS; //generate random integer
    } while (usedIndices[randomIndex] != 0); //loop until unused index is found
    return randomIndex;
}

int checkAnswer(Element *element, char *answer) {
    if (strcmp(answer, element->symbol) == 0 
        || strcmp(answer, element->name) == 0 
        || atoi(answer) == element->atomicNumber) { //check if answer matches any of the possible correct answers
        return 1;
    }
    return 0;
}

void endScreen(int score) {
    printf("Congratulations on completing the quiz!\n"
           "Your score is %d out of %d. Thanks for playing!\n", score, NUM_QUESTIONS);
}