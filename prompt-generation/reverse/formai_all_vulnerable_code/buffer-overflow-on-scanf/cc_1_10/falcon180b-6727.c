//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = (len1 > len2)? len1 : len2;
    int distance[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    for (i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = (distance[i - 1][j] > distance[i][j - 1])? distance[i - 1][j] : distance[i][j - 1];
                distance[i][j]++;
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}