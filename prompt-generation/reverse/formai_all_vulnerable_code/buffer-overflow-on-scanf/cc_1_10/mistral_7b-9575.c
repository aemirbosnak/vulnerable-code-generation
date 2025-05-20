//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_NAME_LEN 50
#define MAX_RATING_LEN 4
#define MAX_GENRE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Movie;

void encryptName(char *name, int key) {
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = (char)((int)name[i] + key);
    }
}

void decryptName(char *name, int key) {
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = (char)((int)name[i] - key);
    }
}

void printMovie(Movie movie) {
    printf("%-30s %-20s %3d\n", movie.name, movie.genre, movie.rating);
}

int main() {
    int numMovies, key = 7;
    Movie movies[MAX_MOVIES];
    char searchName[MAX_NAME_LEN];

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    for (int i = 0; i < numMovies; i++) {
        printf("\nEnter movie %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", movies[i].name);
        encryptName(movies[i].name, key);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating: ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie List:\n");

    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }

    printf("\nSearch a movie by name: ");
    scanf("%s", searchName);
    encryptName(searchName, key);

    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, searchName) == 0) {
            printf("\nMovie Found:\nName: %s\nGenre: %s\nRating: %d", movies[i].name, movies[i].genre, movies[i].rating);
            break;
        }
    }

    printf("\nDecrypted Movie List:\n");

    for (int i = 0; i < numMovies; i++) {
        decryptName(movies[i].name, key);
    }

    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }

    return 0;
}