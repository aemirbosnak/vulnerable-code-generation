//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

// Function Prototypes
void get_movie_info(char *title, char *director, char *actors, char *genre, int *rating);
void display_movie_info(char *title, char *director, char *actors, char *genre, int rating);
int get_rating();

int main() {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;

    get_movie_info(title, director, actors, genre, &rating);
    display_movie_info(title, director, actors, genre, rating);

    return 0;
}

void get_movie_info(char *title, char *director, char *actors, char *genre, int *rating) {
    printf("Enter the movie title: ");
    scanf("%s", title);
    printf("Enter the movie director: ");
    scanf("%s", director);
    printf("Enter the movie actors: ");
    scanf("%s", actors);
    printf("Enter the movie genre: ");
    scanf("%s", genre);
    *rating = get_rating();
}

void display_movie_info(char *title, char *director, char *actors, char *genre, int rating) {
    printf("Movie Title: %s\n", title);
    printf("Movie Director: %s\n", director);
    printf("Movie Actors: %s\n", actors);
    printf("Movie Genre: %s\n", genre);
    printf("Movie Rating: %d\n", rating);
}

int get_rating() {
    int rating;
    char input[10];

    printf("Enter the movie rating (1-5): ");
    scanf("%s", input);

    if (isdigit(input[0])) {
        rating = input[0] - '0';
        if (rating >= 1 && rating <= 5) {
            return rating;
        } else {
            printf("Invalid rating, please enter a number between 1 and 5.\n");
            return get_rating();
        }
    } else {
        printf("Invalid input, please enter a number between 1 and 5.\n");
        return get_rating();
    }
}