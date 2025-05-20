//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rating;
    char name[50];
} Movie;

void print_menu() {
    printf("1. Add a new movie\n");
    printf("2. Display all movies\n");
    printf("3. Update a movie's rating\n");
    printf("4. Delete a movie\n");
    printf("5. Exit\n");
}

void add_movie() {
    Movie new_movie;
    printf("Enter the name of the movie: ");
    scanf("%s", new_movie.name);
    printf("Enter the movie's rating: ");
    scanf("%d", &new_movie.rating);
    printf("Movie added successfully!\n");
}

void display_movies() {
    Movie movies[100];
    int num_movies = 0;
    int i;
    printf("Movie Name\t\tRating\n");
    for (i = 0; i < 100; i++) {
        printf("%s\t\t%d\n", movies[i].name, movies[i].rating);
    }
}

void update_movie() {
    Movie new_movie;
    printf("Enter the name of the movie to update: ");
    scanf("%s", new_movie.name);
    printf("Enter the movie's new rating: ");
    scanf("%d", &new_movie.rating);
    printf("Movie updated successfully!\n");
}

void delete_movie() {
    Movie movie_to_delete;
    printf("Enter the name of the movie to delete: ");
    scanf("%s", movie_to_delete.name);
    printf("Movie deleted successfully!\n");
}

int main() {
    Movie movies[100];
    int num_movies = 0;
    int choice;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_movie(); break;
            case 2: display_movies(); break;
            case 3: update_movie(); break;
            case 4: delete_movie(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    }
    return 0;
}