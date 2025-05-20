//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int level, answer, num1, num2, num3, score=0, i;

    printf("Welcome to the Math Exercise Game!\n\n");
    printf("Please choose a level: \n1 for easy\n2 for medium\n3 for hard\n");
    scanf("%d", &level);

    srand(time(0));

    for(i=1;i<=10;i++)
    {
        if(level==1)
        {
            num1=rand()%10+1;
            num2=rand()%10+1;
            printf("\n%d + %d = ", num1, num2);
            scanf("%d", &answer);
            if(answer==num1+num2)
            {
                score++;
                printf("Correct! ");
            }
            else
                printf("Incorrect. ");
        }
        else if(level==2)
        {
            num1=rand()%50+1;
            num2=rand()%50+1;
            printf("\n%d - %d = ", num1, num2);
            scanf("%d", &answer);
            if(answer==num1-num2)
            {
                score++;
                printf("Great job! ");
            }
            else
                printf("Wrong! ");
        }
        else if(level==3)
        {
            num1=rand()%100+1;
            num2=rand()%100+1;
            num3=rand()%100+1;
            printf("\n%d * %d / %d = ", num1, num2, num3);
            scanf("%d", &answer);
            if(answer==(num1*num2)/num3)
            {
                score++;
                printf("Superb! ");
            }
            else
                printf("Sorry, that is incorrect. ");
        }
    }

    printf("\n\nGame Over! Your final score is %d out of 10.", score);

    return 0;
}