//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000    // Maximum length of the two strings

// Function that calculates the minimum between three numbers
int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function that calculates the Levenshtein Distance between two strings
int levenshteinDistance(char *str1, char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    int distance[MAX_LENGTH][MAX_LENGTH];    // 2D array to store the distances
    int i, j;

    // Initialize the first row and the first column of the array
    for (i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    // Calculate the distance
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else {
                distance[i][j] = minimum(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + 1);
            }
        }
    }

    // Return the final result
    return distance[len1][len2];
}

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    // Get the two strings from the user
    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);

    // Remove the newline character from the end of the strings
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    // Calculate the Levenshtein Distance between the two strings
    int distance = levenshteinDistance(str1, str2);

    // Print the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}