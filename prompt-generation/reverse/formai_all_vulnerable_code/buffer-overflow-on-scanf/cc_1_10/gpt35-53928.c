//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find minimum of three values
int minimum(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    return min;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If either of the strings are blank, return the length of the other string
    if(len1 == 0){
        return len2;
    }
    if(len2 == 0){
        return len1;
    }

    // Initialise the matrix
    int matrix[MAX_LENGTH][MAX_LENGTH];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i == 0){
                matrix[i][j] = j;
            }
            else if(j == 0){
                matrix[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                matrix[i][j] = 1 + minimum(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }

    // Return the Levenshtein Distance
    return matrix[len1][len2];
}

int main(){
    // Test the function
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, levenshteinDistance(str1, str2));
    return 0;
}