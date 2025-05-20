//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int* dp = malloc(sizeof(int) * (len1 + 1) * (len2 + 1));

    for (int i = 0; i <= len1; i++) {
        dp[i * (len2 + 1)] = i;
    }

    for (int j = 0; j <= len2; j++) {
        dp[(len1 + 1) * j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[(i - 1) * (len2 + 1) + j] = dp[(i - 1) * (len2 + 1) + j - 1] + 1;
            } else {
                dp[(i - 1) * (len2 + 1) + j] = dp[(i - 1) * (len2 + 1) + j - 1] + 1;
            }
        }
    }

    int distance = dp[(len1 - 1) * (len2 + 1) + len2];

    free(dp);

    return distance;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}