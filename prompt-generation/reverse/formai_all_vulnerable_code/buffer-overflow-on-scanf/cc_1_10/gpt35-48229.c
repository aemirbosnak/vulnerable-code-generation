//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void revealFortune() // function to reveal fortunes
{
    int choice = rand() % 10; // generate a random number between 0 and 9
    switch(choice)
    {
        case 0:
            printf("Your future is looking bright!\n");
            break;
        case 1:
            printf("You will encounter a great challenge in the near future.\n");
            break;
        case 2:
            printf("Your hard work will pay off soon.\n");
            break;
        case 3:
            printf("Keep an open mind and you will find success.\n");
            break;
        case 4:
            printf("You will receive an unexpected gift.\n");
            break;
        case 5:
            printf("Your life will soon undergo a major transformation.\n");
            break;
        case 6:
            printf("Your finances are destined to improve.\n");
            break;
        case 7:
            printf("You will meet a charming stranger who will have a big impact on your life.\n");
            break;
        case 8:
            printf("You have a big decision to make soon, choose wisely.\n");
            break;
        case 9:
            printf("Your creativity will reach new heights.\n");
            break;
        default:
            printf("Oops, something went wrong!\n");
            break;
    }
}

int main()
{
    srand(time(NULL)); // initialize random seed
    char response;

    printf("Welcome to the Automated Fortune Teller. Shall we begin? (y/n)\n");
    scanf("%c", &response);

    if (response == 'y' || response == 'Y')
    {
        printf("Great, let's get started!\n");

        while(1)
        {
            printf("Think about your question and press enter to reveal your fortune. To quit, type \"exit\" and press enter.\n");
            char question[50];
            scanf("%s", question);

            if(strcmp(question, "exit") == 0) // check if user wants to quit
            {
                printf("Thank you for using the Automated Fortune Teller. Good luck on your journey!\n");
                break;
            }

            revealFortune(); // reveal the fortune
        }
    }
    else if(response == 'n' || response == 'N')
    {
        printf("That's too bad. Come back when you're ready to know your destiny.\n");
    }
    else
    {
        printf("Sorry, I didn't catch that.\n");
    }

    return 0;
}