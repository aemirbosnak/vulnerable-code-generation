//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input[10];
    printf("Welcome to the Automated Fortune Teller! Would you like your fortune told? (yes or no)\n");
    scanf("%s", input);

    if (strcmp(input, "yes") == 0) 
    {
        srand(time(NULL));
        int num = rand() % 10;

        switch(num)
        {
            case 0:
                printf("You will have a happy day today.\n");
                break;
            case 1:
                printf("A pleasant surprise awaits you soon!\n");
                break;
            case 2:
                printf("You will finally find the solution to a problem that has been troubling you.\n");
                break;
            case 3:
                printf("Be cautious today, as danger may be lurking around the corner.\n");
                break;
            case 4:
                printf("Your hard work will pay off soon!\n");
                break;
            case 5:
                printf("Your creativity will be at an all-time high today.\n");
                break;
            case 6:
                printf("You will meet someone special in the coming days.\n");
                break;
            case 7:
                printf("Opportunities for success will arise today, but it's up to you to seize them.\n");
                break;
            case 8:
                printf("You will receive good news that will brighten your day.\n");
                break;
            case 9:
                printf("Take a risk and try something new today. It may lead to unexpected rewards.\n");
                break;
        }
    }
    else if (strcmp(input, "no") == 0) 
    {
        printf("Okay, have a nice day!\n");
    }
    else 
    {
        printf("I'm sorry, I didn't understand your response. Please try again.\n");
    }

    return 0;
}