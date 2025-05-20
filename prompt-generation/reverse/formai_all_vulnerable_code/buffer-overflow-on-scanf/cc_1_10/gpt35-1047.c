//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Powered by your destiny and my code :)\n");

    char name[50];
    printf("Please enter your name: ");
    scanf("%s", name);

    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);

    char question[200];
    printf("What is your burning question today? ");
    scanf(" %[^\n]s", question);

    printf("\nHmm... Let me consult the cosmic universe for your answer...\n");

    srand(time(0));
    int fortune = rand() % 5;

    switch(fortune)
    {
        case 0:
            printf("\nYour destiny awaits, %s. The answer to your question is... Yes.\n", name);
            break;
        case 1:
            printf("\nYour stars align, %s. The answer to your question is... No.\n", name);
            break;
        case 2:
            printf("\nYour future shines bright, %s. The answer to your question is... It's possible.\n", name);
            break;
        case 3:
            printf("\nYour fate is in your hands, %s. The answer to your question is... Ask again later.\n", name);
            break;
        case 4:
            printf("\nYour path is not yet clear, %s. The answer to your question is... Maybe.\n", name);
            break;
        default:
            printf("\nOops! Something went wrong. Please try again later.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller! Have a great day!\n");

    return 0;
}