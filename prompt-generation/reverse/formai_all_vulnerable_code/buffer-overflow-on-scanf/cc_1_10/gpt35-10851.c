//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
// Decentralized approach - unique C math exercise example program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generateQuestion(char op, int num1, int num2);
int checkAnswer(char op, int num1, int num2, int ans);
float calculateScore(int correct, int total);
void displayResult(float score);

int main()
{
    srand(time(NULL)); // initialize random number generator

    int totalQuestions = 5; // number of questions to ask
    int correctAnswers = 0; // number of correct answers

    for (int i = 0; i < totalQuestions; i++)
    {
        // randomly choose an operation: +, -, *
        char op;
        int randomNum = rand() % 3;
        switch (randomNum)
        {
            case 0:
                op = '+';
                break;
            case 1:
                op = '-';
                break;
            case 2:
                op = '*';
                break;
        }

        // generate two random numbers between 1 and 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;

        // display the question and get the user's answer
        generateQuestion(op, num1, num2);
        int answer;
        scanf("%d", &answer);

        // check if the answer is correct
        if (checkAnswer(op, num1, num2, answer))
        {
            printf("Correct!\n");
            correctAnswers++;
        }
        else
        {
            printf("Incorrect!\n");
        }
    }

    // calculate and display the score
    float score = calculateScore(correctAnswers, totalQuestions);
    displayResult(score);

    return 0;
}

// generate question based on the given operation and numbers
void generateQuestion(char op, int num1, int num2)
{
    printf("What is %d %c %d?\n", num1, op, num2);
}

// check if the user's answer is correct
int checkAnswer(char op, int num1, int num2, int ans)
{
    int correct = 0;
    switch (op)
    {
        case '+':
            if (num1 + num2 == ans)
                correct = 1;
            break;
        case '-':
            if (num1 - num2 == ans)
                correct = 1;
            break;
        case '*':
            if (num1 * num2 == ans)
                correct = 1;
            break;
    }
    return correct;
}

// calculate and return the score
float calculateScore(int correct, int total)
{
    return (float) correct / total * 100;
}

// display the user's score and a personalized message
void displayResult(float score)
{
    printf("\nYour score is %.2f%%.\n", score);
    if (score >= 80)
        printf("Great job! You really know your math.\n");
    else if (score >= 60)
        printf("Not bad! Keep practicing to improve.\n");
    else
        printf("You need more practice. Keep trying!\n");
}