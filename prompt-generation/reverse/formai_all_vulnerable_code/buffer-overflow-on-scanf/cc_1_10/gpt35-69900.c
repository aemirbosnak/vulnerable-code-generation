//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    else if (y <= x && y <= z) {
        return y;
    }
    else {
        return z;
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D matrix to store the distances
    int distanceMatrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        distanceMatrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
            }
            else {
                distanceMatrix[i][j] = min(distanceMatrix[i - 1][j - 1], distanceMatrix[i][j - 1], distanceMatrix[i - 1][j]) + 1;
            }
        }
    }

    // Return the final entry in the matrix
    return distanceMatrix[len1][len2];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, levenshteinDistance(str1, str2));
    return 0;
}