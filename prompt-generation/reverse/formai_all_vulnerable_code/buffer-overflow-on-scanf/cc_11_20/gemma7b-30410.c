//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, n, m, x, y, z;
    float a, b, c, d, e, f, g, h;
    char ch;

    printf("Good evening, Mr. Holmes. Prepare for a mystery...\n");

    // Gather information
    printf("Please provide the number of suspects: ");
    scanf("%d", &n);

    printf("Enter the number of witnesses: ");
    scanf("%d", &m);

    // Create an array for suspects and their alibis
    char **suspect_alibi = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        suspect_alibi[i] = (char*)malloc(20 * sizeof(char));
    }

    // Gather suspect alibis
    for (i = 0; i < n; i++)
    {
        printf("Enter the alibi for suspect %d: ", i + 1);
        scanf("%s", suspect_alibi[i]);
    }

    // Create a matrix for witness testimonies
    int **witness_testimony = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
    {
        witness_testimony[i] = (int*)malloc(n * sizeof(int));
    }

    // Gather witness testimonies
    for (i = 0; i < m; i++)
    {
        printf("Enter the testimony of witness %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &witness_testimony[i][j]);
        }
    }

    // Analyze the evidence
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (witness_testimony[j][i] != suspect_alibi[i])
            {
                printf("Suspect %d is guilty!\n", i + 1);
                break;
            }
        }
    }

    if (i == n)
    {
        printf("No one was guilty.\n");
    }

    // Free memory
    for (i = 0; i < n; i++)
    {
        free(suspect_alibi[i]);
    }
    free(suspect_alibi);

    for (i = 0; i < m; i++)
    {
        free(witness_testimony[i]);
    }
    free(witness_testimony);

    printf("Thank you, Mr. Holmes, for another successful case.\n");

    return 0;
}