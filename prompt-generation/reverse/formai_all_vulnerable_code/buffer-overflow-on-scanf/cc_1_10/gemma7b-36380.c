//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", "a. A person who starts and operates a business venture", 5},
    {"Which country is the largest exporter of cars?", "b. China", 4},
    {"Which scientist invented the theory of relativity?", "c. Albert Einstein", 3},
    {"What is the capital of France?", "d. Paris", 2},
    {"Which planet is the largest?", "e. Jupiter", 1}
};

int main()
{
    int i, score = 0;

    printf("Welcome to the C Online Examination System!\n");

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        char answer;
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        if (answer == questions[i].answer[0])
        {
            score += questions[i].marks;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is: %s\n", questions[i].answer);
        }
    }

    printf("Your total score is: %d\n", score);

    return 0;
}