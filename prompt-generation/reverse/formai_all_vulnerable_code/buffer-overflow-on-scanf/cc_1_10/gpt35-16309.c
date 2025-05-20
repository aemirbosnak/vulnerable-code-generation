//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 20

typedef struct movie {
    char title[50];
    char genre[20];
    int year;
    float rating;
} Movie;

void add_movie(Movie movies[], int *num_movies) {
    Movie new_movie;
    printf("Enter the title of the movie: ");
    scanf("%s", new_movie.title);
    printf("Enter the genre of the movie: ");
    scanf("%s", new_movie.genre);
    printf("Enter the year of the movie: ");
    scanf("%d", &new_movie.year);
    printf("Enter your rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    movies[*num_movies] = new_movie;
    (*num_movies)++;
}

void display_movies(Movie movies[], int num_movies) {
    printf("Title\tGenre\tYear\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%d\t%.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

void search_movie(Movie movies[], int num_movies) {
    char search_title[50];
    printf("Enter the title of the movie you want to search for: ");
    scanf("%s", search_title);
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, search_title) == 0) {
            printf("%s\t%s\t%d\t%.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

void sort_movies(Movie movies[], int num_movies) {
    Movie temp_movie;
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = i + 1; j < num_movies; j++) {
            if (movies[i].rating < movies[j].rating) {
                temp_movie = movies[i];
                movies[i] = movies[j];
                movies[j] = temp_movie;
            }
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice = 0;
    while (choice != 5) {
        printf("\n1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Sort movies by rating\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                display_movies(movies, num_movies);
                break;
            case 3:
                search_movie(movies, num_movies);
                break;
            case 4:
                sort_movies(movies, num_movies);
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}