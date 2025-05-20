//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to display the question and get answer from user
int askQuestion(char* question)
{
    char answer[10];
    printf("%s\n", question);
    scanf("%s", answer);
    if (strcmp(answer, "a") == 0) {
        return 1;
    }
    else if (strcmp(answer, "b") == 0) {
        return 2;
    }
    else if (strcmp(answer, "c") == 0) {
        return 3;
    }
    else if (strcmp(answer, "d") == 0) {
        return 4;
    }
    else {
        return -1;
    }
}

int main()
{
    char* questions[] = {
        "Which of the following is a programming language?\n"
        "a. HTML\n"
        "b. CSS\n"
        "c. Java\n"
        "d. SQL\n",
        
        "Which of the following data types is used to store a floating-point number in C?\n"
        "a. int\n"
        "b. char\n"
        "c. float\n"
        "d. bool\n",

        "Which of the following is an example of a conditional statement?\n"
        "a. if statement\n"
        "b. for loop\n"
        "c. while loop\n"
        "d. switch statement\n",

        "Which of the following is a data structure that stores multiple values of the same data type?\n"
        "a. array\n"
        "b. linked list\n"
        "c. stack\n"
        "d. queue\n",
        
        "Which of the following is NOT a sorting algorithm?\n"
        "a. bubble sort\n"
        "b. quick sort\n"
        "c. heap sort\n"
        "d. pivot sort\n"
    };

    int correctAnswers[] = { 3, 3, 1, 1, 4 };
    int userAnswers[5] = { -1 };

    printf("Welcome to the Online Examination System!\n");

    // ask each question and store the user's answer
    for (int i = 0; i < 5; i++) {
        userAnswers[i] = askQuestion(questions[i]);
    }

    // calculate the user's score
    int score = 0;
    for (int i = 0; i < 5; i++) {
        if (userAnswers[i] == correctAnswers[i]) {
            score++;
        }
    }

    // display the results
    printf("Your score is %d/5.\n", score);
    if (score >= 3) {
        printf("Congratulations! You passed the exam.\n");
    }
    else {
        printf("Sorry, you did not pass the exam.\n");
    }

    return 0;
}