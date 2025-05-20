//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, month, day, hour, minute, second, choice;
    char name[20], gender, hobby[20];
    float salary, balance;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your gender (M/F): ");
    scanf("%c", &gender);

    printf("Enter your birth year: ");
    scanf("%d", &year);

    printf("Enter your birth month (1-12): ");
    scanf("%d", &month);

    printf("Enter your birth day: ");
    scanf("%d", &day);

    printf("Enter your birth hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter your birth minute (0-59): ");
    scanf("%d", &minute);

    printf("Enter your birth second (0-59): ");
    scanf("%d", &second);

    printf("Enter your salary: ");
    scanf("%f", &salary);

    printf("Enter your current balance: ");
    scanf("%f", &balance);

    printf("\n");

    printf("Hello, %s! You are %d years old, born on %d/%d/%d at %d:%d:%d.%c", name, year - 2023, month, day, hour, minute, second, gender);

    printf("\n");

    printf("Your salary is $%.2f and your current balance is $%.2f.", salary, balance);

    printf("\n");

    printf("What would you like to do? (1) Buy a book, (2) Watch a movie, (3) Listen to music, (4) Play a game): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You have chosen to buy a book.\n");
            break;
        case 2:
            printf("You have chosen to watch a movie.\n");
            break;
        case 3:
            printf("You have chosen to listen to music.\n");
            break;
        case 4:
            printf("You have chosen to play a game.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("\n");

    printf("Thank you for visiting the digital diary, %s. See you next time!", name);

    return 0;
}