//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three numbers
int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a matrix to store distances
    int **distance_matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i][0] = i; // Deleting all characters
    }
    
    for (int j = 0; j <= len_str2; j++) {
        distance_matrix[0][j] = j; // Inserting all characters
    }

    // Fill in the distance matrix
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,     // Deletion
                distance_matrix[i][j - 1] + 1,     // Insertion
                distance_matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Get the final distance and free the matrix
    int distance = distance_matrix[len_str1][len_str2];
    for (int i = 0; i <= len_str1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return distance;
}

int main() {
    char str1[100];
    char str2[100];
    
    printf("Welcome to Stringland, where we calculate the distances between words!\n");
    printf("Please enter the first word: ");
    scanf("%s", str1);
    printf("Please enter the second word: ");
    scanf("%s", str2);
    
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    if (distance == 0) {
        printf("The words are identical! They are best friends in Stringland!\n");
    } else if (distance <= 2) {
        printf("The words are closely related in Stringland's neighborhood!\n");
    } else {
        printf("The words are quite distant in Stringland, perhaps on opposite sides of the kingdom!\n");
    }

    printf("Thank you for visiting Stringland! May your words always connect!\n");
    return 0;
}