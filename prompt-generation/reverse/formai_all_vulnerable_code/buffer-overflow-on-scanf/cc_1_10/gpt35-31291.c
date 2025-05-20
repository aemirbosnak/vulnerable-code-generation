//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Function Definitions
void displayQuiz();
void displayScore(int);

int main()
{
    //Variable Declaration
    int score = 0;
    char answer;

    //Calls Function to Display Quiz
    displayQuiz();

    //Asks for User's Answer & Increments Score if Correct
    printf("\n\nEnter your Answer: ");
    scanf(" %c", &answer);
    if(answer == 'C' || answer == 'c')
    {
        score++;
        printf("Correct Answer!\n");
    }
    else
    {
        printf("Incorrect Answer!\nThe Correct Answer is: C\n");
    }

    //Displays Score
    displayScore(score);

    return 0;
}

//Function to Display Quiz
void displayQuiz()
{
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Question 1:\n");
    printf("What is the symbol for Carbon?\n");
    printf("A) Co\n");
    printf("B) Ca\n");
    printf("C) C\n");
}

//Function to Display Score
void displayScore(int score)
{
    printf("\n\nYour Score is: %d\n", score);
}