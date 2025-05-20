//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[50];
    printf("Welcome to the Fortune Teller! \n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, let's get started...\n", name);

    srand(time(NULL));
    int random_num = rand() % 10 + 1;

    switch (random_num)
    {
        case 1:
            printf("You will have a great day today, %s!\n", name);
            break;
        case 2:
            printf("A new opportunity is coming your way, %s!\n", name);
            break;
        case 3:
            printf("You will meet someone special soon, %s!\n", name);
            break;
        case 4:
            printf("A surprise is waiting for you, %s!\n", name);
            break;
        case 5:
            printf("You will have good luck in your next adventure, %s!\n", name);
            break;
        case 6:
            printf("Your hard work will pay off, %s!\n", name);
            break;
        case 7:
            printf("You will have a peaceful day, %s!\n", name);
            break;
        case 8:
            printf("You are going to receive a nice gift, %s!\n", name);
            break;
        case 9:
            printf("You will have a successful outcome, %s!\n", name);
            break;
        default:
            printf("Today will be just an ordinary day, %s.\n", name);
            break;
    }

    return 0;
}