//FormAI DATASET v1.0 Category: Table Game ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int score=0, arr[10], i, j, flag=-1, count=2, rand_num;
    char ans;   
    //Initializing variables
    
    printf("Welcome to the C Table Game! You have been given 10 cards!\n");

    srand(time(NULL));
    // Set the seed for rand() as time

    for(i=0;i<10;i++)
    {
       arr[i]=rand()%100+1; // Generate random numbers between 1-100
    }
    
    printf("The 10 cards have been generated!\n");
    printf("The cards are:\n");
    
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Now, you have to guess whether the next card is going to be higher or lower than the current card.\n");
    printf("If you guess correctly, you will score one point.\n");
    printf("If you guess incorrectly, you will lose one point.\n");
    printf("Let's start the game!\n");

    for(i=0;i<9;i++)
    {
        printf("\nCurrent card: %d\n",arr[i]);
        printf("Higher or lower (h/l)?: ");
        scanf(" %c",&ans);

        rand_num=rand()%100+1;

        if(ans=='h' && arr[i+1]>arr[i])
        {
            printf("Correct!\n");
            score++;
        }

        else if(ans=='l' && arr[i+1]<arr[i])
        {
            printf("Correct!\n");
            score++;
        }

        else
        {
            printf("Incorrect!\n");
            score--;
        }

        printf("Next card: %d\n",arr[i+1]);

        if(score==5 && flag==-1)
        {
            count++;
            printf("Congratulations! You have reached a score of 5 and have gained an additional card!\n");
            printf("The cards are:\n");
            for(j=0;j<count*5;j++)
            {
                printf("%d ",arr[j]);
            }
            printf("\n");
            flag=0;
        }
    }

    printf("\nGame Over! Your final score is %d!\n",score);

    return 0;
}