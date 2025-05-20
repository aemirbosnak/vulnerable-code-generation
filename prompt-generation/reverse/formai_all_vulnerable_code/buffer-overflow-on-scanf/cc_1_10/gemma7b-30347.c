//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    {"What is the meaning of the word 'entrepreneur'?", {"A. A person who is good at making money", "B. A person who is bad at making money", "C. A person who is in charge of a company", "D. A person who is a teacher"}, 2},

    {"Which scientist invented the theory of relativity?", {"A. Isaac Newton", "B. Charles Darwin", "C. Albert Einstein", "D. Galileo Galilei"}, 1},

    {"What is the capital of France?", {"A. Paris", "B. Rome", "C. Berlin", "D. Lyon"}, 3}
};

int main()
{
    int i;
    int score = 0;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("  %s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer;
        printf("Enter your answer: ");
        scanf("%c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is: %c\n", questions[i].correctAnswer);
        }
    }

    // Print the final score
    printf("Your final score is: %d\n", score);

    return 0;
}