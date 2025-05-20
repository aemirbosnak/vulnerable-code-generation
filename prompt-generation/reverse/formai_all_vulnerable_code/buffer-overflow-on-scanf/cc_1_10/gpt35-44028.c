//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_TITLE 50

// struct to represent a movie
typedef struct {
    char title[MAX_TITLE];
    int rating;
} movie_t;

// function prototypes
void display_menu();
int add_movie(movie_t *movies, int *num_movies);
void display_movies(movie_t *movies, int num_movies);
void rate_movie(movie_t *movies, int num_movies);

int main() {
    movie_t movies[MAX_MOVIES]; // array to store movies
    int num_movies = 0; // number of movies in the array
    int choice; // user's menu choice

    do {
        display_menu(); // display menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(add_movie(movies, &num_movies)) {
                    printf("Movie added successfully!\n");
                } else {
                    printf("Sorry, you cannot add any more movies.\n");
                }
                break;
            case 2:
                display_movies(movies, num_movies);
                break;
            case 3:
                rate_movie(movies, num_movies);
                break;
            case 4:
                printf("Thank you for using the movie rating system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// function to display menu options
void display_menu() {
    printf("\nMovie Rating System Menu\n");
    printf("-------------------------\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Rate a movie\n");
    printf("4. Quit\n");
}

// function to add a movie to the array
int add_movie(movie_t *movies, int *num_movies) {
    if(*num_movies < MAX_MOVIES) {
        printf("Enter the movie title: ");
        scanf(" %[^\n]s", movies[*num_movies].title);
        movies[*num_movies].rating = 0;
        (*num_movies)++;
        return 1;
    } else {
        return 0;
    }
}

// function to display all movies in the array
void display_movies(movie_t *movies, int num_movies) {
    printf("\nAll Movies:\n");
    printf("-----------\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%s (rating: %d)\n", movies[i].title, movies[i].rating);
    }
}

// function to rate a movie
void rate_movie(movie_t *movies, int num_movies) {
    char title[MAX_TITLE];
    int rating;

    printf("Enter the title of the movie you want to rate: ");
    scanf(" %[^\n]s", title);

    int movie_index = -1;
    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            movie_index = i;
            break;
        }
    }

    if(movie_index == -1) {
        printf("Movie not found.\n");
    } else {
        printf("Enter your rating (1-10) for \"%s\": ", title);
        scanf("%d", &rating);
        if(rating < 1 || rating > 10) {
            printf("Invalid rating. Please enter a number between 1 and 10.\n");
        } else {
            movies[movie_index].rating = rating;
            printf("Rating of %d has been recorded for \"%s\".\n", rating, title);
        }
    }
}