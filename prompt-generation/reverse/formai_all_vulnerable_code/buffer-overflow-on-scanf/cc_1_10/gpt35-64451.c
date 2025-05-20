//FormAI DATASET v1.0 Category: Movie Rating System ; Style: detailed
/* C Movie Rating System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50

/* Structure to hold details of a movie */
typedef struct movie {
    char name[MAX_NAME_LENGTH];
    int rating;
} Movie;

/* Function prototypes */
void print_menu();
int add_movie(Movie movies[], int *num_movies);
void list_movies(Movie movies[], int num_movies);
void rate_movie(Movie movies[], int num_movies);
void display_statistics(Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES];   /* Array to hold all the movies */
    int num_movies = 0;         /* Number of movies added to the array */
    int choice;                 /* User choice from the menu */

    /*Continuously print the menu and execute user choice until they choose to exit*/
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (add_movie(movies, &num_movies)) {
                    printf("Movie added successfully!\n");
                } else {
                    printf("Error adding movie!\n");
                }
                break;
            case 2:
                list_movies(movies, num_movies);
                break;
            case 3:
                rate_movie(movies, num_movies);
                break;
            case 4:
                display_statistics(movies, num_movies);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/* Print the menu options */
void print_menu() {
    printf("\n*** C Movie Rating System ***\n");
    printf("1. Add movie\n");
    printf("2. List movies\n");
    printf("3. Rate movie\n");
    printf("4. Display statistics\n");
    printf("5. Exit\n");
}

/* Add a new movie to the array of movies */
int add_movie(Movie movies[], int *num_movies) {
    if (*num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return 0;
    }

    Movie new_movie;
    printf("\nEnter details of the movie:\n");
    printf("Name: ");
    getchar();  /* Clear the input buffer */
    fgets(new_movie.name, MAX_NAME_LENGTH, stdin);
    new_movie.name[strlen(new_movie.name) - 1] = '\0';  /* Remove newline character from name */
    printf("Rating (1-10): ");
    scanf("%d", &new_movie.rating);

    movies[*num_movies] = new_movie;
    (*num_movies)++;
    return 1;
}

/* List all movies in the array */
void list_movies(Movie movies[], int num_movies) {
    if (num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    printf("\nList of movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (Rating: %d)\n", i+1, movies[i].name, movies[i].rating);
    }
}

/* Rate a movie */
void rate_movie(Movie movies[], int num_movies) {
    if (num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    int choice;
    list_movies(movies, num_movies);
    printf("Enter the number of the movie you want to rate: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= num_movies) {
        printf("Enter the rating (1-10): ");
        scanf("%d", &movies[choice-1].rating);
        printf("Rating for %s updated successfully.\n", movies[choice-1].name);
    } else {
        printf("Invalid choice.\n");
    }
}

/* Display statistics */
void display_statistics(Movie movies[], int num_movies) {
    if (num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    int num_high_rating = 0;
    int num_low_rating = 0;
    int total_rating = 0;

    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating >= 8) {
            num_high_rating++;
        } else if (movies[i].rating <= 3) {
            num_low_rating++;
        }
        total_rating += movies[i].rating;
    }

    float avg_rating = (float) total_rating / num_movies;

    printf("\nMovie statistics:\n");
    printf("Total number of movies: %d\n", num_movies);
    printf("Number of movies with rating 8 and above: %d\n", num_high_rating);
    printf("Number of movies with rating 3 and below: %d\n", num_low_rating);
    printf("Average rating: %.2f\n", avg_rating);
}