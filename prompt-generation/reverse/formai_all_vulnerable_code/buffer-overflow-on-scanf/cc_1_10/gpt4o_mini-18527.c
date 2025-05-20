//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LEN 100
#define GENRE_LEN 50
#define REVIEW_LEN 200

typedef struct {
    char title[TITLE_LEN];
    char genre[GENRE_LEN];
    int year;
    int rating; // 1 to 5
    char review[REVIEW_LEN];
} Movie;

Movie movieDatabase[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }
    Movie newMovie;

    printf("Enter movie title: ");
    getchar(); // To consume newline character
    fgets(newMovie.title, TITLE_LEN, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Removing newline
    
    printf("Enter genre: ");
    fgets(newMovie.genre, GENRE_LEN, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0;
    
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    
    printf("Rate the movie (1-5): ");
    scanf("%d", &newMovie.rating);
    
    getchar(); // To consume newline character
    printf("Enter your review: ");
    fgets(newMovie.review, REVIEW_LEN, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0;

    movieDatabase[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies in the database.\n");
        return;
    }
    for (int i = 0; i < movieCount; i++) {
        Movie m = movieDatabase[i];
        printf("\nMovie %d:\n", i + 1);
        printf("Title: %s\n", m.title);
        printf("Genre: %s\n", m.genre);
        printf("Year: %d\n", m.year);
        printf("Rating: %d/5\n", m.rating);
        printf("Review: %s\n", m.review);
    }
}

void searchMovie() {
    char searchTitle[TITLE_LEN];
    printf("Enter movie title to search: ");
    getchar(); // To consume newline character
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDatabase[i].title, searchTitle) == 0) {
            found = 1;
            Movie m = movieDatabase[i];
            printf("\nMovie found:\n");
            printf("Title: %s\n", m.title);
            printf("Genre: %s\n", m.genre);
            printf("Year: %d\n", m.year);
            printf("Rating: %d/5\n", m.rating);
            printf("Review: %s\n", m.review);
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

void displayMenu() {
    printf("\nMovie Rating System Menu:\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Search for a movie\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}