//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct paranoid_string {
    char str[MAX_LENGTH];
    int len;
} paranoid_string;

int min(int a, int b, int c) {
    int min = a;
    
    if (b < min) {
        min = b;
    }
    
    if (c < min) {
        min = c;
    }
    
    return min;
}

int levenshtein_distance(paranoid_string str1, paranoid_string str2) {
    int dist[str1.len + 1][str2.len + 1];
    
    for (int i = 0; i <= str1.len; i++) {
        for (int j = 0; j <= str2.len; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (str1.str[i - 1] == str2.str[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + min(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
            }
        }
    }
    
    return dist[str1.len][str2.len];
}

paranoid_string generate_random_string() {
    paranoid_string str;
    int length = rand() % MAX_LENGTH;
    
    for (int i = 0; i < length; i++) {
        str.str[i] = (char) (rand() % 95 + 32);
    }
    
    str.len = length;
    return str;
}

int main() {
    paranoid_string s1, s2;
    int num_tests, dist;
    
    printf("Enter the number of tests to run: ");
    scanf("%d", &num_tests);
    
    for (int i = 0; i < num_tests; i++) {
        s1 = generate_random_string();
        s2 = generate_random_string();
        printf("\nTest %d:\n", i + 1);
        printf("String 1: %s\n", s1.str);
        printf("String 2: %s\n", s2.str);
        dist = levenshtein_distance(s1, s2);
        if (dist == 0) {
            printf("The two strings are identical.\n");
        } else if (dist == 1) {
            printf("The two strings are similar.\n");
        } else {
            printf("The two strings are different.\n");
        }
    }
    
    return 0;
}