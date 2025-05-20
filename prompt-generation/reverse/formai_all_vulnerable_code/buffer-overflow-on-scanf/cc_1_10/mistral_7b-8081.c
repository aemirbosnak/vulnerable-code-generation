//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void string_to_lower(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

// Recursive function to calculate Levenshtein Distance
int levenshtein_distance(char *str1, char *str2, int m, int n) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    char char1 = str1[m - 1];
    char char2 = str2[n - 1];

    // Cost of replacement if characters are same
    int cost_replacement = (char1 == char2) ? 0 : 1;

    int min = 3;

    // Minimum of cost of replacement, deletion of character from str1,
    // and deletion of character from str2
    if (cost_replacement <= min) {
        min = cost_replacement;
    }

    // Cost of deletion of character from str1
    int cost_deletion_str1 = levenshtein_distance(str1, str2, m, n - 1) + 1;

    // Cost of deletion of character from str2
    int cost_deletion_str2 = levenshtein_distance(str1, str2, m - 1, n) + 1;

    // Pick the minimum of all the costs
    return min;
}

int main() {
    char str1[100], str2[100];
    int length_str1, length_str2;

    printf("Enter first string: ");
    scanf("%s", str1);
    length_str1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    length_str2 = strlen(str2);

    // Convert strings to lowercase
    string_to_lower(str1);
    string_to_lower(str2);

    // Call recursive function to calculate Levenshtein Distance
    int distance = levenshtein_distance(str1, str2, length_str1, length_str2);

    printf("Levenshtein Distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}