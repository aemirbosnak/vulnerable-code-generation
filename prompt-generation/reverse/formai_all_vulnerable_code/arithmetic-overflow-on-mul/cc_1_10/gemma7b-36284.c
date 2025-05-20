//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int **freq = NULL;
    int i, j, k, n, m;

    printf("Enter the number of documents: ");
    scanf("%d", &n);

    data = (char **)malloc(n * MAX_SIZE);
    freq = (int **)malloc(n * MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("Enter the text for document %d: ", i + 1);
        scanf("%[^\n]%*c", data[i]);

        freq[i] = (int *)malloc(MAX_SIZE);
        for (j = 0; j < MAX_SIZE; j++)
            freq[i][j] = 0;

        k = 0;
        for (j = 0; data[i][j] != '\0'; j++)
        {
            char word[MAX_SIZE];
            word[0] = data[i][j];
            word[1] = '\0';

            if (freq[i][k] == 0)
            {
                freq[i][k] = 1;
                k++;
            }
            else
            {
                freq[i][k]++;
            }
        }
    }

    printf("Document Similarity Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                printf("  %d ", freq[i][j]);
            else
                printf("%d ", freq[i][j]);
        }
        printf("\n");
    }

    free(data);
    free(freq);

    return 0;
}