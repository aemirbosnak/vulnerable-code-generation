//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller()
{
    int random_number = rand() % 10 + 1;

    switch(random_number)
    {
        case 1:
            printf("You are destined for great things, but only if you take risks.\n");
            break;
        case 2:
            printf("Your future is bright, but only if you stay focused on your goals.\n");
            break;
        case 3:
            printf("Beware of those around you, they may not have your best interests at heart.\n");
            break;
        case 4:
            printf("The universe has a plan for you, trust in it and you will succeed.\n");
            break;
        case 5:
            printf("Your struggles will make you stronger, keep going and don't give up.\n");
            break;
        case 6:
            printf("Love is in your future, but it may not come in the way you expect.\n");
            break;
        case 7:
            printf("Be wary of making hasty decisions, take your time and think things through.\n");
            break;
        case 8:
            printf("Your greatest strength is your determination, use it to overcome any obstacle.\n");
            break;
        case 9:
            printf("You will find success in unexpected ways, be open to new opportunities.\n");
            break;
        case 10:
            printf("You have the power to shape your own destiny, choose your path wisely.\n");
            break;
        default:
            printf("Something went wrong, try again later.\n");
            break;
    }
}

int main()
{
    srand(time(NULL)); // seed the random number generator with the current time
    char response;

    printf("Welcome to the Automated Fortune Teller!\n");

    do {
        fortune_teller();

        printf("\nWould you like another fortune? (y/n): ");
        scanf(" %c", &response); // note the space before %c to consume the newline character

        printf("\n");
    } while (response == 'y' || response == 'Y');

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}