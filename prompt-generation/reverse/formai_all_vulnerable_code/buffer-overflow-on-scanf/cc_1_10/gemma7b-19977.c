//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
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
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at business", "c. A person who is wealthy", "d. A person who is creative"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 3},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Nothing", "d. Hum"}, 4},
    {"Which planet is the largest in the solar system?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 5},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at business", "c. A person who is wealthy", "d. A person who is creative"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 3},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Nothing", "d. Hum"}, 4},
    {"Which planet is the largest in the solar system?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 5}
};

int main()
{
    time_t tStart = time(NULL);
    int score = 0;
    int currentQuestion = 0;

    // Display the questions
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Display the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s  ", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer[256];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answers[questions[i].correctAnswer]) == 0)
        {
            score++;
        }

        currentQuestion++;
    }

    time_t tEnd = time(NULL);
    int timeTaken = tEnd - tStart;

    // Display the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}