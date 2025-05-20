//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int a,b,c,speed,score=0,maximum=10,time_taken;
    char ch;

    printf("\nWelcome to the Internet Speed Test Application!\n");
    printf("You will be given 10 questions to test your internet speed.\n");
    printf("\nPress Enter key to start...");
    getchar();

    srand(time(0)); //random seed

    for(int i=1; i<=maximum; i++)
    {
        printf("\nQuestion %d:\n", i);

        //random download speed generator between 1-100 MB/s
        a = rand()%100 + 1;
        b = rand()%100 + 1;
        c = rand()%100 + 1;

        printf("What is your internet speed if your download speed is %d.%d%d MB/s\n", a, b, c);

        //calculating internet speed
        speed = a*1024*1024 + b*1024 + c;

        time_t start = time(NULL); //start timer

        scanf("%d", &score); //taking input from user

        time_t end = time(NULL); //end timer

        //calculating time taken in seconds
        time_taken = (int)end - (int)start;

        if(speed == score) //checking answer
        {
            printf("You are correct! Your time taken was %d seconds.\n", time_taken);
        }
        else
        {
            printf("Wrong answer! Your time taken was %d seconds.\n", time_taken);
        }

        printf("Do you want to continue?(Y/N)\n");
        scanf("\n%c", &ch);

        if(ch == 'N' || ch == 'n') //ending the game if user doesn't want to continue
        {
            maximum = i;
            break;
        }

    }

    printf("\nThank you for playing the Internet Speed Test Application!\n");
    printf("You have answered %d out of %d questions correctly.\n", maximum-1, maximum);

    return 0;
}