//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Gather the user's name and birthdate
    char name[20];
    printf("What is your name, my dear? ");
    scanf("%s", name);

    int year, month, day;
    printf("Please provide the year of your birth: ");
    scanf("%d", &year);

    printf("Enter the month of your birth (1-12): ");
    scanf("%d", &month);

    printf("Give me the day of your birth: ");
    scanf("%d", &day);

    // Calculate your astrological sign
    int sign = (year - 1) % 12 + month - 1;

    // Print the user's astrological sign
    switch (sign)
    {
        case 0:
            printf("Your astrological sign is Capricorn.\n");
            break;
        case 1:
            printf("Your astrological sign is Aquarius.\n");
            break;
        case 2:
            printf("Your astrological sign is Pisces.\n");
            break;
        case 3:
            printf("Your astrological sign is Aries.\n");
            break;
        case 4:
            printf("Your astrological sign is Taurus.\n");
            break;
        case 5:
            printf("Your astrological sign is Gemini.\n");
            break;
        case 6:
            printf("Your astrological sign is Cancer.\n");
            break;
        case 7:
            printf("Your astrological sign is Leo.\n");
            break;
        case 8:
            printf("Your astrological sign is Virgo.\n");
            break;
        case 9:
            printf("Your astrological sign is Libra.\n");
            break;
        case 10:
            printf("Your astrological sign is Scorpio.\n");
            break;
        case 11:
            printf("Your astrological sign is Sagittarius.\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    // Print a fortune
    int fortune = rand() % 10;

    switch (fortune)
    {
        case 0:
            printf("Today, you will find happiness and prosperity.\n");
            break;
        case 1:
            printf("You will encounter a mysterious person who will change your life.\n");
            break;
        case 2:
            printf("Your creativity will soar, and you will find success in your chosen field.\n");
            break;
        case 3:
            printf("You will face challenges, but you will overcome them with strength and determination.\n");
            break;
        case 4:
            printf("Love and friendship will bring you joy.\n");
            break;
        case 5:
            printf("You will travel to new places and experience new cultures.\n");
            break;
        case 6:
            printf("You will gain wisdom and knowledge from your experiences.\n");
            break;
        case 7:
            printf("You will be surprised by a gift from a loved one.\n");
            break;
        case 8:
            printf("You will face adversity, but you will triumph over it.\n");
            break;
        case 9:
            printf("You will find clarity and direction in your life.\n");
            break;
        default:
            printf("Your future is bright, my dear.\n");
            break;
    }

    // Thank the user
    printf("Thank you for visiting the Crystal Ball, %s. May your future be filled with happiness and prosperity.\n", name);

    return 0;
}