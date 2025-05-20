//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, n;

    printf("C Robot Movement Control\n");
    printf("-------------------\n");

    printf("Enter the number of steps: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the direction (N/S/E/W): ");
        scanf("%c", &k);

        switch (k)
        {
            case 'N':
                printf("Moving north...\n");
                for (j = 0; j < 10; j++)
                {
                    printf("Buzz... ");
                }
                printf("\n");
                break;

            case 'S':
                printf("Moving south...\n");
                for (j = 0; j < 10; j++)
                {
                    printf("Buzz... ");
                }
                printf("\n");
                break;

            case 'E':
                printf("Moving east...\n");
                for (j = 0; j < 10; j++)
                {
                    printf("Buzz... ");
                }
                printf("\n");
                break;

            case 'W':
                printf("Moving west...\n");
                for (j = 0; j < 10; j++)
                {
                    printf("Buzz... ");
                }
                printf("\n");
                break;

            default:
                printf("Invalid direction.\n");
                break;
        }
    }

    return 0;
}