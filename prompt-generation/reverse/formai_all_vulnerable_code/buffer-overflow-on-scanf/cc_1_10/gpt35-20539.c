//FormAI DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>

// Display the ratings for a movie
void display_ratings(int ratings[], int num_ratings) {
    printf("Ratings: ");
    for(int i = 0; i < num_ratings; i++) {
        printf("%d ", ratings[i]);
    }
    printf("\n");
}

// Get the average rating for a movie
double get_average_rating(int ratings[], int num_ratings) {
    int sum = 0;
    for(int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }
    return (double)sum / num_ratings;
}

int main() {
    int ratings[10];
    int num_ratings = 0;
    char continue_input = 'y';
    
    // Prompt user to enter ratings
    printf("Welcome to the C Movie Rating System!\n");
    while(continue_input == 'y') {
        printf("Enter a rating (1-10): ");
        int rating;
        scanf("%d", &rating);
        if(rating > 0 && rating <= 10) {
            ratings[num_ratings] = rating;
            num_ratings++;
        }
        else {
            printf("Invalid rating range!\n");
        }
        printf("Do you want to enter another rating? (y/n): ");
        scanf(" %c", &continue_input);
    }
    
    // Display ratings and average rating
    display_ratings(ratings, num_ratings);
    printf("Average Rating: %.1f\n", get_average_rating(ratings, num_ratings));
    
    // Assign a recommendation based on average rating
    double avg_rating = get_average_rating(ratings, num_ratings);
    if(avg_rating >= 9.0) {
        printf("***** Highly Recommended! *****");
    }
    else if(avg_rating >= 8.0 && avg_rating < 9.0) {
        printf("**** Recommended! ****");
    }
    else if(avg_rating >= 6.0 && avg_rating < 8.0) {
        printf("*** Average. Nothing special. ***");
    }
    else {
        printf("** Not Recommended! **");
    }
    
    return 0;
}