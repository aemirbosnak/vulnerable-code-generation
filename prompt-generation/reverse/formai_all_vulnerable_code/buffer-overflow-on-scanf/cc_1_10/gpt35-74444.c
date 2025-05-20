//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10 
#define MAX_DIGITS 11

// Function to initialize the periodic table questions
void initQuestions(char *questions[MAX_QUESTIONS], char *answers[MAX_QUESTIONS])
{
    // Questions
    questions[0] = "What is the symbol for Hydrogen? (Hint: H)";
    questions[1] = "What is the symbol for Carbon? (Hint: C)";
    questions[2] = "What is the symbol for Oxygen? (Hint: O)";
    questions[3] = "What is the symbol for Nitrogen? (Hint: N)";
    questions[4] = "What is the symbol for Sodium? (Hint: Na)";
    questions[5] = "What is the symbol for Potassium? (Hint: K)";
    questions[6] = "What is the symbol for Iron? (Hint: Fe)";
    questions[7] = "What is the symbol for Gold? (Hint: Au)";
    questions[8] = "What is the symbol for Mercury? (Hint: Hg)";
    questions[9] = "What is the symbol for Lead? (Hint: Pb)";

    // Answers
    answers[0] = "H";
    answers[1] = "C";
    answers[2] = "O";
    answers[3] = "N";
    answers[4] = "Na";
    answers[5] = "K";
    answers[6] = "Fe";
    answers[7] = "Au";
    answers[8] = "Hg";
    answers[9] = "Pb";
}

// Function to get a random number between min and max
int getRandomNumber(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to print the questions and get the user input
int printQuestionAndGetInput(char *question, char *answer)
{
    char input[MAX_DIGITS];
    printf("%s\n", question);
    scanf("%s", input);
    if(strcmp(input, answer) == 0)
    {
        printf("Correct\n");
        return 1;
    }
    else
    {
        printf("Incorrect. The correct answer is %s\n", answer);
        return 0;
    }
}

int main()
{
    char *questions[MAX_QUESTIONS];
    char *answers[MAX_QUESTIONS];
    char playAgain = 'y';
    int totalQuestionsAnswered = 0;
    int totalCorrectAnswers = 0;

    initQuestions(questions, answers);

    printf("Welcome to the Periodic Table Quiz\n");

    while(playAgain == 'y')
    {
        int questionNumbers[MAX_QUESTIONS] = {0};
        int currentQuestion = 0;

        printf("Please answer %d questions by entering the symbol of the element\n", MAX_QUESTIONS);

        // Loop through all the questions
        while(currentQuestion < MAX_QUESTIONS)
        {
            int questionNumber = getRandomNumber(0, MAX_QUESTIONS - 1);

            if(questionNumbers[questionNumber] == 0)
            {
                questionNumbers[questionNumber] = 1;
                totalQuestionsAnswered++;
                totalCorrectAnswers += printQuestionAndGetInput(questions[questionNumber], answers[questionNumber]);
                currentQuestion++;
            }
        }

        printf("\nYou answered %d out of %d questions correctly. \n", totalCorrectAnswers, MAX_QUESTIONS);

        // Ask user whether they want to play again
        printf("\nDo you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain);

        // Reset the score if the user chooses to play again
        if(playAgain == 'y')
        {
            totalCorrectAnswers = 0;
            totalQuestionsAnswered = 0;
        }
    }

    printf("\nThank you for playing the Periodic Table Quiz. Goodbye!\n");

    return 0;
}