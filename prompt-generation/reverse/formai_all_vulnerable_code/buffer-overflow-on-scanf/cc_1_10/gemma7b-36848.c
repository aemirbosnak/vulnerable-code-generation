//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: expert-level
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
    {"What is the meaning of the word 'entrepreneur'?", {"A. Business owner", "B. Employee", "C. Manager", "D. Investor", "E. Contractor"}, 2},
    {"Which scientist invented the theory of relativity?", {"A. Albert Einstein", "B. Isaac Newton", "C. Charles Darwin", "D. Galileo Galilei", "E. Albert Einstein"}, 1},
    {"What is the capital of France?", {"A. Paris", "B. Rome", "C. Lyon", "D. Marseille", "E. Berlin"}, 0},
    // Add more questions here...
};

int main()
{
    int i, score = 0, currentQuestionIndex = 0;

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Display the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer[256];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answers[questions[i].correctAnswerIndex]) == 0)
        {
            score++;
        }

        // Move on to the next question
        currentQuestionIndex++;
    }

    // Display the final score
    printf("Your final score is: %d", score);

    return 0;
}