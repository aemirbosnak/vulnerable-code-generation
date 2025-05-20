//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Movie rating system
typedef enum {
    G,
    PG,
    PG_13,
    R,
    NC_17
} Rating;

// Function to get the rating of a movie
Rating get_rating(char *title) {
    // Get the user's input
    printf("Enter the rating of the movie '%s': ", title);
    char rating[4];
    scanf("%s", rating);

    // Convert the user's input to a rating
    Rating rating_enum;
    if (strcmp(rating, "G") == 0) {
        rating_enum = G;
    } else if (strcmp(rating, "PG") == 0) {
        rating_enum = PG;
    } else if (strcmp(rating, "PG-13") == 0) {
        rating_enum = PG_13;
    } else if (strcmp(rating, "R") == 0) {
        rating_enum = R;
    } else if (strcmp(rating, "NC-17") == 0) {
        rating_enum = NC_17;
    } else {
        printf("Invalid rating '%s'\n", rating);
        exit(1);
    }

    // Return the rating
    return rating_enum;
}

// Function to print the rating of a movie
void print_rating(char *title, Rating rating) {
    // Print the rating
    printf("The rating of the movie '%s' is: ", title);
    switch (rating) {
    case G:
        printf("G\n");
        break;
    case PG:
        printf("PG\n");
        break;
    case PG_13:
        printf("PG-13\n");
        break;
    case R:
        printf("R\n");
        break;
    case NC_17:
        printf("NC-17\n");
        break;
    }
}

// Main function
int main() {
    // Get the title of the movie
    char title[100];
    printf("Enter the title of the movie: ");
    scanf("%s", title);

    // Get the rating of the movie
    Rating rating = get_rating(title);

    // Print the rating of the movie
    print_rating(title, rating);

    return 0;
}