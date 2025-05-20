//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char genome[100000];
    int i, j, k, l, m, n, o, p, q;

    printf("Enter the number of nucleotides in the genome: ");
    scanf("%d", &n);

    printf("Enter the genome sequence: ");
    scanf("%s", genome);

    for (i = 0; i < n; i++)
    {
        printf("%c", genome[i]);
    }

    printf("\nThe number of adenines in the genome is: ");
    for (i = 0; i < n; i++)
    {
        if (genome[i] == 'A')
        {
            printf("%d", 1);
        }
    }

    printf("\nThe number of cytosines in the genome is: ");
    for (i = 0; i < n; i++)
    {
        if (genome[i] == 'C')
        {
            printf("%d", 1);
        }
    }

    printf("\nThe number of guanos in the genome is: ");
    for (i = 0; i < n; i++)
    {
        if (genome[i] == 'G')
        {
            printf("%d", 1);
        }
    }

    printf("\nThe number of thymines in the genome is: ");
    for (i = 0; i < n; i++)
    {
        if (genome[i] == 'T')
        {
            printf("%d", 1);
        }
    }

    return 0;
}