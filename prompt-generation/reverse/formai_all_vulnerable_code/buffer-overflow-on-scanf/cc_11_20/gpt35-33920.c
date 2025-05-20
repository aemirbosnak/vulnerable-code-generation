//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include<stdio.h> 
  
int main() 
{ 
    int rating;
    
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating (1-10) for the movie: ");
    scanf("%d", &rating);
    
    if(rating >= 1 && rating <= 10)
    {
        printf("Thank you for rating the movie!\n");
        
        // Display rating in stars
        printf("Your rating in stars is: ");
        for(int i=1; i<=rating; i++)
        {
            printf("*");
        }
        printf("\n");
        
        // Display rating description
        printf("Your rating description: ");
        switch(rating)
        {
            case 1:
                printf("Terrible");
                break;
            case 2:
                printf("Poor");
                break;
            case 3:
                printf("Average");
                break;
            case 4:
                printf("Fair");
                break;
            case 5:
                printf("Good");
                break;
            case 6:
                printf("Very Good");
                break;
            case 7:
                printf("Excellent");
                break;
            case 8:
                printf("Outstanding");
                break;
            case 9:
                printf("Exceptional");
                break;
            case 10:
                printf("Masterpiece");
                break;
        }
        printf("\n");
        
        // Display recommended age group
        printf("Recommended age group: ");
        if(rating >= 7 && rating <= 10)
        {
            printf("13+");
        }
        else if(rating >= 4 && rating <= 6)
        {
            printf("PG");
        }
        else if(rating >= 1 && rating <= 3)
        {
            printf("G");
        }
        printf("\n");
    }
    else
    {
        printf("Invalid rating! Please enter a rating between 1-10.\n");
    }
    
    return 0;
}