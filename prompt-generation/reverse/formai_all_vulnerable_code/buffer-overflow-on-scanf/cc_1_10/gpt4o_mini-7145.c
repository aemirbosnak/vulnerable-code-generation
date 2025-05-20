//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50
#define GENRE_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char genre[GENRE_LENGTH];
    float rating;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count < MAX_MOVIES) {
        printf("Enter movie title: ");
        scanf(" %[^\n]s", movies[*count].title);
        printf("Enter movie genre: ");
        scanf(" %[^\n]s", movies[*count].genre);
        printf("Enter movie rating (0.0 to 10.0): ");
        scanf("%f", &movies[*count].rating);
        (*count)++;
        printf("Movie added successfully!\n\n");
    } else {
        printf("Movie list is full! Cannot add more movies.\n\n");
    }
}

void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n\n");
        return;
    }
    
    printf("List of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("--------------------------\n");
    }
    printf("\n");
}

void searchMovie(const Movie movies[], int count) {
    char title[TITLE_LENGTH];
    printf("Enter the movie title to search: ");
    scanf(" %[^\n]s", title);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Found Movie:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %.1f\n\n", movies[i].rating);
            return;
        }
    }
    printf("Movie not found!\n\n");
}

void editMovie(Movie movies[], int count) {
    char title[TITLE_LENGTH];
    printf("Enter the movie title to edit: ");
    scanf(" %[^\n]s", title);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Editing Movie: %s\n", movies[i].title);
            printf("Enter new genre: ");
            scanf(" %[^\n]s", movies[i].genre);
            printf("Enter new rating (0.0 to 10.0): ");
            scanf("%f", &movies[i].rating);
            printf("Movie updated successfully!\n\n");
            return;
        }
    }
    printf("Movie not found!\n\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("Welcome to the Movie Rating System!\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Edit Movie\n");
        printf("5. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                editMovie(movies, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    return 0;
}