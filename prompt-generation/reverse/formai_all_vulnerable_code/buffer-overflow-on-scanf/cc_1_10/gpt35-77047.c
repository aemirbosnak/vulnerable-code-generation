//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int x, int y, int z) {
    return (x < y) 
            ? ((x < z) ? x : z) 
            : ((y < z) ? y : z);
}

int levenshtein(char* s1, char* s2, int len1, int len2) {
    int distance[len2+1][len1+1];
    
    for (int i = 0; i <= len1; i++) {
        distance[0][i] = i;
    }
    for (int j = 0; j <= len2; j++) {
        distance[j][0] = j;
    }
    
    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            if (s1[i-1] == s2[j-1]) {
                distance[j][i] = distance[j-1][i-1];
            } else {
                distance[j][i] = 1 + min(distance[j-1][i], distance[j][i-1], distance[j-1][i-1]);
            }
        }
    }

    return distance[len2][len1];
}

int main() {
    char word1[MAX_LEN], word2[MAX_LEN];

    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int distance = levenshtein(word1, word2, len1, len2);

    printf("The Levenshtein distance between %s and %s is %d\n", word1, word2, distance);

    return 0;
}