//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("Welcome to the Crystal Ball, my dear. Please, take a seat.\n");

    // Gather the user's name and birthdate
    char name[20];
    printf("What is your name, traveler? ");
    scanf("%s", name);

    int year, month, day;
    printf("Please provide the year of your birth: ");
    scanf("%d", &year);

    printf("And the month (1-12): ");
    scanf("%d", &month);

    printf("Finally, the day of your birth: ");
    scanf("%d", &day);

    // Calculate the user's astrological sign
    int sign = (year - 1) % 12 + month - 1 + day - 1;

    // Interpret the astrological sign
    switch (sign)
    {
        case 0:
            printf("You are a Capricorn, my dear %s. You are ambitious, determined, and ambitious.\n", name);
            break;
        case 1:
            printf("You are an Aquarius, my dear %s. You are independent, humanitarian, and unconventional.\n", name);
            break;
        case 2:
            printf("You are a Pisces, my dear %s. You are empathetic, intuitive, and artistic.\n", name);
            break;
        case 3:
            printf("You are a Aries, my dear %s. You are courageous, self-assured, and leadership-oriented.\n", name);
            break;
        case 4:
            printf("You are a Taurus, my dear %s. You are practical, artistic, and loyal.\n", name);
            break;
        case 5:
            printf("You are a Gemini, my dear %s. You are communicative, adaptable, and curious.\n", name);
            break;
        case 6:
            printf("You are a Cancer, my dear %s. You are protective, nurturing, and emotional.\n", name);
            break;
        case 7:
            printf("You are a Leo, my dear %s. You are dramatic, ambitious, and self-centered.\n", name);
            break;
        case 8:
            printf("You are a Virgo, my dear %s. You are organized, efficient, and detail-oriented.\n", name);
            break;
        case 9:
            printf("You are a Libra, my dear %s. You are charming, aesthetic, and concerned with social harmony.\n", name);
            break;
        case 10:
            printf("You are a Scorpio, my dear %s. You are mysterious, loyal, and passionate.\n", name);
            break;
        default:
            printf("I am unable to provide an interpretation for your astrological sign, %s. Please try again.\n", name);
            break;
    }

    printf("Thank you for visiting the Crystal Ball, %s. May your future be bright.\n", name);

    system("pause");
}