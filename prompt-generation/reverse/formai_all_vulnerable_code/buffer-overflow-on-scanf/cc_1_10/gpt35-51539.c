//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    else if (y <= x && y <= z) {
        return y;
    }
    else {
        return z;
    }
}

int levenshtein(char* s1, char* s2, int len1, int len2) {
    int dist[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            }
            else if (j == 0) {
                dist[i][j] = i;
            }
            else if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
            }
        }
    }
    
    return dist[len1][len2];
}

int main() {
    char s1[100], s2[100];
    
    printf("Enter two strings to calculate the Levenshtein Distance (apocalypse edition):\n");
    scanf("%s %s", s1, s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int dist = levenshtein(s1, s2, len1, len2);
    
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d (and that's how the world ends)\n", s1, s2, dist);
    
    return 0;
}