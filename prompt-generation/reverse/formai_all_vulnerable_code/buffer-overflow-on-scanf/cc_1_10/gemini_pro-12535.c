//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Romeo and Juliet rating system
enum rjrating {
    TRAGIC,
    ROMANTIC,
    COMEDIC,
    UNKNOWN
};

// Get the rating from the user
enum rjrating get_rating(void) {
    int rating;

    printf("Enter the rating (1-4): ");
    scanf("%d", &rating);

    switch (rating) {
        case 1:
            return TRAGIC;
        case 2:
            return ROMANTIC;
        case 3:
            return COMEDIC;
        case 4:
            return UNKNOWN;
        default:
            printf("Invalid rating\n");
            return UNKNOWN;
    }
}

// Print the rating
void print_rating(enum rjrating rating) {
    switch (rating) {
        case TRAGIC:
            printf("Tragic\n");
            break;
        case ROMANTIC:
            printf("Romantic\n");
            break;
        case COMEDIC:
            printf("Comedic\n");
            break;
        case UNKNOWN:
            printf("Unknown\n");
            break;
    }
}

int main(void) {
    enum rjrating rating;

    // Get the rating from the user
    rating = get_rating();

    // Print the rating
    print_rating(rating);

    return 0;
}