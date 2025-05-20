//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three numbers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *str1, char *str2, int len1, int len2) {
    // Create a 2D array to store the distances
    int dist[len1 + 1][len2 + 1];
    // Initialize the first row and column of the array
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }
    // Fill the rest of the array with the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = min(dist[i - 1][j - 1], dist[i][j - 1], dist[i - 1][j]) + 1;
            }
        }
    }
    // Return the distance between the strings
    return dist[len1][len2];
}

int main() {
    char str1[100], str2[100]; // Declare two character arrays to store the strings
    int len1, len2; // Declare two integers to store the lengths of the strings
    // Get input from the user
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    // Remove the newline character from the end of the strings
    len1 = strlen(str1) - 1;
    len2 = strlen(str2) - 1;
    str1[len1] = '\0';
    str2[len2] = '\0';
    // Calculate the Levenshtein Distance between the strings
    int dist = levenshteinDistance(str1, str2, len1, len2);
    // Print the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, dist);
    return 0;
}