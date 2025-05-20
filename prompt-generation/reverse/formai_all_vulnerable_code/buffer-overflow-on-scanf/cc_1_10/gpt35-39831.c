//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Hello, %s! Please wait while we generate your exam...\n\n", name);
    srand(time(0)); // Seed the random number generator with the current time
    int numQuestions = 5; // Let's have five questions in each exam
    int correctAnswers = 0; // Keep track of how many the user gets right
    for(int i = 0; i < numQuestions; i++){
        int a = rand() % 101; // Generate a random number between 0 and 100
        int b = rand() % 101;
        char operator;
        int answer;
        switch(rand() % 4){ // Randomly choose an operator
            case 0:
                operator = '+';
                answer = a + b;
                break;
            case 1:
                operator = '-';
                answer = a - b;
                break;
            case 2:
                operator = '*';
                answer = a * b;
                break;
            case 3:
                operator = '/';
                answer = a / b;
                break;
        }
        printf("Question %d: What is %d %c %d?\n", i+1, a, operator, b);
        int userAnswer;
        scanf("%d", &userAnswer);
        if(userAnswer == answer){
            printf("Correct!\n\n");
            correctAnswers++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    printf("Exam complete! You got %d out of %d questions correct.\n", correctAnswers, numQuestions);
    if(correctAnswers == numQuestions){
        printf("Congratulations, %s! You have passed the exam.\n", name);
    }
    else{
        printf("Sorry, %s. You have failed the exam.\n", name);
    }
    return 0;
}