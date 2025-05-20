//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10

typedef struct Movie {
    char title[50];
    int year;
    float rating;
    char genre[50];
} Movie;

Movie movies[MAX_MOVIES] = {
    {"The Matrix Reloaded", 2003, 8.3, "Sci-Fi"},
    {"The Lord of the Rings: The Two Towers", 2002, 8.2, "Fantasy"},
    {"Spider-Man", 2002, 8.0, "Action"},
    {"The Matrix", 1999, 8.5, "Sci-Fi"},
    {"The Terminator", 1984, 7.6, "Action"},
    {"Back to the Future", 1985, 7.8, "Sci-Fi"},
    {"The Shawshank Redemption", 1994, 8.2, "Drama"},
    {"Forrest Gump", 1994, 8.0, "Drama"},
    {"The Silence of Lambs", 1991, 8.0, "Horror"},
    {"Halloween", 1978, 7.8, "Horror"}
};

int main() {
    system("clear");
    printf("Welcome to the Electric Boogaloo Cinema!\n");
    printf("Here is a list of our current movies:\n");

    for (int i = 0; i < MAX_MOVIES; i++) {
        printf("%s (%d) - Rating: %.1f, Genre: %s\n", movies[i].title, movies[i].year, movies[i].rating, movies[i].genre);
    }

    printf("Please enter the title of the movie you want to rate:");
    char title[50];
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1;
            printf("Please enter your rating for the movie (1-10):");
            int rating = 0;
            scanf("%d", &rating);

            movies[i].rating = (float)rating;
            printf("Thank you for your rating!\n");
        }
    }

    if (!found) {
        printf("Sorry, that movie is not available.\n");
    }

    return 0;
}