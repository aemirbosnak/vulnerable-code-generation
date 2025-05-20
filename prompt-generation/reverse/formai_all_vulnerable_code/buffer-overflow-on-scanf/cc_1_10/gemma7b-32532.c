//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char *question;
    char *options[4];
    int answer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Paris", "Rome", "London", "Berlin"}, 1},
    {"Which scientist invented the theory of relativity?", {"Albert Einstein", "Isaac Newton", "Charles Darwin", "Galileo Galilei"}, 2},
    {"Which planet is the largest?", {"Jupiter", "Mars", "Saturn", "Earth"}, 0},
    // Add more questions here...
};

int main()
{
    int i, score = 0, totalQuestions = 0;
    char answerChoice;

    time_t startTime = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        printf("a. %s\n", questions[i].options[0]);
        printf("b. %s\n", questions[i].options[1]);
        printf("c. %s\n", questions[i].options[2]);
        printf("d. %s\n", questions[i].options[3]);

        printf("Enter your answer choice (a/b/c/d): ");
        scanf("%c", &answerChoice);

        if (answerChoice == questions[i].answer)
        {
            score++;
        }

        totalQuestions++;
    }

    time_t endTime = time(NULL);

    printf("Your total score: %d/%d\n", score, totalQuestions);
    printf("Time taken: %ld seconds\n", endTime - startTime);

    return 0;
}