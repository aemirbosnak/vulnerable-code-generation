//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // Maximum number of elements in the periodic table
#define MAX_QUESTIONS 10 // Maximum number of questions to ask in the quiz

struct Element {
    char name[10];
    char symbol[3];
    int atomicNumber;
    int category; // 1 = metal, 2 = nonmetal, 3 = metalloid
};

struct Element elements[MAX_ELEMENTS] = {
    { "Hydrogen", "H", 1, 1 },
    { "Helium", "He", 2, 1 },
    { "Lithium", "Li", 3, 1 },
    { "Beryllium", "Be", 4, 1 },
    { "Boron", "B", 5, 3 },
    { "Carbon", "C", 6, 3 },
    { "Nitrogen", "N", 7, 3 },
    { "Oxygen", "O", 8, 3 },
    { "Fluorine", "F", 9, 3 },
    { "Neon", "Ne", 10, 1 }
};

void shuffleArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int askQuestion(int numQuestions) {
    int correctAnswers = 0;
    for (int i = 0; i < numQuestions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol of %s?\n", i+1, elements[index].name);
        char input[3];
        scanf("%s", input);
        if (strcmp(input, elements[index].symbol) == 0) {
            correctAnswers++;
        }
    }
    return correctAnswers;
}

int main() {
    int numQuestions;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want to answer? (1 to %d)\n", MAX_QUESTIONS);
    scanf("%d", &numQuestions);
    int score = askQuestion(numQuestions);
    printf("\nYou got %d out of %d questions correct.\n", score, numQuestions);
    return 0;
}