//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main()
{
    int height, base, i, j, k;
    
    printf("Enter height of C: ");
    scanf("%d", &height);
    
    base = height / 4 + height / 10;

    printf("\n");

    // Printing top half of C
    for(i=0; i<height; i++)
    {
        for(j=0; j<base; j++)
        {
            if(i==0 || i==(height-1))
            {
                printf("*");
            }
            else if(j==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");

    // Printing bottom half of C
    for(i=0; i<height/2; i++)
    {
        for(j=0; j<base; j++)
        {
            if(j==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        
        for(k=0; k<height/2; k++)
        {
            if(i==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    return 0;
}