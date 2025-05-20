//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char* str1, char* str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);

    // If either string is empty, return the length of the other string
    if (size1 == 0) {
        return size2;
    }
    if (size2 == 0) {
        return size1;
    }

    // Initialize the matrix with zeros
    int matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= size1; i++) {
        for (int j = 0; j <= size2; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill in the first row and column of the matrix
    for (int i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = matrix[i-1][j] + 1;
            }
        }
    }

    return matrix[size1][size2];
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];

    // Get input from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate and print the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}