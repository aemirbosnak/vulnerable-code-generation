//FormAI DATASET v1.0 Category: Pattern printing ; Style: immersive
#include <stdio.h>

int main()
{
    printf("Welcome to the world of C pattern printing!\n");
    printf("Today, we are going to create a unique pattern that will leave you amazed.\n");
    
    int n;
    printf("Enter the number of rows you want in the pattern: ");
    scanf("%d", &n);
    
    printf("Here's your pattern:\n");
    
    int i, j, k;
    
    // Upper half of the pattern
    for(i=1; i<=n; i++)
    {
        // First half of the row
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        
        // Middle part of the row
        for(k=1; k<=2*i-1; k++)
        {
            if(k%2 == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        
        // Second half of the row
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        
        printf("\n");
    }
    
    // Lower half of the pattern
    for(i=n-1; i>=1; i--)
    {
        // First half of the row
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        
        // Middle part of the row
        for(k=1; k<=2*i-1; k++)
        {
            if(k%2 == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        
        // Second half of the row
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        
        printf("\n");
    }
    
    printf("Wow, look at that pattern! Thank you for using this program. Goodbye!\n");
    return 0;
}