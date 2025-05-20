//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATING 5
#define MAX_NAME_LEN 50
#define MAX_GENRE_LEN 20

struct movie {
    char name[MAX_NAME_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
};

int main() {
    int num_movies;
    char input[100];
    struct movie movies[MAX_MOVIES];
    int i, j;

    printf("Welcome to the C Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    printf("Enter the name of the first movie: ");
    scanf(" %[^\n]", movies[0].name);
    getchar();

    printf("Enter the genre of the first movie: ");
    scanf(" %[^\n]", movies[0].genre);
    getchar();

    printf("Enter the rating for the first movie (1-5): ");
    scanf("%d", &movies[0].rating);

    for (i = 1; i < num_movies; i++) {
        printf("Enter the name of the next movie: ");
        scanf(" %[^\n]", movies[i].name);
        getchar();

        printf("Enter the genre of the next movie: ");
        scanf(" %[^\n]", movies[i].genre);
        getchar();

        printf("Enter the rating for the next movie (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nThank you for entering the movie ratings!\n");

    printf("\nHere are the ratings:\n");

    for (i = 0; i < num_movies; i++) {
        printf("Name: %s\nGenre: %s\nRating: ", movies[i].name, movies[i].genre);

        for (j = 0; j < movies[i].rating; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}