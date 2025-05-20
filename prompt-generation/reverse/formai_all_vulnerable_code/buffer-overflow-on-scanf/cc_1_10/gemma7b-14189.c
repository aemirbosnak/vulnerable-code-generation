//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char question[255];
    char answers[MAX_ANSWERS][255];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at selling", "c. A person who is creative", "d. A person who is ambitious"}, 1},
    {"Which country is the largest in the world?", {"a. China", "b. Canada", "c. USA", "d. Russia"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 0},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Noise", "c. Harmony", "d. Silence"}, 2},
    {"Which planet has the most moons?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at selling", "c. A person who is creative", "d. A person who is ambitious"}, 1},
    {"Which country is the largest in the world?", {"a. China", "b. Canada", "c. USA", "d. Russia"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 0},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1}
};

int main()
{
    int i, score = 0, attempts = 0;
    time_t start_time, end_time;

    start_time = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        printf("Enter your answer: ");
        char answer;
        scanf("%c", &answer);

        if (answer == questions[i].correctAnswer)
        {
            score++;
        }

        attempts++;
    }

    end_time = time(NULL);

    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d seconds\n", end_time - start_time);

    return 0;
}