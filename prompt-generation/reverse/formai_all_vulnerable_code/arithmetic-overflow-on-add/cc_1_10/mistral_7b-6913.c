//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function to find minimum of three numbers
int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *str1, char *str2, int m, int n) {
    int cost[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; str1[i] != '\0'; i++)
        cost[i][0] = i + 1;

    for (int j = 0; str2[j] != '\0'; j++)
        cost[0][j] = j + 1;

    for (int i = 1; str1[i] != '\0'; i++) {
        for (int j = 1; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j])
                cost[i][j] = cost[i - 1][j - 1];
            else
                cost[i][j] = 1 + min(cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1]);
        }
    }

    return cost[m][n];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int m, n;

    // Input two strings in the post-apocalyptic world
    printf("In the ruins of the old world, enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Determine the length of the strings
    m = strlen(str1);
    n = strlen(str2);

    // Calculate Levenshtein Distance
    int distance = levenshteinDistance(str1, str2, m, n);

    // Output the result in a dramatic way
    printf("The strings '%s' and '%s' have a Levenshtein Distance of %d.\n", str1, str2, distance);

    return 0;
}