//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold the movie details */
struct Movie {
    char title[100];
    char genre[50];
    int rating;
};

/* Function to get the user input for movie details */
void get_movie_details(struct Movie *movie) {
    printf("Enter the title of the movie: ");
    scanf("%[^\n]%*c", movie->title);

    printf("Enter the genre of the movie: ");
    scanf("%[^\n]%*c", movie->genre);

    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &movie->rating);
}

/* Function to print the movie details */
void print_movie_details(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %d\n", movie.rating);
}

/* Main function */
int main() {
    int choice, num_movies = 0;
    struct Movie movies[10];

    while (1) {
        printf("\n-------------------\n");
        printf("C Movie Rating System\n");
        printf("-------------------\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Exit\n");
        printf("-------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_movies < 10) {
                struct Movie new_movie;
                get_movie_details(&new_movie);
                movies[num_movies] = new_movie;
                num_movies++;

                printf("Movie added successfully!\n");
            }
            else {
                printf("Cannot add more movies, maximum limit reached.\n");
            }
        }
        else if (choice == 2) {
            if (num_movies == 0) {
                printf("No movies found.\n");
            }
            else {
                printf("\n-------------------\n");
                printf("All Movies\n");
                printf("-------------------\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("#%d\n", i+1);
                    print_movie_details(movies[i]);
                    printf("\n");
                }
                printf("-------------------\n");
            }
        }
        else if (choice == 3) {
            printf("Exiting C Movie Rating System...\n");
            exit(0);
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}