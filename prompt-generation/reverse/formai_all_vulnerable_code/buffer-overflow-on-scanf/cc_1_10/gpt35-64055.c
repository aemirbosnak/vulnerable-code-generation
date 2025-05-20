//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h> // for rand() function
#include <time.h> // for time() function

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Declare functions
void askQuestion(int questionNumber);
int generateQuestionNumber(int previousNumbers[], int currentQuestionNumber);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    int questions[MAX_QUESTIONS];
    int score = 0;

    // Loop through each question
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        // Generate a random question number
        int questionNumber = generateQuestionNumber(questions, i);

        // Ask the question
        askQuestion(questionNumber);

        // Get the user's answer
        int answer;
        printf("\nEnter your answer (1-118): ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questionNumber)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", questionNumber);
        }
    }

    // Display the final score
    printf("\nYou scored %d out of %d.\n", score, MAX_QUESTIONS);

    // Return 0 to indicate success
    return 0;
}

void askQuestion(int questionNumber)
{
    // Display the question
    printf("What element has the atomic number %d?\n", questionNumber);

    // TODO: Display multiple choice answers (optional)
}

int generateQuestionNumber(int previousNumbers[], int currentQuestionNumber)
{
    int number;

    // Generate a random number between 1 and 118 (inclusive)
    do
    {
        number = rand() % 118 + 1;
    } while (number == previousNumbers[0]
             || number == previousNumbers[1]
             || number == previousNumbers[2]
             || number == previousNumbers[3]
             || number == previousNumbers[4]
             || number == previousNumbers[5]
             || number == previousNumbers[6]
             || number == previousNumbers[7]
             || number == previousNumbers[8]
             || number == previousNumbers[9]
             || number == currentQuestionNumber + 1);

    // Add the number to the list of previous numbers
    for (int i = 0; i < MAX_QUESTIONS - 1; i++)
    {
        previousNumbers[i] = previousNumbers[i+1];
    }
    previousNumbers[MAX_QUESTIONS - 1] = number;

    // Return the generated number
    return number;
}