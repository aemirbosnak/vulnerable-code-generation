//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <string.h>

// Function to calculate minimum of 3 numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;

    // Creating a table to store Levenshtein Distance between each combination of substrings
    int table[len1 + 1][len2 + 1];

    // Initializing the first row and column of the table with values corresponding to empty substrings
    for (i = 0; i <= len1; i++) {
        table[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        table[0][j] = j;
    }

    // Filling up the table by calculating Levenshtein Distance between each combination of substrings
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]);
            }
        }
    }

    // Returning the final value of Levenshtein Distance between the two strings
    return table[len1][len2];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}