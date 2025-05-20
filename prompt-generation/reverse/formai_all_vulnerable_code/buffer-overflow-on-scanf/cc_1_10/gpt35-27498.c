//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshtein_distance(char *s1, char *s2) {
    // get lengths of the strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // create the table that stores distance values
    int table[MAX_LENGTH + 1][MAX_LENGTH + 1];

    // initialize the first row and column
    for (int i = 0; i <= len1; i++) {
        table[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        table[0][j] = j;
    }

    // fill in the rest of the table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // if characters match, no operation needed
            if (s1[i - 1] == s2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                // calculate the minimum cost (insertion, deletion, substitution)
                table[i][j] = min(table[i - 1][j] + 1, // deletion
                                   table[i][j - 1] + 1, // insertion
                                   table[i - 1][j - 1] + 1 // substitution
                                   );
            }
        }
    }

    // return the final distance value
    return table[len1][len2];
}

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}