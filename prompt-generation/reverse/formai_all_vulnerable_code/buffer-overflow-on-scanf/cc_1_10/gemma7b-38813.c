//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a custom movie rating system
typedef enum MovieRating {
    Terrible,
    Meh,
    Acceptable,
    Good,
    Excellent
} MovieRating;

// Function to get the movie rating from the user
MovieRating getMovieRating() {
    int rating;

    printf("Enter your movie rating (1-5): ");
    scanf("%d", &rating);

    switch (rating) {
        case 1:
            return Terrible;
        case 2:
            return Meh;
        case 3:
            return Acceptable;
        case 4:
            return Good;
        case 5:
            return Excellent;
        default:
            return Terrible;
    }
}

// Function to display the movie rating
void displayMovieRating(MovieRating rating) {
    switch (rating) {
        case Terrible:
            printf("Your movie rating is: Terrible\n");
            break;
        case Meh:
            printf("Your movie rating is: Meh\n");
            break;
        case Acceptable:
            printf("Your movie rating is: Acceptable\n");
            break;
        case Good:
            printf("Your movie rating is: Good\n");
            break;
        case Excellent:
            printf("Your movie rating is: Excellent\n");
            break;
    }
}

int main() {
    MovieRating rating = getMovieRating();
    displayMovieRating(rating);

    return 0;
}