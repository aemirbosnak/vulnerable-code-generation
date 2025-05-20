//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100 // Maximum number of movies in the system

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    int choice = 0;
    while (choice != 5) {
        printf("1. Add movie\n");
        printf("2. Edit movie rating\n");
        printf("3. List movies\n");
        printf("4. Find movie by director\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_movies >= MAX_MOVIES) {
                    printf("Error: Maximum number of movies reached.\n");
                } else {
                    Movie new_movie;
                    printf("Enter title: ");
                    scanf("%s", new_movie.title);
                    printf("Enter director: ");
                    scanf("%s", new_movie.director);
                    printf("Enter year: ");
                    scanf("%d", &new_movie.year);
                    printf("Enter rating (out of 10): ");
                    scanf("%f", &new_movie.rating);
                    if (new_movie.rating > 10) {
                        printf("Error: Rating cannot be greater than 10.\n");
                        break;
                    }
                    movies[num_movies++] = new_movie;
                }
                break;
            case 2:
                if (num_movies == 0) {
                    printf("Error: No movies in system.\n");
                } else {
                    char title_to_find[50];
                    printf("Enter title of movie to edit rating: ");
                    scanf("%s", title_to_find);
                    int movie_index = -1;
                    for (int i = 0; i < num_movies; i++) {
                        if (strcmp(movies[i].title, title_to_find) == 0) {
                            movie_index = i;
                            break;
                        }
                    }
                    if (movie_index == -1) {
                        printf("Error: Movie not found.\n");
                        break;
                    }
                    float new_rating;
                    printf("Enter new rating (out of 10): ");
                    scanf("%f", &new_rating);
                    if (new_rating > 10) {
                        printf("Error: Rating cannot be greater than 10.\n");
                        break;
                    }
                    movies[movie_index].rating = new_rating;
                    printf("Rating updated successfully.\n");
                }
                break;
            case 3:
                if (num_movies == 0) {
                    printf("Error: No movies in system.\n");
                } else {
                    printf("Movies:\n");
                    printf("%-30s %-20s %-10s %-10s\n", "Title", "Director", "Year", "Rating");
                    for (int i = 0; i < num_movies; i++) {
                        printf("%-30s %-20s %-10d %-10.1f\n",
                                movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
                    }
                }
                break;
            case 4:
                if (num_movies == 0) {
                    printf("Error: No movies in system.\n");
                } else {
                    char director_to_find[50];
                    printf("Enter director of movie to find: ");
                    scanf("%s", director_to_find);
                    printf("Movies by %s:\n", director_to_find);
                    printf("%-30s %-20s %-10s %-10s\n", "Title", "Director", "Year", "Rating");
                    for (int i = 0; i < num_movies; i++) {
                        if (strcmp(movies[i].director, director_to_find) == 0) {
                            printf("%-30s %-20s %-10d %-10.1f\n",
                                    movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
                        }
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}