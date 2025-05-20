//FormAI DATASET v1.0 Category: Online Examination System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TOTAL_QUESTIONS 5

typedef struct {
    char question[200];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_answer;
} Question;

Question questions[TOTAL_QUESTIONS] = {
    {"What is the capital of India?", "Mumbai", "Delhi", "Chennai", "Bangalore", 2},
    {"What is the national animal of India?", "Tiger", "Lion", "Elephant", "Peacock", 1},
    {"What is the currency of Japan?", "Euro", "Dollar", "Yen", "Pound", 3},
    {"Which planet is known as the red planet?", "Earth", "Venus", "Mars", "Jupiter", 3},
    {"Who invented telephone?", "Thomas Edison", "Graham Bell", "Isaac Newton", "Albert Einstein", 2}
};

int shuffle_questions(int array[], int n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

int main()
{
    int user_answer;
    int score = 0;
    int question_order[TOTAL_QUESTIONS];
    int i, j;
    srand(time(0));
    for (i = 0; i < TOTAL_QUESTIONS; i++)
    {
        question_order[i] = i;
    }
    shuffle_questions(question_order, TOTAL_QUESTIONS);
    printf("Welcome to our online examination system!\n");
    printf("You will be asked %d questions.\n", TOTAL_QUESTIONS);
    printf("Each correct answer will get you 1 point.\n");
    printf("Let's begin!\n\n");
    for (i = 0; i < TOTAL_QUESTIONS; i++)
    {
        printf("Question %d: %s\n", i+1, questions[question_order[i]].question);
        printf("Option 1: %s\n", questions[question_order[i]].option1);
        printf("Option 2: %s\n", questions[question_order[i]].option2);
        printf("Option 3: %s\n", questions[question_order[i]].option3);
        printf("Option 4: %s\n", questions[question_order[i]].option4);
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);
        if (user_answer == questions[question_order[i]].correct_answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", questions[question_order[i]].correct_answer);
        }
        printf("\n");
    }
    printf("Your score is: %d out of %d.\n", score, TOTAL_QUESTIONS);
    return 0;
}