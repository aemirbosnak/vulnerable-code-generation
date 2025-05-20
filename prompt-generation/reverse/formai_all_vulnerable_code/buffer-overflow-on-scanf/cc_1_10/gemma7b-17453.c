//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of 10 questions
    char questions[10][100] = {
        "What is the meaning of the word 'entrepreneur'?",
        "What is the capital of France?",
        "What is the chemical symbol for gold?",
        "Who was the first president of the United States?",
        "What is the most common color of hair in the world?",
        "What is the sound of one hand clapping?",
        "What is the meaning of the word 'entrepreneur' in a sentence?",
        "What is the most expensive city in the world?",
        "What is the meaning of the word 'giraffe'?",
        "What is the sound of a goose honking?"
    };

    // Randomly select a question
    int question_number = rand() % 10;

    // Display the question
    printf("%s\n", questions[question_number]);

    // Get the user's answer
    char answer[100];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the answer is correct
    char correct_answer[100] = "The answer is: ";
    correct_answer[strlen(correct_answer)] = questions[question_number][0];

    // Display the correct answer
    printf("%s\n", correct_answer);

    // Calculate the user's score
    int score = 0;
    if (strcmp(answer, correct_answer) == 0)
    {
        score++;
    }

    // Display the user's score
    printf("Your score is: %d\n", score);

    return 0;
}