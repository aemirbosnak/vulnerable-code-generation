//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Clear the terminal
    system("cls");

    // Welcome the user
    printf("Welcome to the Crystal Ball!\n");

    // Get the user's name
    printf("What is your name, traveler?\n");
    char name[20];
    scanf("%s", name);

    // Generate a random number between 1 and 10
    int number = rand() % 10 + 1;

    // Interpret the number
    char fortune[200];
    if (number == 1)
    {
        fortune[0] = 'A';
        fortune[1] = 'A';
        fortune[2] = 'A';
        fortune[3] = 'A';
    }
    else if (number == 2)
    {
        fortune[0] = 'B';
        fortune[1] = 'B';
        fortune[2] = 'B';
        fortune[3] = 'B';
    }
    else if (number == 3)
    {
        fortune[0] = 'C';
        fortune[1] = 'C';
        fortune[2] = 'C';
        fortune[3] = 'C';
    }
    else if (number == 4)
    {
        fortune[0] = 'D';
        fortune[1] = 'D';
        fortune[2] = 'D';
        fortune[3] = 'D';
    }
    else if (number == 5)
    {
        fortune[0] = 'E';
        fortune[1] = 'E';
        fortune[2] = 'E';
        fortune[3] = 'E';
    }
    else if (number == 6)
    {
        fortune[0] = 'F';
        fortune[1] = 'F';
        fortune[2] = 'F';
        fortune[3] = 'F';
    }
    else if (number == 7)
    {
        fortune[0] = 'G';
        fortune[1] = 'G';
        fortune[2] = 'G';
        fortune[3] = 'G';
    }
    else if (number == 8)
    {
        fortune[0] = 'H';
        fortune[1] = 'H';
        fortune[2] = 'H';
        fortune[3] = 'H';
    }
    else if (number == 9)
    {
        fortune[0] = 'I';
        fortune[1] = 'I';
        fortune[2] = 'I';
        fortune[3] = 'I';
    }
    else if (number == 10)
    {
        fortune[0] = 'J';
        fortune[1] = 'J';
        fortune[2] = 'J';
        fortune[3] = 'J';
    }

    // Print the fortune
    printf("Your fortune, %s, is: ", name);
    printf("%s\n", fortune);

    // Thank the user
    printf("Thank you for visiting the Crystal Ball, %s.\n", name);

    return 0;
}