//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if(a < b) {
        if(a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if(b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Declare the table to store the minimum distances
    int dist_table[MAX_LEN][MAX_LEN];
    
    // Initialize the table
    for(int i = 0; i < len1; i++) {
        dist_table[i][0] = i;
    }
    for(int j = 0; j < len2; j++) {
        dist_table[0][j] = j;
    }
    
    // Compute the minimum distances
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(str1[i-1] == str2[j-1]) {
                dist_table[i][j] = dist_table[i-1][j-1];
            } else {
                dist_table[i][j] = min(dist_table[i-1][j], dist_table[i][j-1], dist_table[i-1][j-1]) + 1;
            }
        }
    }
    
    // Return the minimum distance between the two strings
    return dist_table[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    
    // Get the two strings from the user
    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strlen(str1)-1] = '\0';
    
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strlen(str2)-1] = '\0';
    
    // Compute the Levenshtein distance and print it to the console
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    
    return 0;
}