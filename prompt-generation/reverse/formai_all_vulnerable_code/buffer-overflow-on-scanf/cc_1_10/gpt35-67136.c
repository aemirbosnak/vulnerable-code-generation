//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to calculate Levenshtein distance between two strings
int Levenshtein_distance(char s1[], char s2[]) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store distances
    int dist[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            // If first string is empty, insert all characters of the second string
            if (i == 0) 
                dist[i][j] = j;

            // If second string is empty, delete all characters of the first string
            else if (j == 0) 
                dist[i][j] = i;

            // If last characters are same in both strings, ignore the last character and recur for the remaining string
            else if (s1[i-1] == s2[j-1]) 
                dist[i][j] = dist[i-1][j-1];

            // If the last character is different, consider all possibilities and find the minimum
            else 
                dist[i][j] = 1 + min(dist[i][j-1],      // Insert
                                   dist[i-1][j],      // Remove
                                   dist[i-1][j-1]);   // Replace
        }
    }

    // Return the distance between the two strings
    return dist[m][n];
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = Levenshtein_distance(str1, str2);

    printf("Levenshtein distance between %s and %s is %d", str1, str2, distance);

    return 0;
}