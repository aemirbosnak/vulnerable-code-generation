//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, j, k;
    char ch;
    time_t t;
    srand(time(NULL));

    printf("Enter the haunted house number: ");
    scanf("%d", &i);

    switch (i)
    {
        case 1:
            printf("You have chosen the haunted house of Mrs. Amelia.\n");
            break;
        case 2:
            printf("You have chosen the haunted house of Mr. Jones.\n");
            break;
        case 3:
            printf("You have chosen the haunted house of the Grady family.\n");
            break;
        default:
            printf("Invalid haunted house number.\n");
            break;
    }

    t = time(NULL);
    for (k = 0; k < 5; k++)
    {
        printf("\n");
        for (j = 0; j < 20; j++)
        {
            printf("%c ", rand() % 26 + 65);
        }
        printf("\n");
        sleep(rand() % 3);
    }

    printf("\nAre you scared? (Y/N): ");
    scanf(" %c", &ch);

    if (ch == 'Y')
    {
        printf("You should be. This is a haunted house.\n");
    }
    else
    {
        printf("I'm not sure if you're scared or not.\n");
    }

    return;
}