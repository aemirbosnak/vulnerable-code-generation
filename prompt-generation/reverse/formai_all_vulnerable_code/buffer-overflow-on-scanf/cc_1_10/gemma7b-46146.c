//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i, j, n, m, choice;
    char ch;
    int haunted_house[10][10] = {{0}};

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            haunted_house[i][j] = rand() % 2;
        }
    }

    printf("Enter 1 to explore the haunted house, or 2 to leave: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("You have entered the haunted house.\n");
            system("CLS");
            for(n = 0; n < 5; n++)
            {
                for(m = 0; m < 5; m++)
                {
                    if(haunted_house[n][m] == 1)
                    {
                        printf("X ");
                    }
                    else
                    {
                        printf(". ");
                    }
                }
                printf("\n");
            }

            printf("Do you want to continue exploring the haunted house? (Y/N): ");
            scanf(" %c", &ch);

            if(ch == 'Y')
            {
                main();
            }
            else
            {
                printf("Thank you for visiting the haunted house.\n");
            }
            break;

        case 2:
            printf("You have left the haunted house.\n");
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}