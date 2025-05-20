//FormAI DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000
#define MAX_STR_LEN 100

struct movie {
    char title[MAX_STR_LEN];
    char director[MAX_STR_LEN];
    char genre[MAX_STR_LEN];
    int runtime;
    float rating;
};

void print_menu();
void add_movie(struct movie movies[], int *num_movies);
void view_movie(struct movie movies[], int num_movies);
void update_movie(struct movie movies[], int num_movies);
void delete_movie(struct movie movies[], int *num_movies);

int main(void) {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    int quit = 0;
    int choice;

    while (!quit) {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                view_movie(movies, num_movies);
                break;
            case 3:
                update_movie(movies, num_movies);
                break;
            case 4:
                delete_movie(movies, &num_movies);
                break;
            case 5:
                quit = 1;
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    }

    printf("Thank you for using the movie rating system!");

    return 0;
}

void print_menu() {
    printf("\n");
    printf("1. Add a movie\n");
    printf("2. View movies\n");
    printf("3. Update a movie\n");
    printf("4. Delete a movie\n");
    printf("5. Quit\n");
}

void add_movie(struct movie movies[], int *num_movies) {
    if (*num_movies == MAX_MOVIES) {
        printf("\nMaximum number of movies reached. Cannot add more movies.");
        return;
    }

    struct movie new_movie;
    printf("\nEnter the movie title: ");
    scanf("%s", new_movie.title);
    printf("Enter the movie director: ");
    scanf("%s", new_movie.director);
    printf("Enter the movie genre: ");
    scanf("%s", new_movie.genre);
    printf("Enter the movie runtime in minutes: ");
    scanf("%d", &new_movie.runtime);
    printf("Enter the movie rating out of 10: ");
    scanf("%f", &new_movie.rating);

    movies[*num_movies] = new_movie;
    *num_movies += 1;

    printf("\nMovie added successfully.");
}

void view_movie(struct movie movies[], int num_movies) {
    if (num_movies == 0) {
        printf("\nNo movies to view.");
        return;
    }

    printf("\n%-30s %-30s %-15s %-10s %-10s", "Title", "Director", "Genre", "Runtime", "Rating");

    for (int i = 0; i < num_movies; i++) {
        struct movie current_movie = movies[i];
        printf("\n%-30s %-30s %-15s %-10d %-10.1f", current_movie.title, current_movie.director, current_movie.genre, current_movie.runtime, current_movie.rating);
    }
}

void update_movie(struct movie movies[], int num_movies) {
    if (num_movies == 0) {
        printf("\nNo movies to update.");
        return;
    }

    char title[MAX_STR_LEN];
    int found_movie = 0;

    printf("\nEnter the title of the movie to update: ");
    scanf("%s", title);

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("\nEnter the updated movie director: ");
            scanf("%s", movies[i].director);
            printf("Enter the updated movie genre: ");
            scanf("%s", movies[i].genre);
            printf("Enter the updated movie runtime in minutes: ");
            scanf("%d", &movies[i].runtime);
            printf("Enter the updated movie rating out of 10: ");
            scanf("%f", &movies[i].rating);

            printf("\nMovie updated successfully.");
            found_movie = 1;
            break;
        }
    }

    if (!found_movie) {
        printf("\nMovie not found.");
    }
}

void delete_movie(struct movie movies[], int *num_movies) {
    if (*num_movies == 0) {
        printf("\nNo movies to delete.");
        return;
    }

    char title[MAX_STR_LEN];
    int found_movie = 0;

    printf("\nEnter the title of the movie to delete: ");
    scanf("%s", title);

    for (int i = 0; i < *num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *num_movies - 1; j++) {
                movies[j] = movies[j+1];
            }

            printf("\nMovie deleted successfully.");
            found_movie = 1;
            *num_movies -= 1;
            break;
        }
    }

    if (!found_movie) {
        printf("\nMovie not found.");
    }
}