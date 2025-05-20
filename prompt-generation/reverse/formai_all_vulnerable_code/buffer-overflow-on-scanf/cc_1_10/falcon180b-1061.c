//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MOVIES 1000
#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_REVIEW_LEN 500

typedef struct movie {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

void add_movie(Movie* movies, int num_movies) {
    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);

    printf("Enter director: ");
    scanf("%s", movies[num_movies].director);

    printf("Enter actors: ");
    scanf("%s", movies[num_movies].actors);

    printf("Enter genre: ");
    scanf("%s", movies[num_movies].genre);

    printf("Enter rating (1-5): ");
    movies[num_movies].rating = scanf("%d", &movies[num_movies].rating);

    printf("Enter review: ");
    scanf("%s", movies[num_movies].review);

    printf("\n");
}

void display_movies(Movie* movies, int num_movies) {
    printf("Movie Title\tDirector\tActors\tGenre\tRating\tReview\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%s\t%s\t%d\t%s\n",
               movies[i].title,
               movies[i].director,
               movies[i].actors,
               movies[i].genre,
               movies[i].rating,
               movies[i].review);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    printf("Welcome to the Movie Rating System!\n");
    while (num_movies < MAX_MOVIES) {
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_movie(movies, num_movies);
                num_movies++;
                break;
            case '2':
                display_movies(movies, num_movies);
                break;
            case '3':
                printf("Thank you for using the Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}