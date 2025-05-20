//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, count = 0, total = 0, arr[MAX], arr2[MAX];

    printf("Good evening, dear Watson. We are investigating a case of a stolen diamond. Please provide me with the number of suspects involved:** ");
    scanf("%d", &n);

    printf("Now, tell me the names of the suspects:");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Please describe the sequence of events:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (k = 0; k < n; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }
                if (arr2[i] - arr2[j] == arr2[k] - arr2[j])
                {
                    count++;
                }
            }
        }
    }

    total = count / (n - 1);
    printf("The number of suspicious transactions is: %d", total);

    return 0;
}