//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char answer;
    printf("Welcome to the automated fortune teller!\n\n");
    printf("This fortune teller will predict your future based on your horoscope sign.\n");
    printf("Please enter your horoscope sign: ");
    scanf("%c", &answer);
    printf("\n");
    
    switch (answer)
    {
        case 'A':
            printf("You will find success in your career in the near future.\n");
            break;
        case 'B':
            printf("You will find love in unexpected places.\n");
            break;
        case 'C':
            printf("You will go on an exciting adventure in the coming months.\n");
            break;
        case 'D':
            printf("You will receive a windfall in the near future.\n");
            break;
        case 'E':
            printf("You will face some challenges in the coming days, but you will overcome them with ease.\n");
            break;
        case 'F':
            printf("Your creativity will be put to good use and will bring you great success.\n");
            break;
        case 'G':
            printf("You will find peace and tranquility in the coming months.\n");
            break;
        case 'H':
            printf("Your hard work will pay off, and you will be rewarded handsomely.\n");
            break;
        case 'I':
            printf("You will travel to far-off lands and make unforgettable memories.\n");
            break;
        default:
            printf("Invalid input. Please enter a valid horoscope sign.\n");
            break;
    }
    
    printf("\nThank you for using the automated fortune teller.\n");
    
    return 0;
}