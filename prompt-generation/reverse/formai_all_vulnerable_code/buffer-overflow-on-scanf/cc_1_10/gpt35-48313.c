//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    int random = (rand() % (max - min + 1)) + min;
    return random;
}

int main() {
    // configurable variables
    int numQuestions = 5; // number of questions for the exam
    int minAnswer = 1; // minimum answer value
    int maxAnswer = 10; // maximum answer value
    int passingGrade = 70; // passing grade percentage

    // initialize variables
    int question, answer, userAnswer, correctAnswer;
    int totalCorrect = 0; // number of correct answers
    float percentageCorrect;

    printf("Welcome to the Online Examination System\n");
    printf("You will be presented with %d questions\n", numQuestions);

    // loop through each question
    for (question = 1; question <= numQuestions; question++) {
        // generate random answer
        answer = generateRandomNumber(minAnswer, maxAnswer);
        
        // ask user for answer to question
        printf("\nQuestion %d: What is %d x %d?\n", question, answer, answer);
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        // calculate correct answer
        correctAnswer = answer * answer;

        // check if user answer is correct
        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            totalCorrect++;
        } else {
            printf("Incorrect. The correct answer is %d\n", correctAnswer);
        }
    }

    // calculate percentage of correct answers
    percentageCorrect = ((float)totalCorrect / numQuestions) * 100;

    // check if user passed exam
    if (percentageCorrect >= passingGrade) {
        printf("\nCongratulations! You passed the exam with a score of %.2f%%.\n", percentageCorrect);
    } else {
        printf("\nSorry, you did not pass the exam. Your score is %.2f%%.\n", percentageCorrect);
    }

    return 0;
}