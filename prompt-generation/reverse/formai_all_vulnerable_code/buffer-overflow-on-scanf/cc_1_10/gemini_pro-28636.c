//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

// Function to print the top half of the pattern
void printTopHalf(int n)
{
    int i, j, k;
    
    // Iterate over each row
    for (i = 1; i <= n; i++)
    {
        // Print spaces before the pattern
        for (j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        
        // Print numbers in increasing order
        for (k = 1; k <= i; k++)
        {
            printf("%d ", k);
        }
        
        // Print numbers in decreasing order
        for (k = i - 1; k >= 1; k--)
        {
            printf("%d ", k);
        }
        
        // Move to the next line
        printf("\n");
    }
}

// Function to print the bottom half of the pattern
void printBottomHalf(int n)
{
    int i, j, k;
    
    // Iterate over each row
    for (i = n - 1; i >= 1; i--)
    {
        // Print spaces before the pattern
        for (j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        
        // Print numbers in increasing order
        for (k = 1; k <= i; k++)
        {
            printf("%d ", k);
        }
        
        // Print numbers in decreasing order
        for (k = i - 1; k >= 1; k--)
        {
            printf("%d ", k);
        }
        
        // Move to the next line
        printf("\n");
    }
}

// Main function
int main()
{
    int n;
    
    // Get the size of the pattern from the user
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);
    
    // Print the top half of the pattern
    printTopHalf(n);
    
    // Print the bottom half of the pattern
    printBottomHalf(n);
    
    return 0;
}