//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num, destiny, roll, oracle_answer;
    char name[20];

    printf("Welcome to the Enchanted Forest of Oracle Tower!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("You have come to the crossroads of fate.\n");
    printf("Choose your path:\n");
    printf("1. The Path of Wisdom\n");
    printf("2. The Path of Courage\n");
    printf("3. The Path of Love\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            destiny = 7;
            break;
        case 2:
            destiny = 3;
            break;
        case 3:
            destiny = 10;
            break;
        default:
            destiny = 0;
    }

    roll = rand() % 6 + 1;
    oracle_answer = destiny * roll;

    printf("Your destiny is sealed. You have rolled a %d and your destiny is %d.\n", roll, oracle_answer);

    if (oracle_answer >= 8)
    {
        printf("You will find great success and happiness.\n");
    }
    else
    {
        printf("You will face challenges and obstacles.\n");
    }

    printf("Thank you for visiting the Enchanted Forest of Oracle Tower. May your future be bright.\n");

    return 0;
}