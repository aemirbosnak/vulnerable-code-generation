//FormAI DATASET v1.0 Category: Math exercise ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num1, num2, result;
    char op;

    printf("Welcome to the Math Game! Let's play!\n\n");

    srand(time(NULL)); //initialize random seed

    int count = 0; //keep track of number of questions answered correctly

    for (int i=0; i<10; i++)
    {
        //generate two random numbers between 1-20
        num1 = rand() % 20 + 1;
        num2 = rand() % 20 + 1;

        //generate random operator
        int op_num = rand() % 3;
        switch (op_num)
        {
            case 0:
                op = '+';
                result = num1 + num2;
                break;
            case 1:
                op = '-';
                result = num1 - num2;
                break;
            case 2:
                op = '*';
                result = num1 * num2;
                break;
        }

        printf("Question %d: What is %d %c %d?\n", i+1, num1, op, num2);

        int user_ans;
        scanf("%d", &user_ans);

        if (user_ans == result)
        {
            printf("Correct!\n");
            count++;
        }
        else
        {
            printf("Wrong! The answer is %d.\n", result);
        }

    }

    printf("\nGame Over! You answered %d questions correctly.\n", count);

    return 0;
}