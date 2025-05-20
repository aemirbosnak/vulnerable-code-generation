//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 30
#define MAX_MOVIES 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
    int year;
} Movie;

void printMovie(Movie m) {
    printf("Title: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Rating: %.2f\n", m.rating);
    printf("Year: %d\n\n", m.year);
}

void printAllMovies(Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        printMovie(movies[i]);
    }
}

void addMovie(Movie movies[], int *count) {
    if (*count < MAX_MOVIES) {
        printf("Enter movie title: ");
        scanf(" %[^\n]", movies[*count].title);
        
        printf("Enter movie genre: ");
        scanf(" %[^\n]", movies[*count].genre);
        
        printf("Enter movie rating (0.0 - 10.0): ");
        scanf("%f", &movies[*count].rating);
        
        printf("Enter movie release year: ");
        scanf("%d", &movies[*count].year);
        
        (*count)++;
        printf("Movie added successfully!\n\n");
    } else {
        printf("Movie list is full!\n\n");
    }
}

void searchMovieByTitle(Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title to search: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printMovie(movies[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n\n");
    }
}

void sortMoviesByRating(Movie movies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating!\n\n");
}

void displayMenu() {
    printf("===================================\n");
    printf("         Movie Rating System       \n");
    printf("===================================\n");
    printf("1. Add a movie\n");
    printf("2. Search a movie by title\n");
    printf("3. Display all movies\n");
    printf("4. Sort movies by rating (highest to lowest)\n");
    printf("5. Exit\n");
    printf("===================================\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                searchMovieByTitle(movies, count);
                break;
            case 3:
                printAllMovies(movies, count);
                break;
            case 4:
                sortMoviesByRating(movies, count);
                break;
            case 5:
                printf("Exiting the system! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n\n");
        }
    }

    return 0;
}