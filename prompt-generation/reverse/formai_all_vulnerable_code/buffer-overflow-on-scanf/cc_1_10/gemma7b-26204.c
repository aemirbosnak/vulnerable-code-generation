//Gemma-7B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int i, j, k, l, n, m, data[MAX], freq[MAX], maxFreq = 0, pos = 0;
    char str[MAX];

    printf("Happy Data Mining, my friend!\n");
    printf("Please enter a string: ");
    scanf("%s", str);

    n = strlen(str);
    m = n / MAX;

    for (i = 0; i < m; i++)
    {
        data[i] = str[i * MAX] - 96;
    }

    for (i = 0; i < m; i++)
    {
        freq[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (data[i] == data[j])
            {
                freq[i]++;
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            pos = i;
        }
    }

    printf("The character with the maximum frequency is: %c", data[pos]);
    printf("\nThe maximum frequency is: %d", maxFreq);

    return 0;
}