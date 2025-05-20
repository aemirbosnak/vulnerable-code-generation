//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTION_LENGTH 30
#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

typedef struct {
    char question[100];
    char options[4][MAX_OPTION_LENGTH];
    int correctOption;
} QuizQuestion;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

QuizQuestion questions[MAX_QUESTIONS] = {
    {"What is the chemical symbol for Oxygen?", {"O", "Ox", "Oz", "O2"}, 0},
    {"What is the atomic number of Carbon?", {"4", "6", "12", "8"}, 1},
    {"Which element is represented by the symbol 'He'?", {"Hydrogen", "Helium", "Hafnium", "Holmium"}, 1},
    {"Which of the following is a halogen?", {"Oxygen", "Fluorine", "Nitrogen", "Argon"}, 1},
    {"What is the common state of Nitrogen at room temperature?", {"Solid", "Liquid", "Gas", "Plasma"}, 2}
};

void displayWelcomeMessage() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge about the elements.\n\n");
}

void displayQuestion(QuizQuestion *q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q->question);
    for(int i = 0; i < 4; i++) {
        printf("  %d. %s\n", i + 1, q->options[i]);
    }
}

int getUserAnswer() {
    int answer;
    printf("Enter the option number (1-4): ");
    scanf("%d", &answer);
    return answer - 1; // Convert to 0-based index
}

void evaluateAnswer(int userAnswer, int correctAnswer, int *score) {
    if (userAnswer == correctAnswer) {
        printf("Correct!\n");
        (*score)++;
    } else {
        printf("Wrong! The correct answer was option %d.\n", correctAnswer + 1);
    }
    printf("\n");
}

void displayFinalScore(int score) {
    printf("Quiz Over! Your final score is: %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    int score = 0;

    srand(time(NULL));
    displayWelcomeMessage();

    for(int i = 0; i < MAX_QUESTIONS; i++) {
        int questionIndex = rand() % MAX_QUESTIONS; // Random questions
        displayQuestion(&questions[questionIndex], i);
        int userAnswer = getUserAnswer();
        evaluateAnswer(userAnswer, questions[questionIndex].correctOption, &score);
    }

    displayFinalScore(score);
    return 0;
}