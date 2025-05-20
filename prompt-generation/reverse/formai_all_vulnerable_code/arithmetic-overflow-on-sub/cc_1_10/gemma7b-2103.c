//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "Paris", 2},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4},
    {"What is the most common color in the world?", "Blue", 1},
    {"What is the chemical symbol for gold?", "Au", 3},
    {"Which planet is the largest?", "Jupiter", 2},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 3},
    {"Which president signed the Declaration of Independence?", "Thomas Jefferson", 4},
    {"What is the most valuable gemstone in the world?", "Diamond", 5},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 3}
};

int main()
{
    int i, score = 0, time_taken = 0;
    char answer[256];

    time_t start_time = time(NULL);

    printf("Welcome to the C Online Examination System!\n");

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        scanf("Enter your answer: ", answer);

        if (strcmp(answer, questions[i].answer) == 0)
        {
            score += questions[i].marks;
        }
    }

    time_taken = time(NULL) - start_time;

    printf("Your total score is: %d\n", score);

    printf("Time taken: %d seconds\n", time_taken);

    return 0;
}