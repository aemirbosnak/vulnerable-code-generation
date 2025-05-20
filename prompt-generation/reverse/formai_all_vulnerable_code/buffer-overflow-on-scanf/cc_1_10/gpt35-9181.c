//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold movie information
struct movie {
    char title[100];
    char director[50];
    int year;
    char rating[5];
};

// Function to add a new movie to the database
void add_movie(struct movie *database, int *num_movies) {
    printf("\nEnter the title of the movie: ");
    scanf("%s", database[*num_movies].title);

    printf("Enter the name of the director: ");
    scanf("%s", database[*num_movies].director);

    printf("Enter the year the movie was released: ");
    scanf("%d", &database[*num_movies].year);

    printf("Enter the rating of the movie: ");
    scanf("%s", database[*num_movies].rating);

    printf("Movie added to database.\n");

    (*num_movies)++;
}

// Function to update the rating of a movie
void update_rating(struct movie *database, int num_movies) {
    char title[100], rating[5];
    printf("\nEnter the title of the movie you want to update: ");
    scanf("%s", title);

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(database[i].title, title) == 0) {
            printf("Enter the new rating for %s: ", title);
            scanf("%s", rating);
            strcpy(database[i].rating, rating);
            printf("Rating updated for %s.\n", title);
            return;
        }
    }

    printf("Movie not found in database.\n");
}

// Function to display all movies in the database
void display_movies(struct movie *database, int num_movies) {
    printf("\n%-30s %-20s %-10s %s\n", "Title", "Director", "Year", "Rating");
    for (int i = 0; i < num_movies; i++) {
        printf("%-30s %-20s %-10d %s\n", database[i].title, database[i].director, database[i].year, database[i].rating);
    }
}

int main() {
    struct movie movie_database[100];
    int num_movies = 0;
    int choice;

    printf("Welcome to the Grateful Movie Rating System!\n\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new movie to the database\n");
        printf("2. Update the rating of a movie\n");
        printf("3. Display all movies in the database\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movie_database, &num_movies);
                break;
            case 2:
                update_rating(movie_database, num_movies);
                break;
            case 3:
                display_movies(movie_database, num_movies);
                break;
            case 4:
                printf("\nThanks for using the Grateful Movie Rating System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 4.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}