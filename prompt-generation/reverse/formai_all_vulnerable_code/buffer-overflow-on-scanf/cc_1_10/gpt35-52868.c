//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

int levenshtein(char *string1, char *string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int distance[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
    int i, j, cost;

    for(i = 0; i <= length1; i++) {
        for(j = 0; j <= length2; j++) {
            distance[i][j] = 0;
        }
    }

    for(i = 1; i <= length1; i++) {
        distance[i][0] = i;
    }

    for(j = 1; j <= length2; j++) {
        distance[0][j] = j;
    }

    for(i = 1; i <= length1; i++) {
        for(j = 1; j <= length2; j++) {
            if(string1[i-1] == string2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            distance[i][j] = minimum(distance[i-1][j]+1, distance[i][j-1]+1, distance[i-1][j-1]+cost);
        }
    }

    return distance[length1][length2];
}

int minimum(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);
    int distance = levenshtein(string1, string2);
    printf("The Levenshtein distance between %s and %s is %d.", string1, string2, distance);
    return 0;
}