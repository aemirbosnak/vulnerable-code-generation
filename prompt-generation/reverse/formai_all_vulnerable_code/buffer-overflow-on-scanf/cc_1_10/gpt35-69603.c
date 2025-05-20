//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int num1,num2,result=0,chances=5;
    char operator;
    printf("Welcome to the Arithmetic Quest!\n");
    printf("You have to answer 5 questions correctly to win the game!\n");
    printf("Each question will have a random operator.\n");
    printf("You will only have 5 chances to answer each question.\n");
    printf("Let's start!\n");
    for(int i=0;i<5;i++)
    {
        num1 = rand()%100;
        num2 = rand()%100;
        int op = rand()%4;
        switch(op)
        {
            case 0:
                operator = '+';
                result = num1 + num2;
                break;
            case 1:
                operator = '-';
                result = num1 - num2;
                break;
            case 2:
                operator = '*';
                result = num1 * num2;
                break;
            case 3:
                operator = '/';
                result = num1 / num2;
                break;
        }
        printf("\nQuestion %d: What is %d %c %d?\n",i+1,num1,operator,num2);
        for(int j=0;j<5;j++)
        {
            int answer;
            printf("Attempt %d: ",j+1);
            scanf("%d",&answer);
            if(answer == result)
            {
                printf("Congratulations! You answered correctly.\n");
                break;
            }
            else
            {
                if(j != 4)
                {
                    int remaining = 4 - j;
                    printf("Oops! That's incorrect. You have %d more chances left.\n",remaining);
                }
                else
                {
                    printf("Sorry, you ran out of chances for this question. The correct answer was %d.\n",result);
                }
            }
        }
    }
    printf("\nCongratulations! You have completed the Arithmetic Quest!\n");
    return 0;
}