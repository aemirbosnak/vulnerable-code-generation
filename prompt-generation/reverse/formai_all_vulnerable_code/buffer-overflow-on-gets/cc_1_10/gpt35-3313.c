//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function calculates the minimum of three numbers.
int min(int a, int b, int c) {
    int minimum = a;
    if(b < minimum) {
        minimum = b;
    }
    if(c < minimum) {
        minimum = c;
    }
    return minimum;
}

// Recursive implementation of Levenshtein Distance algorithm.
int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    if(len1 == 0) {
        return len2;
    }
    if(len2 == 0) {
        return len1;
    }

    int cost;
    if(str1[len1 - 1] == str2[len2 - 1]) {
        cost = 0;
    } else {
        cost = 1;
    }

    return min(levenshtein_distance(str1, str2, len1 - 1, len2) + 1,
               levenshtein_distance(str1, str2, len1, len2 - 1) + 1,
               levenshtein_distance(str1, str2, len1 - 1, len2 - 1) + cost);        
}

// Main function
int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2,
        levenshtein_distance(str1, str2, strlen(str1), strlen(str2)));
    
    return 0;
}