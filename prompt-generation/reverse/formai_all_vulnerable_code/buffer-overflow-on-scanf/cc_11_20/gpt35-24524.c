//FormAI DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>

int main() {
    int rating;
    char movieTitle[100];
    
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the name of the movie: ");
    scanf("%[^\n]s", movieTitle);
    
    printf("\nPlease rate the movie out of 10: ");
    scanf("%d", &rating);
    
    if (rating >=0 && rating <=10) {
        printf("Thank you for submitting your rating for %s!\n", movieTitle);
        printf("Your rating for %s is: %d\n", movieTitle, rating);
    }
    else {
        printf("Invalid rating! Please enter a rating between 0 and 10.\n");
    }
    
    printf("\nWould you like to leave a review of %s? (Y/N)\n", movieTitle);
    char reviewResponse;
    scanf(" %c", &reviewResponse);
    
    if (reviewResponse == 'Y' || reviewResponse == 'y') {
        printf("Great! Please enter your review for %s:\n", movieTitle);
        char review[200];
        scanf(" %[^\n]s", review);
        printf("\nThank you for your review of %s!\n", movieTitle);
        printf("Your review for %s is: \"%s\"\n", movieTitle, review);
    }
    else if (reviewResponse == 'N' || reviewResponse == 'n') {
        printf("That's okay, thank you for rating %s!\n", movieTitle);
    }
    else {
        printf("Invalid response. Please enter either Y or N.\n");
    }
    
    printf("\nWould you like to see more movie ratings? (Y/N)\n");
    char moreMoviesResponse;
    scanf(" %c", &moreMoviesResponse);
    
    if (moreMoviesResponse == 'Y' || moreMoviesResponse == 'y') {
        printf("Sorry, this feature is not yet available. Please try again later!\n");
    }
    else if (moreMoviesResponse == 'N' || moreMoviesResponse == 'n') {
        printf("Thank you for using the C Movie Rating System. Goodbye!\n");
    }
    else {
        printf("Invalid response. Please enter either Y or N.\n");
    }
    
    return 0;
}