//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num1, num2, result;
    char operator;
    srand(time(NULL));

    printf("Welcome to the Math Exercise Program!\n\n");

    for(int i=1; i<=10; i++)
    {
        num1 = rand() % 20 + 1;
        num2 = rand() % 10 + 1;

        int operatorChoice = rand() % 4;

        if(operatorChoice == 0)
        {
            operator = '+';
            result = num1 + num2;
        }
        else if(operatorChoice == 1)
        {
            operator = '-';
            result = num1 - num2;
        }
        else if(operatorChoice == 2)
        {
            operator = '/';
            while(num1 % num2 != 0)
            {
                num1 = rand() % 20 + 1;
                num2 = rand() % 10 + 1;
            }
            result = num1 / num2;
        }
        else
        {
            operator = '*';
            result = num1 * num2;
        }

        printf("Exercise %d: What is %d %c %d?\n", i, num1, operator, num2);
        int user_answer;
        printf("Answer: ");
        scanf("%d", &user_answer);

        if(user_answer == result)
        {
            printf("Great job! That's the correct answer! :)\n\n");
        }
        else
        {
            printf("Sorry, that is incorrect. The correct answer is %d. :(\n\n", result);
        }
    }

    printf("Congratulations! You've completed all the exercises! Thanks for using our Math Exercise Program.\n");
    return 0;
}