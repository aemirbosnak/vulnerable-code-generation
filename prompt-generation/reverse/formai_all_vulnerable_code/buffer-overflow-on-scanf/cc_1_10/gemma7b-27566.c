//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char sideA[20], sideB[20];
    int i, j, k, flag = 0, count = 0;

    printf("Enter the name of the side you belong to: ");
    scanf("%s", sideA);

    printf("Enter the name of the side you are fighting against: ");
    scanf("%s", sideB);

    printf("Enter the number of fighters from each side: ");
    scanf("%d", &i);

    printf("Enter the names of the fighters from each side: ");
    for (j = 0; j < i; j++)
    {
        scanf("%s", sideA[j]);
    }

    for (k = 0; k < i; k++)
    {
        scanf("%s", sideB[k]);
    }

    printf("The battle begins!\n");

    for (k = 0; k < 10; k++)
    {
        if (flag == 0)
        {
            printf("%s fighter %d strikes a blow to the %s fighter %d.\n", sideA, count, sideB, count);
            count++;
        }
        else
        {
            printf("%s fighter %d parries the blow from the %s fighter %d.\n", sideA, count, sideB, count);
            count++;
        }

        if (count == i)
        {
            flag = 1;
            printf("The battle ends.\n");
            break;
        }
    }

    return 0;
}