//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100

int levenshtein_distance(char *str1, char *str2);

int main() {
    char str1[MAX_STRING_LEN], str2[MAX_STRING_LEN];

    printf("Enter first string:\n");
    scanf("%s", str1);

    printf("Enter second string:\n");
    scanf("%s", str2);

    int dist = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between %s and %s is %d\n",
           str1, str2, dist);

    return 0;
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a matrix to store the distances
    int dist_matrix[len1+1][len2+1];

    // Initialize the first column and row of the matrix
    for(int i=0; i<=len1; i++) {
        dist_matrix[i][0] = i;
    }
    for(int j=0; j<=len2; j++) {
        dist_matrix[0][j] = j;
    }

    // Compute the distances for the rest of the matrix
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            // If the characters match, the cost is 0
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            // Take the minimum of the three adjacent cells and add the cost
            int deletion = dist_matrix[i-1][j] + 1;   // deletion
            int insertion = dist_matrix[i][j-1] + 1;   // insertion
            int substitution = dist_matrix[i-1][j-1] + cost; // substitution
            int min_cost = deletion;

            if (insertion < min_cost) {
                min_cost = insertion;
            }
            if (substitution < min_cost) {
                min_cost = substitution;
            }

            dist_matrix[i][j] = min_cost;
        }
    }

    return dist_matrix[len1][len2];
}