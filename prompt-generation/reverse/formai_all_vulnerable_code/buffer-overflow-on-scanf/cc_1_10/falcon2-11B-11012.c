//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the levenshtein distance
int levenshteinDistance(char* str1, char* str2) {
    // create two arrays to store the lengths of the strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int *costs = (int *)malloc((len1 + 1) * sizeof(int));
    int *prevRow = (int *)malloc((len2 + 1) * sizeof(int));

    // initialize the first row of the matrix
    for (int i = 0; i <= len1; i++) {
        costs[i] = i;
    }

    // initialize the first column of the matrix
    for (int i = 0; i <= len2; i++) {
        prevRow[i] = i;
    }

    // fill in the rest of the matrix
    for (int i = 2; i <= len1; i++) {
        for (int j = 2; j <= len2; j++) {
            int cost1 = (str1[i-1]!= str2[j-1])? 1 : 0;
            int cost2 = prevRow[j-1] + 1;
            int cost3 = costs[i-1] + 1;
            int minCost = cost1 < cost2? cost1 : cost2;
            minCost = minCost < cost3? minCost : cost3;
            costs[i] = minCost;
            prevRow[j] = minCost;
        }
    }

    // return the levenshtein distance
    return costs[len1];
}

int main() {
    // prompt the user for the two strings
    printf("Enter the first string: ");
    char str1[100];
    scanf("%s", str1);

    printf("Enter the second string: ");
    char str2[100];
    scanf("%s", str2);

    // calculate the levenshtein distance
    int distance = levenshteinDistance(str1, str2);

    // print the result
    printf("The levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}