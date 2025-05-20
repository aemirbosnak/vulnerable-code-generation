//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
int getRandomNumber(int lower, int upper);
int calculateAnswer(int a, int b, char operation);
void printEquation(int a, int b, char operation);

int main()
{
    srand(time(NULL));
    
    int lower = 1, upper = 10;
    char operators[4] = {'+', '-', '*', '/'};
    int num1, num2, answer, userAnswer, correctAnswers = 0, totalQuestions = 0;
    char operation;
    
    printf("Welcome to the Genius Math Exercise!\n");
    printf("You will be given a series of math problems to solve.\n");
    printf("You will need to enter the correct answer to move on.\n");
    printf("Let's begin!\n");
    
    while(1)
    {
        num1 = getRandomNumber(lower, upper);
        num2 = getRandomNumber(lower, upper);
        operation = operators[getRandomNumber(0, 3)];
        
        if(operation == '/' && num2 == 0)
        {
            continue;
        }
        
        printEquation(num1, num2, operation);
        scanf("%d", &userAnswer);
        
        answer = calculateAnswer(num1, num2, operation);
        
        if(userAnswer == answer)
        {
            printf("Correct! Great Job!\n");
            correctAnswers++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d\n", answer);
        }
        
        totalQuestions++;
        printf("You have answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);
        
        if(totalQuestions % 5 == 0)
        {
            printf("Congratulations! You've answered 5 questions correctly in a row!\n");
        }
        
        if(totalQuestions % 10 == 0)
        {
            printf("You've answered 10 questions! Let's increase the difficulty!\n");
            lower += 5;
            upper += 5;
        }
        
        printf("\n");
        
        if(totalQuestions == 20)
        {
            printf("Good job! You've completed 20 questions!\n");
            break;
        }
    }
    
    printf("Thanks for playing Genius Math Exercise!\n");
    printf("Your final score is %d out of %d questions.\n", correctAnswers, totalQuestions);
    
    return 0;
}

int getRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

int calculateAnswer(int a, int b, char operation)
{
    int answer;
    
    switch(operation)
    {
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break;
        case '/':
            answer = a / b;
            break;
    }
    
    return answer;
}

void printEquation(int a, int b, char operation)
{
    printf("%d %c %d = ", a, operation, b);
}