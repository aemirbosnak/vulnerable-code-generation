//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    char review[500];
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");
    scanf("%d", &rating);
    
    // Rating validation
    if (rating < 1 || rating > 10) {
        printf("Invalid rating. Please rate the movie on a scale of 1 to 10:\n");
        scanf("%d", &rating);
    }
    
    printf("Thanks for rating! Please provide a brief review of the movie:\n");
    scanf("\n");
    fgets(review, 500, stdin);
    
    printf("You have rated this movie %d out of 10.\n", rating);
    printf("Your review: %s\n", review);
    
    // Interpretation of the rating
    switch (rating) {
        case 1:
        case 2:
            printf("Sorry to hear you didn't enjoy the movie, we'll try to improve!\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("Thank you for watching, we hope you enjoyed it enough to recommend to others!\n");
            break;
        case 6:
        case 7:
            printf("Glad to hear you enjoyed the movie, we'll keep up the good work!\n");
            break;
        case 8:
        case 9:
            printf("Fantastic! We're so happy you loved the movie, thanks for watching!\n");
            break;
        case 10:
            printf("We're speechless! Thank you so much for giving us a perfect score!\n");
            break;
        default:
            printf("Oops, something went wrong. Please try rating and reviewing the movie again.\n");
            exit(1);
    }
    
    return 0;
}