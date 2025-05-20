//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX 100

int min(int a, int b, int c) {
    if(a <= b && a <= c) {
        return a;
    }
    if(b <= a && b <= c) {
        return b;
    }
    return c;
}

int levenshtein(char *str1, char *str2, int len1, int len2) {
    int dist[MAX][MAX];
    int i, j, cost;

    for(i = 0; i <= len1; i++) {
        for(j = 0; j <= len2; j++) {
            if(i == 0) {
                dist[i][j] = j;
            } else if(j == 0) {
                dist[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                cost = 1;
                dist[i][j] = min(dist[i-1][j] + 1, dist[i][j-1] + 1, dist[i-1][j-1] + cost);
            }
        }
    }
    return dist[len1][len2];
}

int main() {
    char str1[MAX], str2[MAX];
    int len1, len2, distance;

    printf("Enter string 1: ");
    fgets(str1, MAX, stdin);
    printf("Enter string 2: ");
    fgets(str2, MAX, stdin);

    len1 = strlen(str1) - 1;
    len2 = strlen(str2) - 1;

    distance = levenshtein(str1, str2, len1, len2);

    printf("Levenshtein distance between \n'%s' and \n'%s' is: %d\n", str1, str2, distance);
    return 0;
}