//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int min(int a, int b, int c) {  // calculate the minimum value of three numbers
    if (a < b && a < c) { 
        return a; 
    } 
    else if (b < a && b < c) { 
        return b; 
    } 
    else { 
        return c; 
    } 
}

int levenshtein_distance(char *word1, char *word2) {
    int len1 = strlen(word1);  // get the length of the first word
    int len2 = strlen(word2);  // get the length of the second word
    int i, j, cost;  // initialize variables for iteration and cost calculation
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));  // create matrix to store calculations
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int *));
    }
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;  // initialize the first column
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;  // initialize the first row
    }
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (word1[i-1] == word2[j-1]) ? 0 : 1;  // calculate the cost
            matrix[i][j] = min(matrix[i-1][j] + 1,
                               matrix[i][j-1] + 1,
                               matrix[i-1][j-1] + cost);  // determine the minimum value
        }
    }
    int distance = matrix[len1][len2];  // store the final distance value
    for (i = 0; i <= len1; i++) {
        free(matrix[i]);  // free memory used by matrix
    }
    free(matrix);
    return distance;
}

int main() {
    char word1[50], word2[50];  // initialize character arrays to store input strings
    printf("Enter two words: ");
    scanf("%s %s", word1, word2);  // read input strings
    int distance = levenshtein_distance(word1, word2);  // calculate the Levenshtein distance
    printf("The Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);  // output the result
    return 0;  // end main function
}