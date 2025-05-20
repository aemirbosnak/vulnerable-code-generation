//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur?'", {"a) A person who owns a business", "b) A person who is good at math", "c) A person who is creative", "d) A person who is smart"}, 1},
    {"What is the capital of France?", {"a) Paris", "b) Rome", "c) Lyon", "d) Marseille"}, 2},
    {"Which scientist invented the theory of relativity?", {"a) Albert Einstein", "b) Isaac Newton", "c) Charles Darwin", "d) Galileo Galilei"}, 3},
    {"What is the most common color of the human eye?", {"a) Blue", "b) Brown", "c) Gray", "d) Hazel"}, 4},
    {"What is the sound of one hand clapping?", {"a) Silence", "b) A hum", "c) A click", "d) A thump"}, 5},
    {"What is the meaning of the word 'entrepreneur?'", {"a) A person who owns a business", "b) A person who is good at math", "c) A person who is creative", "d) A person who is smart"}, 1},
    {"What is the capital of France?", {"a) Paris", "b) Rome", "c) Lyon", "d) Marseille"}, 2},
    {"Which scientist invented the theory of relativity?", {"a) Albert Einstein", "b) Isaac Newton", "c) Charles Darwin", "d) Galileo Galilei"}, 3},
    {"What is the most common color of the human eye?", {"a) Blue", "b) Brown", "c) Gray", "d) Hazel"}, 4},
    {"What is the sound of one hand clapping?", {"a) Silence", "b) A hum", "c) A click", "d) A thump"}, 5}
};

int main()
{
    int i;
    int score = 0;

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        int answer = 0;
        scanf("%d", &answer);

        if (answer == questions[i].correctAnswer)
        {
            score++;
        }
    }

    printf("Your score is: %d out of %d", score, MAX_QUESTIONS);

    return 0;
}