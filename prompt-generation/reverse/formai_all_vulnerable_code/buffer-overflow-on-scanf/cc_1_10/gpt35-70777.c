//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int minimum(int a, int b, int c);

int LevenshteinDistance(char *s, char *t);

int main() {
    char firstString[MAX_LENGTH], secondString[MAX_LENGTH];
    
    printf("Enter the first string: ");
    scanf("%s", firstString);

    printf("Enter the second string: ");
    scanf("%s", secondString);

    int distance = LevenshteinDistance(firstString, secondString);
    printf("\nThe Levenshtein distance between %s and %s is %d\n", firstString, secondString, distance);
    
    return 0;
}

int minimum(int a, int b, int c) {
    int min = a < b ? a : b;
    min = c < min ? c : min;
    return min;
}

int LevenshteinDistance(char *s, char *t) {
    int sLength = strlen(s);
    int tLength = strlen(t);
    int LevenshteinMatrix[sLength+1][tLength+1];

    for(int i = 0; i <= sLength; i++) {
        LevenshteinMatrix[i][0] = i; 
    }
    for(int j = 0; j <= tLength; j++) {
        LevenshteinMatrix[0][j] = j; 
    }

    for(int i = 1; i <= sLength; i++) {
        for(int j = 1; j <= tLength; j++) {
            int cost = s[i-1] == t[j-1] ? 0 : 1;
            LevenshteinMatrix[i][j] = minimum(LevenshteinMatrix[i-1][j] + 1, 
                                               LevenshteinMatrix[i][j-1] + 1, 
                                               LevenshteinMatrix[i-1][j-1] + cost);
        }
    }

    return LevenshteinMatrix[sLength][tLength];
}