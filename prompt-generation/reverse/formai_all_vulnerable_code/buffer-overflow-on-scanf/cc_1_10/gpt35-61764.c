//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int yesno;
    char name[20];
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Greetings, %s!\n", name);
    printf("Would you like to know your fortune for today? (1/0): ");
    scanf("%d", &yesno);
    if(yesno == 1){
        printf("Excellent! Let me consult the ancients for your fortune.\n");
    }
    else{
        printf("That's okay, maybe next time. Have a good day %s!\n", name);
        return 0;
    }

    srand(time(NULL));
    int rand_num = rand() % 5 + 1;

    switch(rand_num){
        case 1:
            printf("You will find happiness in unexpected places today.\n");
            break;
        case 2:
            printf("Watch out for a disagreement with a loved one, but don't worry--it will be resolved.\n");
            break;
        case 3:
            printf("Today is your lucky day! Good things are in store for you.\n");
            break;
        case 4:
            printf("Be careful when making any financial decisions today. Look out for scams.\n");
            break;
        case 5:
            printf("You may face a difficult decision today. Trust your instincts and stay true to yourself.\n");
            break;
        default:
            printf("Uh oh, something went wrong. Please try again later.\n");
            break;
    }

    printf("Thank you for using the Automated Fortune Teller. Have a good day %s!\n", name);
    return 0;
}