//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void print_matrix(int dist[MAX_LEN][MAX_LEN]) {
    int i, j;
    for(i=0; i<MAX_LEN; i++) {
        for(j=0; j<MAX_LEN; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist[MAX_LEN][MAX_LEN];
    int i, j;

    for(i=0; i<MAX_LEN; i++) {
        for(j=0; j<MAX_LEN; j++) {
            if(i == 0)
                dist[i][j] = j;
            else if(j == 0)
                dist[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                dist[i][j] = dist[i-1][j-1];
            else
                dist[i][j] = 1 + min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]);
        }
    }

    return dist[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);
    int dist = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, dist);
    return 0;
}