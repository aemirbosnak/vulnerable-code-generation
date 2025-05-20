//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculation function
int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create an array to store the Levenshtein distances
    int **d = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i < len1 + 1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the array
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    // Calculate the Levenshtein distance for each cell in the array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    return d[len1][len2];
}

// Function to print the Levenshtein distance matrix
void print_matrix(int **d, int len1, int len2) {
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Get the input strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}