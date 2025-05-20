//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    char sign[20];
    int number;
    int fate;

    printf("Welcome to the Oracle of Love, my dear. Please provide me with your name and sign:");
    scanf("%s %s", name, sign);

    srand(time(NULL));
    number = rand() % 11;

    switch (number)
    {
        case 0:
            fate = 1;
            break;
        case 1:
            fate = 2;
            break;
        case 2:
            fate = 3;
            break;
        case 3:
            fate = 4;
            break;
        case 4:
            fate = 5;
            break;
        case 5:
            fate = 6;
            break;
        case 6:
            fate = 7;
            break;
        case 7:
            fate = 8;
            break;
        case 8:
            fate = 9;
            break;
        case 9:
            fate = 10;
            break;
    }

    printf("Your destiny, %s, is written in the stars. Your sign, %s, holds the key to your future. Your fate is:", name, sign);

    switch (fate)
    {
        case 1:
            printf("Full of passion and mystery. You will find love and happiness, but beware of hidden secrets.");
            break;
        case 2:
            printf("Serene and graceful. You will find success and prosperity, but remember to cherish your friendships.");
            break;
        case 3:
            printf("Brave and courageous. You will face challenges and overcome them, but be wary of your enemies.");
            break;
        case 4:
            printf("Full of wisdom and compassion. You will find happiness through service to others.");
            break;
        case 5:
            printf("Independent and strong. You will find your own path and success, but be mindful of your choices.");
            break;
        case 6:
            printf("Full of joy and laughter. You will find happiness in the simple things, but remember to appreciate the good things in life.");
            break;
        case 7:
            printf("Loyal and faithful. You will find love and support from your friends, but be wary of false promises.");
            break;
        case 8:
            printf("Full of mystery and intrigue. You will find success and recognition, but beware of hidden secrets.");
            break;
        case 9:
            printf("Serene and mysterious. You will find happiness and success, but remember to keep your secrets to yourself.");
            break;
        case 10:
            printf("Full of potential and promise. You will find great success and happiness, but be mindful of your choices.");
            break;
    }

    return 0;
}