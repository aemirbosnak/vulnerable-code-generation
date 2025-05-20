//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

int main()
{
    // initialize variables
    int height, width, spaces, stars;
    
    // get input from user
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);
    
    // calculate width
    width = 2 * height - 1;
    
    // loop through rows
    for(int i=1; i<=height; i++)
    {
        spaces = height - i;
        stars = 2 * i - 1;
        
        // loop through spaces
        for(int j=1; j<=spaces; j++)
        {
            printf(" ");
        }
        
        // loop through stars
        for(int k=1; k<=stars; k++)
        {
            printf("*");
        }
        
        // move to next line
        printf("\n");
    }
    
    // loop through rows
    for(int i=height-1; i>=1; i--)
    {
        spaces = height - i;
        stars = 2 * i - 1;
        
        // loop through spaces
        for(int j=1; j<=spaces; j++)
        {
            printf(" ");
        }
        
        // loop through stars
        for(int k=1; k<=stars; k++)
        {
            printf("*");
        }
        
        // move to next line
        printf("\n");
    }
    
    return 0;
}