//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20], response;
    int num, fortuneNum;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("\nHello %s, please think of a question to ask the fortune teller.\n", name);
    
    do {
        printf("\nYour question: ");
        scanf(" %[^\t\n]", &response);
        printf("\nShaking the magic 8 ball...\n\n");

        // generate a random number between 1 and 8
        fortuneNum = (rand() % 8) + 1;

        switch (fortuneNum) {
            case 1:
                printf("It is certain.\n");
                break;
            case 2:
                printf("Don't count on it.\n");
                break;
            case 3:
                printf("Reply hazy, try again.\n");
                break;
            case 4:
                printf("Without a doubt.\n");
                break;
            case 5:
                printf("My sources say no.\n");
                break;
            case 6:
                printf("Better not tell you now.\n");
                break;
            case 7:
                printf("Yes, definitely.\n");
                break;
            case 8:
                printf("Cannot predict now.\n");
                break;
        }

        printf("\nWould you like to ask another question? (y/n) ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    printf("\nThank you for using the Automated Fortune Teller, %s!\n", name);
    return 0;
}