//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    // Set up random number generation using current time
    srand(time(NULL));

    // Initializations
    char response;
    int num;

    // Welcome user and ask if they want their fortune told
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Would you like me to tell your fortune? (Y/N)\n");

    // Get user's response and check validity
    scanf("%c", &response);
    while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') 
    {
        printf("Invalid response. Please enter 'Y' or 'N'.\n");
        getchar(); // Clear input buffer
        scanf("%c", &response);
    }

    if (response == 'N' || response == 'n') 
    {
        printf("Okay, bye!\n");
        return 0;
    }

    // Generate random number and corresponding fortune
    num = rand() % 10;
    printf("\nYour fortune is:\n");

    switch(num) 
    {
        case 0:
            printf("A lorry carrying wallpaper will overturn on your way to work.\n");
            break;
        case 1:
            printf("The stars are not aligned in your favor today.\n");
            break;
        case 2:
            printf("You will meet a tall, dark stranger. But don't trust him.\n");
            break;
        case 3:
            printf("Something good will happen to you in the next 24 hours.\n");
            break;
        case 4:
            printf("Your lucky number today is %d.\n", rand() % 100);
            break;
        case 5:
            printf("You will soon embark on an unexpected adventure.\n");
            break;
        case 6:
            printf("The person you have been thinking about will contact you soon.\n");
            break;
        case 7:
            printf("You will find $100 on the ground today.\n");
            break;
        case 8:
            printf("You will be successful in your career.\n");
            break;
        case 9:
            printf("Your dreams will come true.\n");
            break;
        default:
            printf("Error: Something went wrong.\n");
            break;
    }

    printf("\n");

    return 0;
}