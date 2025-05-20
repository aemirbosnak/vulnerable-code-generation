//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Calculate the minimum of three values
int minimum(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}

// Calculate the Levenshtein Distance between two strings
int levenshtein_distance(char *s, char *t) {
    int i, j, s_len, t_len, substitution_cost, substitution;
    s_len = strlen(s);
    t_len = strlen(t);
    int dist[s_len + 1][t_len + 1]; // Create a distance matrix (two-dimensional array)

    // Initialize the matrix with the default values
    for(i = 0; i <= s_len; i++) {
        dist[i][0] = i;
    }
    for(j = 0; j <= t_len; j++) {
        dist[0][j] = j;
    }

    // Calculate the minimum cost of operations to get from s to t
    for(j = 1; j <= t_len; j++) {
        for(i = 1; i <= s_len; i++) {
            if(s[i - 1] == t[j - 1]) { // No cost if characters match
                substitution_cost = 0;
            } else {
                substitution_cost = 1; // Cost of substituting a character
            }
            substitution = dist[i - 1][j - 1] + substitution_cost; // Substitution cost
            dist[i][j] = minimum(dist[i - 1][j] + 1, dist[i][j - 1] + 1, substitution); // Minimum of three costs
        }
    }
    return dist[s_len][t_len]; // Return the Levenshtein Distance between s and t
}

int main() {
    char s1[25], s2[25]; // Define two strings to compare
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    printf("The Levenshtein Distance between %s and %s is %d.\n", s1, s2, levenshtein_distance(s1, s2)); // Calculate and print the distance between the strings
    return 0;
}