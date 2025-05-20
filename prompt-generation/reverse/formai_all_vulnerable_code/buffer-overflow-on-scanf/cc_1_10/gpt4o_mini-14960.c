//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;  // a rating from 1 to 10
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear newline from buffer
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove trailing newline

    printf("Enter movie rating (1-10): ");
    scanf("%d", &newMovie.rating);

    if (newMovie.rating < 1 || newMovie.rating > 10) {
        printf("Invalid rating. Rating must be between 1 and 10.\n");
        return;
    }

    movieList[movieCount++] = newMovie;
    printf("Movie \"%s\" added successfully.\n", newMovie.title);
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies found in the list.\n");
        return;
    }
    
    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Genre: %s, Rating: %d\n",
                movieList[i].title,
                movieList[i].genre,
                movieList[i].rating);
    }
}

void deleteMovie() {
    if (movieCount == 0) {
        printf("No movies to delete.\n");
        return;
    }
    
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // Clear newline from buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline
    
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            printf("Movie \"%s\" deleted successfully.\n", title);
            return;
        }
    }
    printf("Movie \"%s\" not found in the list.\n", title);
}

void searchMovie() {
    if (movieCount == 0) {
        printf("No movies found in the list.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Clear newline from buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline
    
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            printf("Movie found: Title: %s, Genre: %s, Rating: %d\n",
                   movieList[i].title,
                   movieList[i].genre,
                   movieList[i].rating);
            return;
        }
    }
    printf("Movie \"%s\" not found in the list.\n", title);
}

void displayMenu() {
    printf("\n*** Movie Rating System Menu ***\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Delete Movie\n");
    printf("4. Search Movie\n");
    printf("5. Exit\n");
    printf("*********************************\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                deleteMovie();
                break;
            case 4:
                searchMovie();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}