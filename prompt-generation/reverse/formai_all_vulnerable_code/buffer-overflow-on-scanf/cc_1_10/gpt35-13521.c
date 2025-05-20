//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>

/* User-defined movie rating system */
typedef enum {
    WORST = 1,
    BAD,
    OKAY,
    GOOD,
    BEST
} MovieRating;

/* Function declarations */
MovieRating getRating();
void displayRating(MovieRating);

int main() {
    printf("Welcome to the Unique C Movie Rating System!\n\n");

    MovieRating rating = getRating();
    printf("\nYou have rated the movie as:\n");
    displayRating(rating);

    return 0;
}

/**
 * Gets the user's movie rating input.
 */
MovieRating getRating() {
    int ratingInput;
    printf("Please rate the movie on a scale of 1 to 5: ");
    scanf("%d", &ratingInput);

    switch (ratingInput) {
        case 1: return WORST;
        case 2: return BAD;
        case 3: return OKAY;
        case 4: return GOOD;
        case 5: return BEST;
        default:
            printf("Invalid rating input. Please try again.\n");
            return getRating();
    }
}

/**
 * Displays the movie rating to the user.
 */
void displayRating(MovieRating rating) {
    switch (rating) {
        case WORST:
            printf("WORST\n");
            printf("Why did you even watch this movie?\n");
            break;
        case BAD:
            printf("BAD\n");
            printf("This movie was pretty terrible.\n");
            break;
        case OKAY:
            printf("OKAY\n");
            printf("It wasn't great, but not the worst.\n");
            break;
        case GOOD:
            printf("GOOD\n");
            printf("I enjoyed this movie!\n");
            break;
        case BEST:
            printf("BEST\n");
            printf("This movie was absolutely fantastic!\n");
            break;
        default:
            printf("Invalid rating input.\n");
            break;
    }
}