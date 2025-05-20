//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 20 // The number of elements to quiz
#define MAX_QUIZ_QUESTIONS 5 // Number of questions in one quiz

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

// Function declarations
void initializeElements(Element elements[]);
void askQuizQuestion(Element elements[], int questionIndex);
void shuffleQuestions(int indices[], int size);
int compare(const void *a, const void *b);

int main() {
    Element elements[MAX_ELEMENTS];
    int questionIndices[MAX_QUIZ_QUESTIONS];
    int score = 0;
    srand(time(0)); // Seed for random number generation
        
    initializeElements(elements);

    // Shuffle questions
    for (int i = 0; i < MAX_QUIZ_QUESTIONS; i++) {
        questionIndices[i] = i;
    }
    shuffleQuestions(questionIndices, MAX_QUIZ_QUESTIONS);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the first %d elements.\n", MAX_QUIZ_QUESTIONS, MAX_ELEMENTS);
    
    // Ask quiz questions
    for (int i = 0; i < MAX_QUIZ_QUESTIONS; i++) {
        askQuizQuestion(elements, questionIndices[i]);
        score++;
    }

    printf("You completed the quiz! Your score: %d/%d\n", score, MAX_QUIZ_QUESTIONS);
    
    return 0;
}

void initializeElements(Element elements[]) {
    // Initialize an array of elements
    strcpy(elements[0].name, "Hydrogen");   elements[0].symbol[0] = 'H'; elements[0].symbol[1] = '\0'; elements[0].atomicNumber = 1;
    strcpy(elements[1].name, "Helium");     elements[1].symbol[0] = 'He'; elements[1].symbol[1] = '\0'; elements[1].atomicNumber = 2;
    strcpy(elements[2].name, "Lithium");    elements[2].symbol[0] = 'Li'; elements[2].symbol[1] = '\0'; elements[2].atomicNumber = 3;
    strcpy(elements[3].name, "Beryllium");  elements[3].symbol[0] = 'Be'; elements[3].symbol[1] = '\0'; elements[3].atomicNumber = 4;
    strcpy(elements[4].name, "Boron");      elements[4].symbol[0] = 'B'; elements[4].symbol[1] = '\0'; elements[4].atomicNumber = 5;
    strcpy(elements[5].name, "Carbon");     elements[5].symbol[0] = 'C'; elements[5].symbol[1] = '\0'; elements[5].atomicNumber = 6;
    strcpy(elements[6].name, "Nitrogen");   elements[6].symbol[0] = 'N'; elements[6].symbol[1] = '\0'; elements[6].atomicNumber = 7;
    strcpy(elements[7].name, "Oxygen");     elements[7].symbol[0] = 'O'; elements[7].symbol[1] = '\0'; elements[7].atomicNumber = 8;
    strcpy(elements[8].name, "Fluorine");   elements[8].symbol[0] = 'F'; elements[8].symbol[1] = '\0'; elements[8].atomicNumber = 9;
    strcpy(elements[9].name, "Neon");       elements[9].symbol[0] = 'Ne'; elements[9].symbol[1] = '\0'; elements[9].atomicNumber = 10;
    strcpy(elements[10].name, "Sodium");    elements[10].symbol[0] = 'Na'; elements[10].symbol[1] = '\0'; elements[10].atomicNumber = 11;
    strcpy(elements[11].name, "Magnesium"); elements[11].symbol[0] = 'Mg'; elements[11].symbol[1] = '\0'; elements[11].atomicNumber = 12;
    strcpy(elements[12].name, "Aluminum");  elements[12].symbol[0] = 'Al'; elements[12].symbol[1] = '\0'; elements[12].atomicNumber = 13;
    strcpy(elements[13].name, "Silicon");   elements[13].symbol[0] = 'Si'; elements[13].symbol[1] = '\0'; elements[13].atomicNumber = 14;
    strcpy(elements[14].name, "Phosphorus"); elements[14].symbol[0] = 'P'; elements[14].symbol[1] = '\0'; elements[14].atomicNumber = 15;
    strcpy(elements[15].name, "Sulfur");    elements[15].symbol[0] = 'S'; elements[15].symbol[1] = '\0'; elements[15].atomicNumber = 16;
    strcpy(elements[16].name, "Chlorine");  elements[16].symbol[0] = 'Cl'; elements[16].symbol[1] = '\0'; elements[16].atomicNumber = 17;
    strcpy(elements[17].name, "Argon");     elements[17].symbol[0] = 'Ar'; elements[17].symbol[1] = '\0'; elements[17].atomicNumber = 18;
    strcpy(elements[18].name, "Potassium");  elements[18].symbol[0] = 'K'; elements[18].symbol[1] = '\0'; elements[18].atomicNumber = 19;
    strcpy(elements[19].name, "Calcium");   elements[19].symbol[0] = 'Ca'; elements[19].symbol[1] = '\0'; elements[19].atomicNumber = 20;
}

void askQuizQuestion(Element elements[], int questionIndex) {
    char answer[20];
    int userAns;
    
    printf("Question %d: What is the name of the element with the symbol '%s' and atomic number %d?\n", 
            questionIndex + 1, elements[questionIndex].symbol, elements[questionIndex].atomicNumber);
    
    printf("Your Answer: ");
    scanf("%s", answer);
    
    // Compare answers
    if (strcasecmp(answer, elements[questionIndex].name) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n\n", elements[questionIndex].name);
    }
}

void shuffleQuestions(int indices[], int size) {
    // Shuffle the question indices array
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}