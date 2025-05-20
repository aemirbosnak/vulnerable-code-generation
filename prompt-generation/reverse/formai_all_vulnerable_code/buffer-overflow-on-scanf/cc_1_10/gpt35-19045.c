//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int calculate_levenshtein_distance(char *string1, char *string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    int levenshtein_matrix[length1 + 1][length2 + 1];

    for(int i = 0; i <= length1; i++) {
        for(int j = 0; j <= length2; j++) {
            if(i == 0) {
                levenshtein_matrix[i][j] = j;
            }
            else if(j == 0) {
                levenshtein_matrix[i][j] = i;
            }
            else {
                if(string1[i-1] == string2[j-1]) {
                    levenshtein_matrix[i][j] = levenshtein_matrix[i-1][j-1];
                }
                else {
                    int minimum = levenshtein_matrix[i-1][j-1];
                    if(levenshtein_matrix[i][j-1] < minimum) {
                        minimum = levenshtein_matrix[i][j-1];
                    }
                    if(levenshtein_matrix[i-1][j] < minimum) {
                        minimum = levenshtein_matrix[i-1][j];
                    }

                    levenshtein_matrix[i][j] = minimum + 1;
                }
            }
        }
    }

    return levenshtein_matrix[length1][length2];
}

int main() {
    char string1[100];
    char string2[100];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int distance = calculate_levenshtein_distance(string1, string2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d", string1, string2, distance);

    return 0;
}