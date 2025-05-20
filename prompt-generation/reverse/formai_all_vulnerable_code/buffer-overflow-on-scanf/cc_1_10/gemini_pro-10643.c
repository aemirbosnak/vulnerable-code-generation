//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
typedef enum {
    G,      // General audiences
    PG,     // Parental guidance suggested
    PG13,   // Parents strongly cautioned
    R,      // Restricted
    NC17    // No one 17 and under admitted
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int year;
} Movie;

// Define the array of movies
Movie movies[] = {
    {"The Shawshank Redemption", R, 1994},
    {"The Godfather", R, 1972},
    {"The Dark Knight", PG13, 2008},
    {"12 Angry Men", PG, 1957},
    {"Schindler's List", R, 1993},
    {"Pulp Fiction", R, 1994},
    {"Forrest Gump", PG13, 1994},
    {"The Matrix", R, 1999},
    {"Good Will Hunting", R, 1997},
    {"Fight Club", R, 1999},
    {"The Lord of the Rings: The Fellowship of the Ring", PG13, 2001},
    {"The Lion King", G, 1994},
    {"The Silence of the Lambs", R, 1991},
    {"Se7en", R, 1995},
    {"The Green Mile", R, 1999},
    {"Saving Private Ryan", R, 1998},
    {"The Usual Suspects", R, 1995},
    {"The Departed", R, 2006},
    {"No Country for Old Men", R, 2007},
    {"There Will Be Blood", R, 2007},
};

// Define the number of movies
#define NUM_MOVIES (sizeof(movies) / sizeof(Movie))

// Get the rating of a movie
Rating get_rating(char *title) {
    for (int i = 0; i < NUM_MOVIES; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return movies[i].rating;
        }
    }

    return -1;
}

// Print the rating of a movie
void print_rating(char *title) {
    Rating rating = get_rating(title);

    switch (rating) {
        case G:
            printf("G - General audiences\n");
            break;
        case PG:
            printf("PG - Parental guidance suggested\n");
            break;
        case PG13:
            printf("PG-13 - Parents strongly cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC17:
            printf("NC-17 - No one 17 and under admitted\n");
            break;
        default:
            printf("Invalid rating\n");
            break;
    }
}

// Main function
int main() {
    // Get the movie title from the user
    char title[256];
    printf("Enter the movie title: ");
    scanf("%s", title);

    // Print the rating of the movie
    print_rating(title);

    return 0;
}