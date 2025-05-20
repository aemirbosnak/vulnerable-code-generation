//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>

// Define the movie rating system
enum movie_rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Get the movie rating from the user
enum movie_rating get_movie_rating() {
    char rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf(" %c", &rating);

    // Convert the user input to the corresponding movie rating
    enum movie_rating rating_enum;
    switch (rating) {
        case 'G':
            rating_enum = G;
            break;
        case 'P':
            rating_enum = PG;
            break;
        case 'p':
            rating_enum = PG;
            break;
        case 'g':
            rating_enum = G;
            break;
        case 'R':
            rating_enum = R;
            break;
        case 'r':
            rating_enum = R;
            break;
        case 'N':
            rating_enum = NC17;
            break;
        case 'n':
            rating_enum = NC17;
            break;
        case 'C':
            rating_enum = NC17;
            break;
        case 'c':
            rating_enum = NC17;
            break;
        case '1':
            rating_enum = PG13;
            break;
        case '3':
            rating_enum = PG13;
            break;
        default:
            printf("Invalid rating entered. Please enter a valid rating (G, PG, PG13, R, NC17).\n");
            rating_enum = get_movie_rating();
    }

    return rating_enum;
}

// Print the movie rating
void print_movie_rating(enum movie_rating rating) {
    switch (rating) {
        case G:
            printf("The movie is rated G.\n");
            break;
        case PG:
            printf("The movie is rated PG.\n");
            break;
        case PG13:
            printf("The movie is rated PG13.\n");
            break;
        case R:
            printf("The movie is rated R.\n");
            break;
        case NC17:
            printf("The movie is rated NC17.\n");
            break;
    }
}

int main() {
    // Get the movie rating from the user
    enum movie_rating rating = get_movie_rating();

    // Print the movie rating
    print_movie_rating(rating);

    return 0;
}