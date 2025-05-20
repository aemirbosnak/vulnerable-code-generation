//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>

// function to display the movie ratings along with helpful tips
void displayRatings(float rating) {
    printf("Movie Rating: %.2f\n", rating);
    if(rating >= 8.5) {
        printf("Wow! This movie is a must-watch!\n");
    } else if(rating >= 7) {
        printf("This movie is definitely worth your time!\n");
    } else if(rating >= 5) {
        printf("This movie is okay. It could have been better.\n");
    } else {
        printf("Sorry, this movie is not worth watching.\n");
    }
}

int main() {
    char movieName[50];
    int numReviews, i, rating;
    float avgRating;
    
    printf("Welcome to the Genius Movie Rating System\n\n");
    printf("Enter the movie name: ");
    scanf("%[^\n]", movieName);
    while(getchar() != '\n');
    
    printf("How many reviews have been submitted for %s? ", movieName);
    scanf("%d", &numReviews);
    while(getchar() != '\n');
    
    // get the average rating
    for(i=1; i<=numReviews; i++) {
        printf("Enter rating #%d (out of 10): ", i);
        scanf("%d", &rating);
        while(getchar() != '\n');
        if(rating >= 0 && rating <= 10) {
            avgRating += rating;
        } else {
            printf("Invalid rating. Please enter a rating between 0-10.\n");
            i--;
        }
    }
    avgRating /= numReviews;
    
    // display the movie ratings along with helpful tips
    printf("\n\n");
    printf("Movie: %s\n", movieName);
    printf("Number of Reviews: %d\n", numReviews);
    displayRatings(avgRating);
    
    return 0;
}