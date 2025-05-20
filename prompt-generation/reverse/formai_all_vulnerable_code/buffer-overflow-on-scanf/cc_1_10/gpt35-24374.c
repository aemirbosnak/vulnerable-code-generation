//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int x,y,ans,guess;
    char c;
    srand(time(0));
    printf("Welcome to the Math Quiz Bot! \n");
    printf("You'll be given two numbers to add, subtract or multiply. \n");
    printf("Let's see how good you are at math! \n\n");

    do{
        x=rand()%100; //generating two random numbers between 0 to 99
        y=rand()%100;

        switch(rand()%3) //generating a random operation among addition,subtraction or multiplication
        {
            case 0: 
            {
                ans=x+y;
                printf("%d + %d = ",x,y);
                break;
            }
            case 1:
            {
                ans=x-y;
                printf("%d - %d = ",x,y);
                break;
            }
            case 2:
            {
                ans=x*y;
                printf("%d * %d = ",x,y);
                break;
            }
        }
        scanf("%d",&guess);
        if(guess==ans)
            printf("You are a Math Guru!\n");
        else
            printf("Oops! You need to sharpen your math skills!\n The correct answer is %d\n",ans);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c",&c);
        printf("\n");
    }while(c=='y');

    printf("Thanks for playing! Hope to see you again soon for more Math fun!\n");

    return 0;
}