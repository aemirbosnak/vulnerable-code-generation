//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Declare the movie rating system
enum MovieRating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Declare a function to print the movie rating
void printMovieRating(enum MovieRating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested");
            break;
        case PG13:
            printf("PG-13 - Parents Strongly Cautioned");
            break;
        case R:
            printf("R - Restricted");
            break;
        case NC17:
            printf("NC-17 - No One 17 and Under Admitted");
            break;
        default:
            printf("Invalid rating");
            break;
    }
}

// Get the age of the user
int getAge() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Get the movie rating
enum MovieRating getMovieRating() {
    char rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf(" %c", &rating);
    switch (rating) {
        case 'G':
            return G;
        case 'P':
            return PG;
        case 'g':
            return PG13;
        case 'R':
            return R;
        case 'N':
            return NC17;
        default:
            return -1;
    }
}

// Check if the user is old enough to see the movie
int isOldEnough(int age, enum MovieRating rating) {
    switch (rating) {
        case G:
            return 1;
        case PG:
            return age >= 8;
        case PG13:
            return age >= 13;
        case R:
            return age >= 17;
        case NC17:
            return 0;
        default:
            return 0;
    }
}

// Main function
int main() {
    // Get the age of the user
    int age = getAge();

    // Get the movie rating
    enum MovieRating rating = getMovieRating();

    // Check if the user is old enough to see the movie
    int isOldEnoughToSeeMovie = isOldEnough(age, rating);

    // Print the result
    if (isOldEnoughToSeeMovie) {
        printf("You are old enough to see the movie.\n");
    } else {
        printf("You are not old enough to see the movie.\n");
    }

    return 0;
}