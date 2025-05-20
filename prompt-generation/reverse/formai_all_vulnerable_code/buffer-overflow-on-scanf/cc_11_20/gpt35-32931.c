//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int prob;
    float probFloat;
    srand(time(NULL)); //seeding the random number generator
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the current threat level (1-10): ");
    int threatLevel;
    scanf("%d",&threatLevel); //taking input from the user

    //calculating the probability based on threat level
    if(threatLevel==10)
    {
        prob=99;
    }
    else if(threatLevel>=8 && threatLevel<=9)
    {
        prob=90+rand()%10;
    }
    else if(threatLevel>=6 && threatLevel<=7)
    {
        prob=80+rand()%20;
    }
    else if(threatLevel>=4 && threatLevel<=5)
    {
        prob=70+rand()%30;
    }
    else if(threatLevel>=2 && threatLevel<=3)
    {
        prob=60+rand()%40;
    }
    else if(threatLevel==1)
    {
        prob=50+rand()%50;
    }
    else
    {
        printf("Invalid input!\n");
        return 0;
    }
    printf("The probability of an Alien Invasion is:");

    //handling probabilities greater than 100
    if(prob>100)
    {
        prob=100;
        printf(" %d%%\n",prob);
    }
    else
    {
        probFloat=(float)prob/100;
        printf(" %.2f%%\n",probFloat);
    }
    return 0;
}