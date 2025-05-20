//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void redLight()
{
    printf("RED light is ON!\n");
    sleep(5);
}

void yellowLight()
{
    printf("YELLOW light is ON!\n");
    sleep(2);
}

void greenLight()
{
    printf("GREEN light is ON!\n");
    sleep(5);
}

int main()
{
    int i, count=0;
    char option;
    printf("****Traffic Signal Control System*****\n");

    do{
        count++;
        if(count==1 || count==4)
        {
            redLight();
        }
        else if(count==2)
        {
            yellowLight();
        }
        else if(count==3)
        {
            greenLight();
        }
        else
        {
            count=0;
        }
    printf("\n\nDo you want to continue? (y/n):");
    scanf("%c",&option);
    }while(option=='y' || option=='Y');
    return 0;
}