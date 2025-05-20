//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include<stdio.h>
#include<string.h>

int levenshtein_distance(char word1[], char word2[]) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int distance_matrix[len1+1][len2+1];  // Matrix to store the distance
    
    // initializing the matrix
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance_matrix[i][j] = j;
            }
            else if (j == 0) {
                distance_matrix[i][j] = i;
            }
            else {
                distance_matrix[i][j] = 0;
            }
        }
    }
    
    // Calculating the distance using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i-1] == word2[j-1]) {
                distance_matrix[i][j] = distance_matrix[i-1][j-1];
            }
            else {
                int min_distance = distance_matrix[i-1][j-1];
                if (distance_matrix[i][j-1] < min_distance) {
                    min_distance = distance_matrix[i][j-1];
                }
                if (distance_matrix[i-1][j] < min_distance) {
                    min_distance = distance_matrix[i-1][j];
                }
                distance_matrix[i][j] = min_distance + 1;
            }
        }
    }
    
    return distance_matrix[len1][len2];
}

int main() {
    char word1[100], word2[100];
    
    printf("Enter first word: ");
    scanf("%s", word1);
    
    printf("Enter second word: ");
    scanf("%s", word2);
    
    int distance = levenshtein_distance(word1, word2);
    
    printf("Levenshtein distance between %s and %s is %d.", word1, word2, distance);
    
    return 0;
}