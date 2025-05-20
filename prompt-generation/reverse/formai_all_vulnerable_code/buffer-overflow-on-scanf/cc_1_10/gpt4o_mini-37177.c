//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Recursive function to calculate Levenshtein distance
int levenshtein_recursive(const char *s1, const char *s2, int len1, int len2) {
    // Base cases
    if (len1 == 0) return len2;  // If first string is empty
    if (len2 == 0) return len1;  // If second string is empty

    // Check if last characters are the same
    if (s1[len1 - 1] == s2[len2 - 1]) {
        return levenshtein_recursive(s1, s2, len1 - 1, len2 - 1);
    }

    // Compute costs of the three possible operations
    int insert_cost = levenshtein_recursive(s1, s2, len1, len2 - 1);
    int delete_cost = levenshtein_recursive(s1, s2, len1 - 1, len2);
    int replace_cost = levenshtein_recursive(s1, s2, len1 - 1, len2 - 1);

    // Return the minimum of the three operations plus one
    return 1 + (insert_cost < delete_cost ? (insert_cost < replace_cost ? insert_cost : replace_cost) : (delete_cost < replace_cost ? delete_cost : replace_cost));
}

int main() {
    char str1[100], str2[100];

    while (1) {
        printf("\nEnter first string (or 'exit' to quit): ");
        scanf("%s", str1);
        if (strcmp(str1, "exit") == 0) {
            break;
        }

        printf("Enter second string: ");
        scanf("%s", str2);

        // Calculate the lengths of the strings
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        // Compute Levenshtein distance
        int distance = levenshtein_recursive(str1, str2, len1, len2);
        
        // Output the result
        printf("Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    }

    return 0;
}