//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at business", "c. A person who is wealthy", "d. A person who is poor"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Red", "d. Blonde"}, 1},
    // Add more questions here...
};

int main()
{
    int i, score = 0;
    time_t start, end;

    // Start the timer
    start = time(NULL);

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Get the user's answer
        char answer = getchar();

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer)
        {
            score++;
        }
    }

    // End the timer
    end = time(NULL);

    // Calculate the time taken
    int timeTaken = end - start;

    // Display the results
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}