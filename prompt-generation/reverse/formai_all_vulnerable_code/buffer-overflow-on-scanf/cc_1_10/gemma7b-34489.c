//Gemma-7B DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char team1 = 'R';
    char team2 = 'J';

    printf("Welcome to the Battle of the Two Teams!\n");
    printf("Team %c, please enter your name: ", team1);
    char name1[20];
    scanf("%s", name1);

    printf("Team %c, please enter your number: ", team1);
    int number1;
    scanf("%d", &number1);

    printf("Team %c, please enter your weapon: ", team1);
    char weapon1[20];
    scanf("%s", weapon1);

    printf("Team %c, please enter your strategy: ", team1);
    char strategy1[20];
    scanf("%s", strategy1);

    printf("Team %c, please enter your motto: ", team1);
    char motto1[20];
    scanf("%s", motto1);

    printf("\n");

    printf("Team %c, here is your profile:\n", team1);
    printf("Name: %s\n", name1);
    printf("Number: %d\n", number1);
    printf("Weapon: %s\n", weapon1);
    printf("Strategy: %s\n", strategy1);
    printf("Motto: %s\n", motto1);

    printf("\n");

    printf("Team %c, prepare for battle!\n", team2);
    printf("Team %c, enter your name: ", team2);
    char name2[20];
    scanf("%s", name2);

    printf("Team %c, please enter your number: ", team2);
    int number2;
    scanf("%d", &number2);

    printf("Team %c, please enter your weapon: ", team2);
    char weapon2[20];
    scanf("%s", weapon2);

    printf("Team %c, please enter your strategy: ", team2);
    char strategy2[20];
    scanf("%s", strategy2);

    printf("Team %c, please enter your motto: ", team2);
    char motto2[20];
    scanf("%s", motto2);

    printf("\n");

    printf("Team %c, here is your profile:\n", team2);
    printf("Name: %s\n", name2);
    printf("Number: %d\n", number2);
    printf("Weapon: %s\n", weapon2);
    printf("Strategy: %s\n", strategy2);
    printf("Motto: %s\n", motto2);

    printf("\n");

    printf("The battle begins!\n");

    return 0;
}