//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10
#define ADMIN_PASS "admin123"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_TITLE_LENGTH];
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieList;

void initializeMovieList(MovieList *list) {
    list->count = 0;
}

void addMovie(MovieList *list) {
    if (list->count >= MAX_MOVIES) {
        printf("No more space for new movies.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    scanf(" %[^\n]", newMovie.title);
    printf("Enter movie genre: ");
    scanf(" %[^\n]", newMovie.genre);
    printf("Enter movie rating (0-10): ");
    scanf("%f", &newMovie.rating);

    // Check for valid rating
    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Invalid rating! Rating must be between 0 and 10.\n");
        return;
    }

    list->movies[list->count] = newMovie;
    list->count++;
    printf("Movie added successfully: %s\n", newMovie.title);
}

void viewMovies(const MovieList *list) {
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("Title: %s | Genre: %s | Rating: %.1f\n", 
               list->movies[i].title, 
               list->movies[i].genre, 
               list->movies[i].rating);
    }
    printf("------------------\n");
}

void deleteMovie(MovieList *list) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->movies[i].title, title) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->movies[j] = list->movies[j + 1];
            }
            list->count--;
            printf("Movie deleted successfully: %s\n", title);
            return;
        }
    }
    printf("Movie not found: %s\n", title);
}

void updateRating(MovieList *list) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to update rating: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->movies[i].title, title) == 0) {
            float newRating;
            printf("Enter new rating for %s (0-10): ", title);
            scanf("%f", &newRating);

            if (newRating < 0 || newRating > 10) {
                printf("Invalid rating! Rating must be between 0 and 10.\n");
                return;
            }

            list->movies[i].rating = newRating;
            printf("Rating updated successfully for %s.\n", title);
            return;
        }
    }
    printf("Movie not found: %s\n", title);
}

int main() {
    MovieList movieList;
    initializeMovieList(&movieList);
    char adminInput[MAX_RATING_LENGTH];

    while (1) {
        printf("\n--- Post-Apocalyptic Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. Delete Movie\n");
        printf("4. Update Movie Rating\n");
        printf("5. Admin Panel\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie(&movieList);
                break;
            case 2:
                viewMovies(&movieList);
                break;
            case 3:
                deleteMovie(&movieList);
                break;
            case 4:
                updateRating(&movieList);
                break;
            case 5:
                printf("Enter admin password: ");
                scanf("%s", adminInput);
                if (strcmp(adminInput, ADMIN_PASS) == 0) {
                    printf("Welcome to Admin Panel.\n");
                    // Additional admin operations can be added here.
                } else {
                    printf("Invalid password!\n");
                }
                break;
            case 0:
                printf("Shutting down Movie Rating System. The apocalypse awaits...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}