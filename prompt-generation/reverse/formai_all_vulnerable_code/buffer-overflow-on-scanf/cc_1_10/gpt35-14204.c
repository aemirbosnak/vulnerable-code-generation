//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateLevenshteinDistance(char *word1, char *word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    int distance[word1_len+1][word2_len+1];
    for(int i = 0; i <= word1_len; i++) {
        for(int j = 0; j <= word2_len; j++) {
            if(i == 0) {
                distance[i][j] = j;
            }
            else if(j == 0) {
                distance[i][j] = i;
            }
            else {
                distance[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= word1_len; i++) {
        for(int j = 1; j <= word2_len; j++) {
            if(word1[i-1] == word2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            }
            else {
                distance[i][j] = 1 + min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]);
            }
        }
    }
    return distance[word1_len][word2_len];
}

int min(int a, int b, int c) {
    int m = a;
    if(b < m) {
        m = b;
    }
    if(c < m) {
        m = c;
    }
    return m;
}

int main() {
    char word1[100];
    char word2[100];
    printf("Enter word 1: ");
    scanf("%s", word1);
    printf("Enter word 2: ");
    scanf("%s", word2);
    int levenshtein_distance = calculateLevenshteinDistance(word1, word2);
    printf("The Levenshtein Distance between %s and %s is %d\n", word1, word2, levenshtein_distance);
    return 0;
}