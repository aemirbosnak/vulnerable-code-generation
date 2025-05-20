//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
} Movie;

void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.1f\n", movie.rating);
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Error: Maximum movie limit reached!\n");
        return;
    }
    
    Movie newMovie;
    printf("\nEnter movie title: ");
    getchar(); // to consume the leftover newline
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // remove newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // remove newline

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    
    // Validate rating
    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating. Must be between 0.0 and 10.0.\n");
        return;
    }

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully, Neon Dreamer!\n");
}

void listMovies(Movie *movies, int count) {
    printf("\n--- Current Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nMovie #%d:\n", i + 1);
        printMovie(movies[i]);
    }
    printf("\n--- End of list ---\n");
}

void searchMovie(Movie *movies, int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // to consume the leftover newline
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline
    
    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].title, searchTitle) != NULL) {
            printMovie(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found with the title \"%s\".\n", searchTitle);
    }
}

void cyberPunkEffects() {
    printf("\n--- Cyberpunk Movie Ratings System ---\n");
    printf("... Loading holographic interface ...\n");
    printf("... Integrating data streams ...\n");
    printf("... Accessing movie archives ...\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    cyberPunkEffects();

    while (1) {
        printf("\n[1] Add Movie\n");
        printf("[2] List Movies\n");
        printf("[3] Search Movie\n");
        printf("[0] Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                listMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 0:
                printf("Exiting the Neon Abyss... Stay safe out there!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again, Cyber Warrior.\n");
        }
    }

    return 0;
}