//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int x, int y, int z)
{
    if(x <= y && x <= z)
        return x;
    else if(y <= x && y <= z)
        return y;
    else
        return z;
}

int levenshtein_distance(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    int dist[s_len + 1][t_len + 1];

    for(int i = 0; i <= s_len; i++)
        dist[i][0] = i;
    
    for(int j = 0; j <= t_len; j++)
        dist[0][j] = j;

    for(int j = 1; j <= t_len; j++)
    {
        for(int i = 1; i <= s_len; i++)
        {
            if(s[i - 1] == t[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + 1);
        }
    }

    return dist[s_len][t_len];
}

int main()
{
    char s[MAX_LEN], t[MAX_LEN];

    printf("Enter the first string: ");
    scanf("%s", s);

    printf("Enter the second string: ");
    scanf("%s", t);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s, t, levenshtein_distance(s, t));

    return 0;
}