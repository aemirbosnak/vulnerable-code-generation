//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50

typedef struct {
    char title[50];
    char director[30];
    int rating;
} Movie;

void add_movie(Movie movies[], int *num_movies, char title[], char director[]);
void print_movies(Movie movies[], int num_movies);
void get_rating(Movie *movie);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (1) {
        printf("\n1. Add Movie\n2. Print Movies\n3. Quit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[50], director[30];
                printf("Enter Movie Title: ");
                scanf("%s", title);
                printf("Enter Movie Director: ");
                scanf("%s", director);
                add_movie(movies, &num_movies, title, director);
                break;
            }
            case 2: {
                print_movies(movies, num_movies);
                break;
            }
            case 3: {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid Choice! Try Again.\n");
                break;
            }
        }
    }

    return 0;
}

void add_movie(Movie movies[], int *num_movies, char title[], char director[]) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Maximum Movies Reached!\n");
        return;
    }

    strcpy(movies[*num_movies].title, title);
    strcpy(movies[*num_movies].director, director);

    printf("Enter Movie Rating (1-10): ");
    scanf("%d", &movies[*num_movies].rating);

    (*num_movies)++;
}

void print_movies(Movie movies[], int num_movies) {
    printf("\n%-30s %-20s %-5s\n", "Title", "Director", "Rating");

    for (int i = 0; i < num_movies; i++) {
        printf("%-30s %-20s %-5d\n", movies[i].title, movies[i].director, movies[i].rating);
    }
}

void get_rating(Movie *movie) {
    int rating;
    printf("Enter Movie Rating (1-10): ");
    scanf("%d", &rating);
    movie->rating = rating;
}