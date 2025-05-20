//FormAI DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int questions[10][5]; // a 2D array to store the 10 questions and their corresponding 4 options and correct answer
    int chosenAnswers[10]; // an array to store the user's chosen answers
    int correctAnswers = 0; // a counter to keep track of the number of correct answers
    int i, j;

    // seed the random number generator
    srand(time(NULL));

    // generate the 10 questions and their options
    for (i = 0; i < 10; i++) {
        // generate a random question between 1 and 5
        int question = rand() % 5 + 1;

        // assign the question
        questions[i][0] = question;

        // generate options A, B, C, and D
        for (j = 1; j < 5; j++) {
            questions[i][j] = rand() % 4 + 1;
        }

        // determine the correct answer
        switch (question) {
            case 1:
                questions[i][5] = 2; // the correct answer is B
                break;
            case 2:
                questions[i][5] = 3; // the correct answer is C
                break;
            case 3:
                questions[i][5] = 1; // the correct answer is A
                break;
            case 4:
                questions[i][5] = 4; // the correct answer is D
                break;
            case 5:
                questions[i][5] = 2; // the correct answer is B
                break;
        }
    }

    // start the exam
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with 10 multiple choice questions.\n");
    printf("Please enter the letter of your chosen answer (A, B, C, or D):\n");

    // ask and store the user's answers to the questions
    for (i = 0; i < 10; i++) {
        printf("Question %d: What is the capital of France?\n", i+1);
        printf("A. London\n");
        printf("B. Paris\n");
        printf("C. Berlin\n");
        printf("D. Madrid\n");
        printf("Answer: ");
        char answer;
        scanf(" %c", &answer);
        while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
            printf("Please enter a valid answer (A, B, C, or D): ");
            scanf(" %c", &answer);
        }
        switch (answer) {
            case 'A':
                chosenAnswers[i] = 1;
                break;
            case 'B':
                chosenAnswers[i] = 2;
                break;
            case 'C':
                chosenAnswers[i] = 3;
                break;
            case 'D':
                chosenAnswers[i] = 4;
                break;
        }
    }

    // grade the exam
    for (i = 0; i < 10; i++) {
        if (chosenAnswers[i] == questions[i][5]) {
            correctAnswers++;
        }
    }

    // display the user's score
    printf("Your score is %d out of 10.\n", correctAnswers);

    return 0;
}