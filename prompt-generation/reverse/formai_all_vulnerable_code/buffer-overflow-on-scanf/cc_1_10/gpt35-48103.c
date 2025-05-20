//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include<stdio.h>
#include<string.h>

int min(int x, int y, int z);

int levenshteinDistance(char *str1, char *str2);

int main()
{
    char str1[100], str2[100];
    printf("Let's calculate Levenshtein Distance!\n");
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    
    printf("\n\nCongrats! The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    printf("Thank you for using my program! Cheers!\n");
    return 0;
}

int min(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

int levenshteinDistance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        distance[i][0] = i;

    for (int j = 0; j <= len2; j++)
        distance[0][j] = j;

    for (int j = 1; j <= len2; j++)
    {
        for (int i = 1; i <= len1; i++)
        {
            if (str1[i - 1] == str2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = min(distance[i - 1][j - 1], distance[i][j - 1], distance[i - 1][j]) + 1;
        }
    }
    return distance[len1][len2];
}