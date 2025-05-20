//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

int main()
{
    int i, score = 0, total_marks = 0;
    char answer;
    time_t start_time, end_time;

    // Allocate memory for questions
    char **questions = (char **)malloc(MAX_QUESTIONS * sizeof(char *));

    // Create questions
    questions[0] = "What is the capital of France?";
    questions[1] = "Who wrote the novel Harry Potter?";
    questions[2] = "What is the meaning of the word 'entrepreneur' ?";
    questions[3] = "What is the chemical formula for sulfuric acid?";
    questions[4] = "What is the square root of 25?";
    questions[5] = "What is the meaning of the word 'prodigy' ?";
    questions[6] = "Who was the first president of the United States?";
    questions[7] = "What is the meaning of the word 'entrepreneur' ?";
    questions[8] = "What is the capital of Australia?";
    questions[9] = "What is the meaning of the word 'avatar' ?";

    // Start timer
    start_time = time(NULL);

    // Loop over questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        // Display question
        printf("%s", questions[i]);

        // Get answer
        scanf(" %c", &answer);

        // Check answer
        if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd')
        {
            // Award marks
            score++;

            // Increment total marks
            total_marks++;
        }
    }

    // End timer
    end_time = time(NULL);

    // Calculate time taken
    int time_taken = end_time - start_time;

    // Display results
    printf("\nYour score is: %d/%d", score, total_marks);
    printf("\nTime taken: %d minutes", time_taken);

    return 0;
}