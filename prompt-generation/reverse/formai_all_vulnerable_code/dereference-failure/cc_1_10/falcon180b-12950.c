//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int levenshtein_distance(char* string1, char* string2) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    int* dp = calloc(len1 + 1, sizeof(int));
    int* prev = calloc(len1 + 1, sizeof(int));

    for (int i = 0; i <= len1; i++) {
        dp[i] = i;
        prev[i] = -1;
    }

    for (int j = 0; j <= len2; j++) {
        dp[0] = j;
        int prev_j = -1;

        for (int i = 1; i <= len1; i++) {
            if (string1[i - 1] == string2[j - 1]) {
                dp[i] = dp[i - 1];
                prev[i] = prev[i - 1];
            } else {
                int cost = dp[i - 1] + 1;

                if (dp[i] > cost) {
                    dp[i] = cost;
                    prev[i] = prev[i - 1];
                }
            }

            if (dp[i] == dp[i - 1] + 1) {
                prev[i] = i - 1;
            } else {
                prev[i] = prev_j;
            }

            prev_j = i - 1;
        }
    }

    int distance = dp[len1];
    free(dp);
    free(prev);

    return distance;
}

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];

    printf("Enter first string: ");
    fgets(string1, MAX_STRING_LENGTH, stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(string2, MAX_STRING_LENGTH, stdin);
    string2[strcspn(string2, "\n")] = '\0';

    int distance = levenshtein_distance(string1, string2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", string1, string2, distance);

    return 0;
}