//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

int main()
{
    int i, score = 0, totalQuestions = 0;
    char answer;

    // Define an array of questions
    char questions[MAX_QUESTIONS][100] = {
        "What is the meaning of the word 'entrepreneur'?",
        "Who invented the telephone?",
        "What is the capital of France?",
        "What is the chemical symbol for gold?",
        "Which planet is the largest?",
        "What is the most populous country in the world?",
        "What is the meaning of the word 'prodigy'?",
        "What is the sound of one hand clapping?",
        "Who was the first president of the United States?",
        "What is the meaning of the word 'entrepreneur'"
    };

    // Loop through the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        // Display the question
        printf("%s", questions[i]);

        // Get the answer from the user
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd')
        {
            // Increment the score
            score++;
        }

        // Increment the total number of questions
        totalQuestions++;
    }

    // Display the results
    printf("Your score is: %d", score);
    printf("\nTotal number of questions: %d", totalQuestions);

    return 0;
}