//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, a, b, c, d, e, f, g;
    char name1[20], name2[20];

    printf("Enter the name of the first character: ");
    scanf("%s", name1);

    printf("Enter the name of the second character: ");
    scanf("%s", name2);

    printf("Enter the number of rounds: ");
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        printf("Round %d:\n", i + 1);

        printf("Enter the number of attacks for %s: ", name1);
        scanf("%d", &b);

        printf("Enter the number of attacks for %s: ", name2);
        scanf("%d", &c);

        d = rand() % 10 + 1;
        e = rand() % 10 + 1;

        printf("The number of wounds inflicted by %s is: ", name1);
        printf("%d\n", d);

        printf("The number of wounds inflicted by %s is: ", name2);
        printf("%d\n", e);

        if (d > e)
        {
            printf("%s wins the round!\n", name1);
        }
        else if (e > d)
        {
            printf("%s wins the round!\n", name2);
        }
        else
        {
            printf("It's a draw!\n");
        }

        printf("\n");
    }

    printf("The winner of the battle is: ");
    if (strcmp(name1, name2) == 0)
    {
        printf("It's a draw!\n");
    }
    else
    {
        printf("%s\n", name1);
    }

    return 0;
}