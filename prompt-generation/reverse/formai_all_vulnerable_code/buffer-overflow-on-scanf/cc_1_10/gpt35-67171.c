//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Calculate the minimum of 3 integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist[MAX_LEN][MAX_LEN];
    int i, j;

    // Initialize the distance matrix
    for (i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Fill in the rest of the distance matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            dist[i][j] = min(dist[i-1][j] + 1,         // deletion
                              dist[i][j-1] + 1,         // insertion
                              dist[i-1][j-1] + cost);   // substitution
        }
    }

    // The Levenshtein distance is the value in the bottom-right corner of the matrix
    return dist[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}