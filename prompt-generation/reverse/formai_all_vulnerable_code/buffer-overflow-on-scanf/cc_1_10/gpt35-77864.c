//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: immersive
// Welcome to the Levenshtein Distance Calculator program!
// This program will take in two words and find their Levenshtein Distance, which is a measure of their similarity.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for finding the minimum of three values
int min(int a, int b, int c){
    int min = a;
    if (b < min){
        min = b;
    }
    if (c < min){
        min = c;
    }
    return min;
}

// Function for finding the Levenshtein Distance between two words
int levenshtein_distance(char *word1, char *word2, int len1, int len2){
    int matrix[len1 + 1][len2 + 1];
    int i, j, cost;
    
    // Initializing the matrix
    for (i = 0; i <= len1; i++){
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++){
        matrix[0][j] = j;
    }
    
    // Filling in the matrix using dynamic programming
    for (i = 1; i <= len1; i++){
        for (j = 1; j <= len2; j++){
            if (word1[i - 1] == word2[j - 1]){
                cost = 0;
            }
            else{
                cost = 1;
            }
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }
    
    // Returning the final value in the matrix
    return matrix[len1][len2];
}

int main(){
    // Prompting the user to enter two words
    printf("Enter the first word: ");
    char word1[100];
    scanf("%s", word1);
    printf("Enter the second word: ");
    char word2[100];
    scanf("%s", word2);
    
    // Finding the Levenshtein Distance between the two words
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int distance = levenshtein_distance(word1, word2, len1, len2);
    
    // Displaying the result to the user
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", word1, word2, distance);
    
    return 0;
}