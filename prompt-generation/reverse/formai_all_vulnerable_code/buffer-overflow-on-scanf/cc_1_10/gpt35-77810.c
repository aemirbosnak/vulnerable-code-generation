//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    srand(time(NULL));

    printf("*** Welcome to the Futuristic Automated Fortune Teller! ***\n\n");

    printf("Please think of a number between 1 and 10 and enter it below:\n");
    scanf("%d", &num);

    if (num < 1 || num > 10)
    {
        printf("\nError: Invalid input. Please enter a number between 1 and 10.\n");
        return 0;
    }

    printf("\nThank you for choosing the Automated Fortune Teller.\n");
    printf("As you know, the year is 2050 and technology has advanced exponentially.\n");

    printf("\nGenerating fortune...");
    sleep(2);

    printf("\nHere is your fortune for today: ");

    switch (rand() % 5 + 1)
    {
        case 1:
            printf("You will discover a new source of renewable energy.\n");
            break;
        case 2:
            printf("You will meet a significant other through virtual reality.\n");
            break;
        case 3:
            printf("You will be the first person to travel to Mars.\n");
            break;
        case 4:
            printf("You will invent a device that changes the way we communicate.\n");
            break;
        case 5:
            printf("You will win the Nobel Prize for your contributions to science.\n");
            break;
    }

    printf("\nThank you for using the Futuristic Automated Fortune Teller!\n");

    return 0;
}