//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 5

typedef struct Question
{
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswerIndex;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who is good at making money", "b. A person who is good at starting businesses", "c. A person who is good at managing money", "d. A person who is good at investing money", "e. All of the above"}, 2},
    {"Who was the first president of the United States?", {"a. George Washington", "b. John Adams", "c. Thomas Jefferson", "d. Benjamin Harrison", "e. Woodrow Wilson"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille", "e. Bordeaux"}, 0}
};

int main()
{
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s\n", questions[i].answers[j]);
        }

        char answer;
        printf("Enter your answer: ");
        scanf("%c", &answer);

        if (answer == questions[i].correctAnswerIndex)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is: %c\n", questions[i].correctAnswerIndex);
        }
    }

    printf("Your score: %d\n", score);

    return 0;
}