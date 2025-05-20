//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printQuestion(int questionNum, int answer);
void printIntro();
void printEnd(int correctAnswers, int totalQuestions);

int main() {
    int totalQuestions = 10;
    int correctAnswers = 0;
    int answer;

    printIntro();

    //Question 1
    printQuestion(1, 1);
    scanf("%d", &answer);
    if (answer == 3) {
        correctAnswers++;
    }

    //Question 2
    printQuestion(2, 2);
    scanf("%d", &answer);
    if (answer == 18) {
        correctAnswers++;
    }

    //Question 3
    printQuestion(3, 3);
    scanf("%d", &answer);
    if (answer == 6) {
        correctAnswers++;
    }

    //Question 4
    printQuestion(4, 4);
    scanf("%d", &answer);
    if (answer == 8) {
        correctAnswers++;
    }

    //Question 5
    printQuestion(5, 5);
    scanf("%d", &answer);
    if (answer == 50) {
        correctAnswers++;
    }

    //Question 6
    printQuestion(6, 6);
    scanf("%d", &answer);
    if (answer == 17) {
        correctAnswers++;
    }

    //Question 7
    printQuestion(7, 7);
    scanf("%d", &answer);
    if (answer == 26) {
        correctAnswers++;
    }

    //Question 8
    printQuestion(8, 8);
    scanf("%d", &answer);
    if (answer == 16) {
        correctAnswers++;
    }

    //Question 9
    printQuestion(9, 9);
    scanf("%d", &answer);
    if (answer == 13) {
        correctAnswers++;
    }

    //Question 10
    printQuestion(10, 10);
    scanf("%d", &answer);
    if (answer == 34) {
        correctAnswers++;
    }

    printEnd(correctAnswers, totalQuestions);
    return 0;
}

void printQuestion(int questionNum, int answer) {
    printf("Question %d: What is the atomic number of ", questionNum);

    if (answer == 1) {
        printf("Hydrogen?\n");
    } else if (answer == 2) {
        printf("Argon?\n");
    } else if (answer == 3) {
        printf("Carbon?\n");
    } else if (answer == 4) {
        printf("Oxygen?\n");
    } else if (answer == 5) {
        printf("Tin?\n");
    } else if (answer == 6) {
        printf("Chlorine?\n");
    } else if (answer == 7) {
        printf("Iron?\n");
    } else if (answer == 8) {
        printf("Sulfur?\n");
    } else if (answer == 9) {
        printf("Aluminum?\n");
    } else if (answer == 10) {
        printf("Germanium?\n");
    } else {
        printf("unknown element?\n");
    }
}

void printIntro() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked 10 questions about the atomic number of different elements.\n");
    printf("Please type your answer and hit enter.\n");
}

void printEnd(int correctAnswers, int totalQuestions) {
    printf("Quiz ended! You got %d out of %d correct answers.\n", correctAnswers, totalQuestions);
    printf("Thank you for playing the Periodic Table Quiz! Goodbye!\n");
}