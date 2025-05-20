//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;
    time_t t;
    srand(time(&t));

    printf("Welcome to the Crystal Ball, %s!\n", name);
    printf("Please tell me your age:");
    scanf("%d", &age);

    int fortune = rand() % 10;

    switch (fortune)
    {
        case 0:
            printf("Your future is as bright as a neon sign on a rainy night.\n");
            break;
        case 1:
            printf("Prepare for a rollercoaster ride of love, money, and happiness.\n");
            break;
        case 2:
            printf("You're destined for greatness, but remember to brush your teeth regularly.\n");
            break;
        case 3:
            printf("The stars are aligned in your favor, so go ahead and make your dreams a reality.\n");
            break;
        case 4:
            printf("Beware of evil spirits and black magic. They're lurking around.\n");
            break;
        case 5:
            printf("You're going to have a lot of luck in the lottery, but only if you buy a ticket.\n");
            break;
        case 6:
            printf("Listen to your gut and trust your instincts. They're more accurate than any oracle.\n");
            break;
        case 7:
            printf("Your love life is going to be tumultuous, but don't worry, it's temporary.\n");
            break;
        case 8:
            printf("You're going to be famous, but only if you can handle the spotlight.\n");
            break;
        case 9:
            printf("Prepare for a lifetime of mystery and intrigue. The answers to your questions will be found in the stars.\n");
            break;
    }

    return 0;
}