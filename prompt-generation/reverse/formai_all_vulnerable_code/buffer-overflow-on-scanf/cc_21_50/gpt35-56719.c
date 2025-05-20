//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, answer;
    srand(time(NULL)); //seeds the random number generator with current time
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("This program will give you a random fortune based on the number you choose.\n");
    printf("Please enter a number between 1 and 10: ");
    scanf("%d", &num);
    switch(num)
    {
        case 1:
            printf("Your future is looking bright!\n");
            break;
        case 2:
            printf("Money is in your future.\n");
            break;
        case 3:
            printf("You will meet your soulmate soon.\n");
            break;
        case 4:
            printf("Your hard work will pay off soon.\n");
            break;
        case 5:
            printf("You will travel to a foreign country soon.\n");
            break;
        case 6:
            printf("A new opportunity will come your way soon.\n");
            break;
        case 7:
            printf("You will receive a surprise gift soon.\n");
            break;
        case 8:
            printf("Your health will improve soon.\n");
            break;
        case 9:
            printf("Your wishes will come true.\n");
            break;
        case 10:
            printf("You will receive good news soon.\n");
            break;
        default:
            printf("Invalid input. Please enter a number between 1 and 10.\n");
    }
    printf("Would you like to ask another question? (1 = Yes, 0 = No): ");
    scanf("%d", &answer);
    if(answer == 1)
    {
        printf("Please enter a number between 1 and 10: ");
        scanf("%d", &num);
        switch(num)
        {
            case 1:
                printf("You will encounter a difficult challenge in the near future.\n");
                break;
            case 2:
                printf("You will face a major decision soon.\n");
                break;
            case 3:
                printf("You will have to make sacrifices in order to achieve your goals.\n");
                break;
            case 4:
                printf("You will experience some setbacks, but you will ultimately succeed.\n");
                break;
            case 5:
                printf("You will soon have to confront someone about an issue that has been bothering you.\n");
                break;
            case 6:
                printf("You will have an important conversation with someone close to you.\n");
                break;
            case 7:
                printf("You will receive some unexpected news soon.\n");
                break;
            case 8:
                printf("You will have to let go of something or someone in order to move forward.\n");
                break;
            case 9:
                printf("You will experience a major change in your life soon.\n");
                break;
            case 10:
                printf("A friend will need your help soon.\n");
                break;
            default:
                printf("Invalid input. Please enter a number between 1 and 10.\n");
        }
    }
    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}