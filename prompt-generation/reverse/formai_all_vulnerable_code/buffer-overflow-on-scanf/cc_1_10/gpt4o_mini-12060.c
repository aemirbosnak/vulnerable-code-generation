//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_MAX_LENGTH 100
#define MOVIE_LIST_MAX 100

typedef struct {
    char title[TITLE_MAX_LENGTH];
    float totalRating;
    int ratingCount;
} Movie;

typedef struct {
    Movie *movies[MOVIE_LIST_MAX];
    int movieCount;
} MovieList;

void addMovie(MovieList *list);
void rateMovie(MovieList *list);
void viewMovies(MovieList *list);
void freeMemory(MovieList *list);

int main() {
    MovieList movieList;
    movieList.movieCount = 0;

    int choice;
    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. View Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(&movieList);
                break;
            case 2:
                rateMovie(&movieList);
                break;
            case 3:
                viewMovies(&movieList);
                break;
            case 4:
                freeMemory(&movieList);
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addMovie(MovieList *list) {
    if (list->movieCount >= MOVIE_LIST_MAX) {
        printf("Movie list is full! Unable to add more movies.\n");
        return;
    }
    
    Movie *newMovie = (Movie *)malloc(sizeof(Movie));
    if (newMovie == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // Clear newline character from the buffer
    fgets(newMovie->title, TITLE_MAX_LENGTH, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = 0; // Remove newline character
    newMovie->totalRating = 0.0;
    newMovie->ratingCount = 0;
    
    list->movies[list->movieCount] = newMovie;
    list->movieCount++;
    
    printf("Movie '%s' added successfully!\n", newMovie->title);
}

void rateMovie(MovieList *list) {
    if (list->movieCount == 0) {
        printf("No movies available to rate.\n");
        return;
    }
    
    char title[TITLE_MAX_LENGTH];
    float rating;

    printf("Enter movie title to rate: ");
    getchar(); // Clear newline character from the buffer
    fgets(title, TITLE_MAX_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    for (int i = 0; i < list->movieCount; i++) {
        if (strcmp(list->movies[i]->title, title) == 0) {
            printf("Enter rating (0.0 to 10.0): ");
            scanf("%f", &rating);
            if (rating < 0.0 || rating > 10.0) {
                printf("Invalid rating! It must be between 0.0 and 10.0.\n");
                return;
            }
            list->movies[i]->totalRating += rating;
            list->movies[i]->ratingCount++;
            printf("Rated '%s' with %.2f. Total ratings: %d\n", list->movies[i]->title, rating, list->movies[i]->ratingCount);
            return;
        }
    }

    printf("Movie '%s' not found!\n", title);
}

void viewMovies(MovieList *list) {
    if (list->movieCount == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < list->movieCount; i++) {
        Movie *movie = list->movies[i];
        float averageRating = (movie->ratingCount == 0) ? 0.0 : movie->totalRating / movie->ratingCount;
        printf("Title: %s, Average Rating: %.2f (from %d ratings)\n", movie->title, averageRating, movie->ratingCount);
    }
}

void freeMemory(MovieList *list) {
    for (int i = 0; i < list->movieCount; i++) {
        free(list->movies[i]);
    }
}