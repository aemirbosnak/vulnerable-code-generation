//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    char name[20];
    int birth_year, curr_year, age, lucky_number, fortune;

    printf("Welcome to the Love and Destiny Fortune Teller Program.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your birth year: ");
    scanf("%d", &birth_year);
    printf("Please enter the current year: ");
    scanf("%d", &curr_year);

    age = curr_year - birth_year;

    printf("You are %d years old, %s.\n", age, name);
    printf("Now, please enter a number between 1 and 100: ");
    scanf("%d", &lucky_number);

    srand(time(0));
    fortune = rand() % 5;
    switch(fortune)
    {
        case 0:
            printf("\nYour destiny awaits...");
            printf("\n\n%s, it is written in the stars that you will meet your soulmate in the near future.\n", name);
            printf("You must be patient and believe in true love. Remember, good things come to those who wait.\n");
            printf("Your lucky number %d will bring you great fortune in all aspects of your life.\n", lucky_number);
            break;

        case 1:
            printf("\nYour destiny awaits...");
            printf("\n\n%s, you will soon encounter a difficult decision regarding love.\n", name);
            printf("Remember to listen to your heart and trust your instincts.\n");
            printf("Your lucky number %d will guide you towards making the right choice.\n", lucky_number);
            break;

        case 2:
            printf("\nYour destiny awaits...");
            printf("\n\n%s, you may face some obstacles in your love life in the upcoming days.\n", name);
            printf("But please don't lose heart. Remember, true love never runs smooth.\n");
            printf("Your lucky number %d will be your guide through the tough times.\n", lucky_number);
            break;

        case 3:
            printf("\nYour destiny awaits...");
            printf("\n\n%s, your romantic life will be filled with passion and excitement in the coming days.\n", name);
            printf("You will experience things you never thought possible.\n");
            printf("Your lucky number %d will bring you the love and happiness you deserve.\n", lucky_number);
            break;

        case 4:
            printf("\nYour destiny awaits...");
            printf("\n\n%s, your love life will take a surprising turn in the upcoming weeks.\n", name);
            printf("Be ready for a twist in the plot... this could be just what you need to find your true soulmate.\n");
            printf("Your lucky number %d will play a crucial role in this new chapter of your life.\n", lucky_number);
            break;

        default:
            printf("\nHmmm... something seems off.");
            printf("\nPlease try again later.");
            break;
    }

    return 0;
}