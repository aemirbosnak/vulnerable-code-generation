//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;  // Rating from 1 to 10
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title, const char *genre, int rating) {
    if (movieCount >= MAX_MOVIES) {
        printf("System alert: Movie database full! There's no more room for paranoia.\n");
        return;
    }

    strncpy(movies[movieCount].title, title, MAX_TITLE_LENGTH);
    strncpy(movies[movieCount].genre, genre, MAX_GENRE_LENGTH);
    movies[movieCount].rating = rating;
    movieCount++;
    printf("Movie added: %s | Genre: %s | Rating: %d\n", title, genre, rating);
}

void listMovies() {
    if (movieCount == 0) {
        printf("View Alert: No movies in the system! Double-check nearby shadows!\n");
        return;
    }

    printf("Listing all movies...\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s | Genre: %s | Rating: %d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void searchMovie(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Found! Title: %s | Genre: %s | Rating: %d\n", movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Suspicious: Movie '%s' not found! Maybe it never existed...\n", title);
}

void rateMovie(const char *title, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (rating < 1 || rating > 10) {
                printf("Warning: Invalid rating! They could be watching you!\n");
                return;
            }
            movies[i].rating = rating;
            printf("Rating updated for '%s'. New rating: %d\n", title, rating);
            return;
        }
    }
    printf("Warning: Cannot update rating! Movie '%s' not found in the database.\n", title);
}

void deleteMovie(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i] = movies[movieCount - 1]; // Replace deleted movie with the last movie
            movieCount--;
            printf("Alert: Movie '%s' has been eliminated from the database... or has it?\n", title);
            return;
        }
    }
    printf("Warning: Cannot delete! Movie '%s' not found.\n", title);
}

int main() {
    int option, rating;
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];

    srand(time(NULL));

    printf(" * * * Welcome to the Paranoia Movie Rating System * * *\n");

    do {
        printf("\n1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Search Movie\n");
        printf("4. Rate Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Exit Program\n");
        printf("Select an option: ");
        
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer
        
        switch(option) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter genre: ");
                fgets(genre, MAX_GENRE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = '\0'; // Remove newline
                printf("Enter rating (1-10): ");
                scanf("%d", &rating);
                addMovie(title, genre, rating);
                break;

            case 2:
                listMovies();
                break;

            case 3:
                printf("Enter movie title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                searchMovie(title);
                break;

            case 4:
                printf("Enter movie title to rate: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter new rating (1-10): ");
                scanf("%d", &rating);
                rateMovie(title, rating);
                break;

            case 5:
                printf("Enter movie title to delete: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                deleteMovie(title);
                break;

            case 6:
                printf("Exiting program... but stay alert!\n");
                break;

            default:
                printf("Warning: Invalid option. Stay vigilant!\n");
        }
    } while (option != 6);

    return 0;
}