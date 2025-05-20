//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c);

int main()
{
    char str1[100], str2[100];
    int len1, len2, i, j, cost[100][100];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for(i=0;i<=len1;i++)
        cost[i][0] = i;

    for(j=0;j<=len2;j++)
        cost[0][j] = j;

    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1] == str2[j-1])
                cost[i][j] = cost[i-1][j-1];
            else
                cost[i][j] = min(cost[i-1][j], cost[i][j-1], cost[i-1][j-1]) + 1;
        }
    }

    printf("Levenshtein distance between %s and %s is %d", str1, str2, cost[len1][len2]);

    return 0;
}

int min(int a, int b, int c)
{
    int temp = a;
    if(temp > b)
        temp = b;
    if(temp > c)
        temp = c;

    return temp;
}