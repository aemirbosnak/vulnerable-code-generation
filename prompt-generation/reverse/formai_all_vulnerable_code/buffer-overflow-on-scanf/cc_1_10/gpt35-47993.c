//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Question struct
struct Question{
    char question[1000];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int answer;
};

int main()
{
    int score = 0; //initialize score to 0

    //initialize 5 questions
    struct Question q1 = {"What is the capital of France?", "Paris", "London", "New York", "Rome", 1};
    struct Question q2 = {"What is the largest planet in our solar system?", "Mars", "Jupiter", "Venus", "Saturn", 2};
    struct Question q3 = {"In which state is the Grand Canyon located?", "Arizona", "New Mexico", "Nevada", "California", 1};
    struct Question q4 = {"What year was the first iPhone released?", "2007", "2005", "2009", "2010", 1};
    struct Question q5 = {"What is the smallest country in the world?", "Monaco", "Vatican City", "San Marino", "Liechtenstein", 2};

    //print welcome message and instructions
    printf("Welcome to the Online Examination System\n");
    printf("You will be presented with 5 multiple-choice questions. Choose the correct answer by entering 1, 2, 3, or 4\n\n");

    //ask question 1
    printf("Question 1: %s\n", q1.question);
    printf("1. %s\n", q1.option1);
    printf("2. %s\n", q1.option2);
    printf("3. %s\n", q1.option3);
    printf("4. %s\n", q1.option4);
    int answer1; //initialize variable to store user's answer
    scanf("%d", &answer1); //read user's answer from input
    if(answer1 == q1.answer){ //if answer is correct, increase score
        score++;
    }

    //ask question 2
    printf("\nQuestion 2: %s\n", q2.question);
    printf("1. %s\n", q2.option1);
    printf("2. %s\n", q2.option2);
    printf("3. %s\n", q2.option3);
    printf("4. %s\n", q2.option4);
    int answer2;
    scanf("%d", &answer2);
    if(answer2 == q2.answer){
        score++;
    }

    //ask question 3
    printf("\nQuestion 3: %s\n", q3.question);
    printf("1. %s\n", q3.option1);
    printf("2. %s\n", q3.option2);
    printf("3. %s\n", q3.option3);
    printf("4. %s\n", q3.option4);
    int answer3;
    scanf("%d", &answer3);
    if(answer3 == q3.answer){
        score++;
    }

    //ask question 4
    printf("\nQuestion 4: %s\n", q4.question);
    printf("1. %s\n", q4.option1);
    printf("2. %s\n", q4.option2);
    printf("3. %s\n", q4.option3);
    printf("4. %s\n", q4.option4);
    int answer4;
    scanf("%d", &answer4);
    if(answer4 == q4.answer){
        score++;
    }

    //ask question 5
    printf("\nQuestion 5: %s\n", q5.question);
    printf("1. %s\n", q5.option1);
    printf("2. %s\n", q5.option2);
    printf("3. %s\n", q5.option3);
    printf("4. %s\n", q5.option4);
    int answer5;
    scanf("%d", &answer5);
    if(answer5 == q5.answer){
        score++;
    }

    printf("\nYou have completed the exam\n");
    printf("Your score is: %d\n", score); //print user's score

    return 0;
}