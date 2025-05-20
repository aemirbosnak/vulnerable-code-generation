//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct movie {
    char title[50];
    int year;
    float rating;
} Movie;

Movie* movies[10];
int num_movies = 0;

// Function to add a movie
void add_movie() {
    Movie* m = malloc(sizeof(Movie));
    printf("Enter the movie title: ");
    scanf("%s", m->title);
    printf("Enter the year of release: ");
    scanf("%d", &m->year);
    printf("Enter the rating (out of 10): ");
    scanf("%f", &m->rating);
    movies[num_movies++] = m;
}

// Function to print all movies
void list_movies() {
    printf("Title\t\tYear\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t\t%d\t%.1f\n", movies[i]->title, movies[i]->year, movies[i]->rating);
    }
}

// Function to find a movie by title
void find_movie() {
    char title[50];
    printf("Enter the movie title: ");
    scanf("%s", title);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(title, movies[i]->title) == 0) {
            printf("Title\t\tYear\tRating\n");
            printf("%s\t\t%d\t%.1f\n", movies[i]->title, movies[i]->year, movies[i]->rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

// Function to rate a movie
void rate_movie() {
    char title[50];
    float rating;
    printf("Enter the movie title: ");
    scanf("%s", title);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(title, movies[i]->title) == 0) {
            printf("Enter the rating (out of 10): ");
            scanf("%f", &rating);
            movies[i]->rating = rating;
            printf("Rating updated.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

// Function to delete a movie
void delete_movie() {
    char title[50];
    printf("Enter the movie title: ");
    scanf("%s", title);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(title, movies[i]->title) == 0) {
            free(movies[i]);
            for (int j = i; j < num_movies - 1; j++) {
                movies[j] = movies[j+1];
            }
            num_movies--;
            printf("Movie deleted.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

// Main function
int main() {
    int choice;
    while(true) {
        printf("\nWelcome to the movie rating system. Please choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. List all movies\n");
        printf("3. Find a movie by title\n");
        printf("4. Rate a movie\n");
        printf("5. Delete a movie\n");
        printf("6. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                list_movies();
                break;
            case 3:
                find_movie();
                break;
            case 4:
                rate_movie();
                break;
            case 5:
                delete_movie();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}