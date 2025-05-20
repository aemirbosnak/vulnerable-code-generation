//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include<stdio.h>
#include<string.h>

int mindist(int x,int y,int z)
{
    if(x <= y && x <= z)
    {
        return x;
    }
    else if(y <= x && y <= z)
    {
        return y;
    }
    else
    {
        return z;
    }
}

int levenshtein(char s1[], char s2[], int len1, int len2)
{
    int distance[len1+1][len2+1];

    for(int i = 0;i <= len1;i++)
    {
        for(int j = 0;j <= len2;j++)
        {
            if(i == 0)
            {
                distance[i][j] = j;
            }
            else if(j == 0)
            {
                distance[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1])
            {
                distance[i][j] = distance[i-1][j-1];
            }
            else
            {
                distance[i][j] = 1 + mindist(distance[i-1][j],distance[i][j-1],distance[i-1][j-1]);
            }
        }
    }

    return distance[len1][len2];
}

int main()
{
    char str1[100], str2[100];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dist = levenshtein(str1,str2,len1,len2);
    printf("Levenshtein Distance: %d",dist);

    return 0;
}