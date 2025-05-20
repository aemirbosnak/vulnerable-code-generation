//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;
    char question[100];
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! What's your age?\n", name);
    scanf("%d", &age);
    
    if(age < 18) {
        printf("I'm sorry, you must be 18 or older to use the Automated Fortune Teller.\n");
        return 0;
    }
    
    printf("What's your question? ");
    scanf("%s", question);
    
    srand(time(0));
    int randomNumber = rand() % 10 + 1;
    
    switch(randomNumber)
    {
        case 1:
            printf("\nYes.");
            break;
        case 2:
            printf("\nNo.");
            break;
        case 3:
            printf("\nI'm not sure. Ask again.");
            break;
        case 4:
            printf("\nIt doesn't look good.");
            break;
        case 5:
            printf("\nIt's a definite possibility.");
            break;
        case 6:
            printf("\nI don't think so.");
            break;
        case 7:
            printf("\nMost likely.");
            break;
        case 8:
            printf("\nThere's a good chance.");
            break;
        case 9:
            printf("\nIt's looking good.");
            break;
        case 10:
            printf("\nDefinitely!");
            break;
        default: 
            printf("\nError: Something went wrong with the Automated Fortune Teller.");
            break;
    }
    
    printf("\nThank you for using the Automated Fortune Teller! Good luck on your quest, %s!\n", name);
    
    return 0;
}