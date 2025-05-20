//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 3},
    {"Which river flows through London?", {"a. River Thames", "b. River Severn", "c. River Clyde", "d. River Trent"}, 4},
    {"What is the most common color of the human hair?", {"a. Black", "b. Blonde", "c. Red", "d. Gray"}, 5},
    {"Which planet is known for its many volcanoes?", {"a. Earth", "b. Mars", "c. Venus", "d. Jupiter"}, 6},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 3},
    {"Which river flows through London?", {"a. River Thames", "b. River Severn", "c. River Clyde", "d. River Trent"}, 4}
};

int main()
{
    time_t t;
    int i, score = 0, correctAnswer;
    char answer;

    t = time(NULL);
    srand(t);

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        for (correctAnswer = 0; correctAnswer < MAX_ANSWERS; correctAnswer++)
        {
            printf("%s. %s\n", correctAnswer + 1, questions[i].answers[correctAnswer]);
        }

        printf("Enter your answer: ");
        scanf("%c", &answer);

        if (answer == questions[i].correctAnswer)
        {
            score++;
        }
    }

    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}