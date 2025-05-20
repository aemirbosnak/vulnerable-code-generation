//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n;
    char name[20];

    srand(time(NULL));

    printf("Greetings, traveler! What is your name?\n");
    scanf("%s", name);
    printf("%s, it is a pleasure to meet you.\n\n", name);

    printf("I am the Automated Fortune Teller of the Medieval Times, and I will reveal your destiny.\n");
    printf("Choose a number from 1 to 5: ");
    scanf("%d", &n);
    printf("\n");

    switch(n)
    {
        case 1:
            printf("Your fate is in the hands of the gods. Pray for their mercy.\n");
            break;
        case 2:
            printf("You will find the love of your life in a distant land.\n");
            break;
        case 3:
            printf("Beware of a man with a scar on his face. He will bring you misfortune.\n");
            break;
        case 4:
            printf("You will become rich beyond your wildest dreams. But at what cost?\n");
            break;
        case 5:
            printf("You will face great challenges, but with perseverance and courage, you will overcome them.\n");
            break;
        default:
            printf("Invalid input. Your fate remains a mystery.\n");
    }

    printf("\nBut wait! There's more. I will also divine your lucky number.\n");
    printf("Choose a number from 1 to 10: ");
    scanf("%d", &n);

    printf("\nYour lucky number is: %d", (rand() % 10) + 1);

    printf("\n\nThank you for consulting with me, %s. May your journey be blessed.\n", name);

    return 0;
}