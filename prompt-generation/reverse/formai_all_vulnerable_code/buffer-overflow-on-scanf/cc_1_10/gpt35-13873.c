//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Unique C Movie Rating System\n\n");
    
    int totalMovies = 0;
    float totalRating = 0.0;
    float currentRating;
    int userResponse = 1;
    
    while (userResponse == 1) {
        printf("Enter the rating for the current movie (0-10): ");
        scanf("%f", &currentRating);
        
        if (currentRating < 0 || currentRating > 10) {
            printf("\nInvalid rating! Please enter a rating between 0 and 10.\n\n");
            continue;
        }
        
        totalMovies++;
        totalRating += currentRating;
        
        printf("Thank you for submitting your rating! Would you like to rate another movie? (0 for No, 1 for Yes): ");
        scanf("%d", &userResponse);
        
        if (userResponse != 0 && userResponse != 1) {
            printf("\nInvalid response! Please enter 0 for No or 1 for Yes.\n\n");
            continue;
        }
    }
    
    if (totalMovies == 0) {
        printf("\nNo movies were rated!\n\n");
        return 0;
    }
    
    float averageRating = totalRating / totalMovies;
    
    printf("\nThe average rating of the movies is %.2f\n\n", averageRating);
    
    if (averageRating >= 8.0) {
        printf("Excellent! This movie is a must-watch.\n");
    } else if (averageRating >= 6.0) {
        printf("Good! This movie is definitely worth watching.\n");
    } else {
        printf("Not so good... This movie is not recommended.\n");
    }
    
    return 0;
}