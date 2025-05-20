//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance[len1+1][len2+1];

    // Initialize the first row and column of the matrix
    for(int i = 0; i <= len1; i++)
        distance[i][0] = i;
    for(int j = 0; j <= len2; j++)
        distance[0][j] = j;

    // Fill in the rest of the matrix
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int substitution_cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            int insertion_cost = distance[i][j-1] + 1;
            int deletion_cost = distance[i-1][j] + 1;
            int substitution = distance[i-1][j-1] + substitution_cost;
            distance[i][j] = (insertion_cost < deletion_cost) ? insertion_cost : deletion_cost;
            distance[i][j] = (substitution < distance[i][j]) ? substitution : distance[i][j];
        }
    }

    return distance[len1][len2];
}

int main()
{
    char input_str1[MAX_LEN], input_str2[MAX_LEN];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(input_str1, MAX_LEN, stdin);
    printf("Please enter the second string: ");
    fgets(input_str2, MAX_LEN, stdin);

    // Remove the newline character from user input
    int len1 = strlen(input_str1);
    int len2 = strlen(input_str2);
    input_str1[len1-1] = '\0';
    input_str2[len2-1] = '\0';

    int distance = levenshtein_distance(input_str1, input_str2);
    printf("The Levenshtein distance between %s and %s is %d.\n", input_str1, input_str2, distance);

    return 0;
}