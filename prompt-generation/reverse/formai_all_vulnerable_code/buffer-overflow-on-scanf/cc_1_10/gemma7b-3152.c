//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10

int main()
{
    int score = 0, i, current_question = 0, is_correct = 0;
    char answer;

    // Seed the random number generator
    srand(time(NULL));

    // Create an array of questions
    char **questions = (char**)malloc(NUM_QUESTIONS * sizeof(char*));
    questions[0] = "What is the meaning of the word 'entrepreneur'.";
    questions[1] = "Which scientist invented the theory of relativity.";
    questions[2] = "What is the chemical symbol for gold.";
    questions[3] = "Which planet is the largest.";
    questions[4] = "What is the capital of France.";
    questions[5] = "Which artist painted the Mona Lisa.";
    questions[6] = "What is the most common color of hair in the world.";
    questions[7] = "Which animal is the largest predator on Earth.";
    questions[8] = "What is the meaning of the word 'entrepreneur' in a synonym.";
    questions[9] = "Which country is the largest exporter of oil.";

    // Loop over the questions
    for (i = 0; i < NUM_QUESTIONS; i++)
    {
        // Display the question
        printf("%s", questions[i]);

        // Get the user's answer
        scanf(" %c", &answer);

        // Check if the answer is correct
        is_correct = answer == questions[i][0];

        // Award points if the answer is correct
        if (is_correct)
        {
            score++;
        }

        // Increment the current question
        current_question++;
    }

    // Display the final score
    printf("Your final score is: %d", score);

    return 0;
}