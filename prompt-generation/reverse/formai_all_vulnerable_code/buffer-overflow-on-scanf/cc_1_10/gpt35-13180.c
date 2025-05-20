//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 10

/*
 * Function to get user input
 */
void getUserInput(char *input)
{
    printf("\nEnter your answer: ");
    scanf("%s", input);
}

/*
 * Function to check user input and increment score
 */
int checkAnswer(char *input, char correct[3])
{
    int result = 0;
    if (strcmp(input, correct) == 0)
    {
        printf("\nCorrect!\n");
        result = 1;
    }
    else
    {
        printf("\nIncorrect. The correct symbol is %s.\n", correct);
    }
    return result;
}

/*
 * Main function
 */
int main()
{
    char questions[MAX_QUESTIONS][100] = {
        "What is the symbol for Iron?",
        "What is the symbol for Copper?",
        "What is the symbol for Silver?",
        "What is the symbol for Gold?",
        "What is the symbol for Mercury?",
        "What is the symbol for Lead?",
        "What is the symbol for Tin?",
        "What is the symbol for Zinc?",
        "What is the symbol for Sulphur?",
        "What is the symbol for Carbon?"
    };

    char answers[MAX_QUESTIONS][3] = {
        "Fe", 
        "Cu", 
        "Ag", 
        "Au",
        "Hg",
        "Pb",
        "Sn",
        "Zn",
        "S",
        "C"
    };

    int score = 0;
    char input[3];

    printf("Welcome to the Medieval Periodic Table Quiz!\n");
    printf("Answer the following questions to test your knowledge of the elements.\n");

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("\n%s\n", questions[i]);
        getUserInput(input);
        score += checkAnswer(input, answers[i]);
    }

    printf("\nQuiz complete! You scored %d out of %d.\n", score, MAX_QUESTIONS);
    return 0;
}