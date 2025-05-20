//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein_distance(char* str1, char* str2);

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("In the post-apocalyptic wasteland, communication is key.\n");
    printf("Enter two strings to calculate their Levenshtein distance:\n");
    scanf("%s", str1);
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    if (distance == 0)
        printf("The strings are identical.\n");
    else
        printf("The Levenshtein distance between the strings is %d.\n", distance);

    return 0;
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0)
        return len2;
    else if (len2 == 0)
        return len1;

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = matrix[i - 1][j] + 1;
        }
    }

    return matrix[len1][len2];
}