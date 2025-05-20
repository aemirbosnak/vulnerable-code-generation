//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include<stdio.h>
#include<string.h>

// Function to calculate minimum of three integers
int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein_distance(char* str1, char* str2, int len1, int len2)
{
    // Creating a multi-player game interface
    printf("\n**************************************************\n");
    printf("                 Multiplayer Levenshtein Distance Game             ");
    printf("\n**************************************************\n\n");

    printf("Game Rules: \n");
    printf("- Two players will enter two different strings.\n");
    printf("- The game will calculate Levenshtein Distance between the two strings.\n");
    printf("- The player whose string has smaller Levenshtein Distance from the specified string, wins.\n\n");

    // Printing the two strings entered by the players
    printf("Player 1 entered string: %s\n", str1);
    printf("Player 2 entered string: %s\n", str2);

    // Creating a 2D array to store the Levenshtein distance for each pair of suffixes
    int lDistArr[len1+1][len2+1];

    // Initializing the first row and column with the respective index values
    for (int i=0; i<=len1; i++)
        lDistArr[i][0] = i;
    for (int j=0; j<=len2; j++)
        lDistArr[0][j] = j;

    // Filling the array using Dynamic Programming approach to calculate Levenshtein Distance
    for (int i=1; i<=len1; i++)
    {
        for (int j=1; j<=len2; j++)
        {
            if (str1[i-1] == str2[j-1])
                lDistArr[i][j] = lDistArr[i-1][j-1];
            else
                lDistArr[i][j] = 1 + min(lDistArr[i-1][j], lDistArr[i][j-1], lDistArr[i-1][j-1]);
        }
    }

    // Printing the Levenshtein Distance between the two strings
    int lDist = lDistArr[len1][len2];
    printf("\nLevenshtein Distance between the strings is: %d\n\n", lDist);

    // Determining the winner based on Levenshtein Distance between the two strings
    if (lDist == 0)
        printf("Its a tie!\n");
    else if (lDist % 2 == 0)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");

    return lDist;
}

int main()
{
    char str1[50], str2[50];

    printf("Enter a string for Player 1: ");
    scanf("%s", str1);

    printf("Enter a string for Player 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Calling the function to calculate Levenshtein Distance and determine the winner
    levenshtein_distance(str1, str2, len1, len2);

    return 0;
}