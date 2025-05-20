//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include<stdio.h>
#include<string.h>

// Function to calculate Levenshtein Distance between two strings
int levenshtein_distance(char *s1, char *s2)
{
    // Length of strings s1 and s2
    int len1 = strlen(s1), len2 = strlen(s2);
    
    // Creating a 2D matrix
    int matrix[len1+1][len2+1];
    
    // Initializing the first row
    for(int i = 0; i <= len1; i++)
    {
        matrix[i][0] = i;
    }
    
    // Initializing the first column
    for(int j = 0; j <= len2; j++)
    {
        matrix[0][j] = j;
    }
    
    // Filling up the remaining matrix
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            // Cost of substitution
            int cost = (s1[i-1] != s2[j-1]);
            
            // Finding the minimum cost of operations
            int min_cost = matrix[i-1][j] + 1;             // Deletion
            if(matrix[i][j-1] + 1 < min_cost)              
                min_cost = matrix[i][j-1] + 1;             // Insertion
            if(matrix[i-1][j-1] + cost < min_cost)         
                min_cost = matrix[i-1][j-1] + cost;        // Substitution
            
            matrix[i][j] = min_cost;                       // Updating the matrix
        }
    }
    
    return matrix[len1][len2];                            //Returning the final value of matrix
}

// Main function
int main()
{
    char str1[100], str2[100];
    
    printf("\n\t\t***SURPRISE!***\n");
    printf("\nThis program is a Levenshtein Distance Calculator.");
    printf("\nIt calculates the number of operations required to convert one string into another.");
    
    printf("\n\nEnter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    int dist = levenshtein_distance(str1, str2);          // Calling the Levenshtein Distance function
    
    printf("\nThe Levenshtein Distance between \"%s\" and \"%s\" is: %d", str1, str2, dist);  // Displaying the results
    
    return 0;  // Exiting the program
}