//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If either of strings is empty, return length of other string
    if (len1 == 0) {
        return len2;
    } else if (len2 == 0) {
        return len1;
    }

    int distanceMatrix[len1 + 1][len2 + 1];

    // Initialize first column
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i][0] = i;
    }

    // Initialize first row
    for (int j = 0; j <= len2; j++) {
        distanceMatrix[0][j] = j;
    }

    // Iterate over entire matrix to calculate Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitutionCost = str1[i - 1] == str2[j - 1] ? 0 : 1;
            int deletionCost = distanceMatrix[i - 1][j] + 1;
            int insertionCost = distanceMatrix[i][j - 1] + 1;
            int substitutionOrMatchCost = distanceMatrix[i - 1][j - 1] + substitutionCost;
            distanceMatrix[i][j] = min(deletionCost, insertionCost, substitutionOrMatchCost);
        }
    }

    return distanceMatrix[len1][len2];
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}