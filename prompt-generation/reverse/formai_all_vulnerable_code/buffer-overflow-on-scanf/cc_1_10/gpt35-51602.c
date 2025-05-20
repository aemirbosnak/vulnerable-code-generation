//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of both strings
#define MAX_LENGTH 100

// Define the cost of different operations
#define INSERTION_COST 1
#define DELETION_COST 1
#define SUBSTITUTION_COST 2

// Function to calculate the minimum of three values
int min(int a, int b, int c)
{
    int lowest_value = a;
    if (b < lowest_value) {
        lowest_value = b;
    }
    if (c < lowest_value) {
        lowest_value = c;
    }
    return lowest_value;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *first_string, char *second_string)
{
    // Create a table to store the values of the operations
    int table[MAX_LENGTH + 1][MAX_LENGTH + 1];
    memset(table, 0, sizeof(table));

    // Initialize the first row and the first column
    for (int i = 1; i <= strlen(first_string); i++) {
        table[i][0] = i;
    }
    for (int j = 1; j <= strlen(second_string); j++) {
        table[0][j] = j;
    }

    // Fill in the rest of the table
    for (int i = 1; i <= strlen(first_string); i++) {
        for (int j = 1; j <= strlen(second_string); j++) {
            int substitution_cost = SUBSTITUTION_COST;
            if (first_string[i - 1] == second_string[j - 1]) {
                substitution_cost = 0;
            }
            table[i][j] = min(table[i - 1][j] + DELETION_COST, table[i][j - 1] + INSERTION_COST, table[i - 1][j - 1] + substitution_cost);
        }
    }

    // Return the value in the bottom right corner of the table
    return table[strlen(first_string)][strlen(second_string)];
}

int main()
{
    char first_string[MAX_LENGTH], second_string[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", first_string);
    printf("Enter the second string: ");
    scanf("%s", second_string);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", first_string, second_string, levenshtein_distance(first_string, second_string));

    return 0;
}