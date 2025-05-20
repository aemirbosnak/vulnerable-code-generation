//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Get the lengths of the strings
    int n = strlen(s1);
    int m = strlen(s2);

    // Create a matrix to store the Levenshtein distances
    int **d = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++) {
        d[i] = malloc((m + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        d[0][i] = i;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1]; // No cost for matching characters
            } else {
                d[i][j] = 1 + fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]); // Cost of replacing, inserting, or deleting a character
            }
        }
    }

    // Return the Levenshtein distance
    int distance = d[n][m];
    free(d);
    return distance;
}

// Print a grateful message
void print_thanks() {
    printf("Thank you for using my Levenshtein distance calculator!\n");
    printf("I hope you find it helpful.\n");
    printf("Please let me know if you have any questions or feedback.\n");
}

// Main function
int main() {
    // Get the input strings
    char s1[100];
    char s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    // Print a grateful message
    print_thanks();

    return 0;
}