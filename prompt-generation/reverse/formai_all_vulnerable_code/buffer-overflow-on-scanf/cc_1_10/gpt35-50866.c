//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <string.h>

// function to calculate the minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

// function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(char* str1, char* str2, int len1, int len2) {
    // creating a 2D array to store the minimum distance between two strings to reach each character
    int distance[len1 + 1][len2 + 1];

    // initialize the array
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(
                    distance[i][j - 1], // insert
                    distance[i - 1][j], // remove
                    distance[i - 1][j - 1] // replace
                );
            }
        }
    }

    // return the minimum distance
    return distance[len1][len2];
}

// function to print the result
void print_result(char* str1, char* str2, int distance) {
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, distance);
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    print_result(str1, str2, distance);

    return 0;
}