//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define GENRE_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char genre[GENRE_LENGTH];
    float rating;
    int year;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar();  // To consume the newline left by the previous input
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0;  // Remove newline

    printf("Enter genre: ");
    fgets(newMovie.genre, GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0;  // Remove newline

    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);

    movieList[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    printf("\nMovies in the list:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d: %s (%d) - Genre: %s, Rating: %.1f\n", 
                i + 1, movieList[i].title, movieList[i].year,
                movieList[i].genre, movieList[i].rating);
    }
}

void calculateStatistics() {
    float totalRating = 0.0;
    float maxRating = 0.0;
    float minRating = 10.0;
    int genresCount[5] = {0}; // Action, Comedy, Drama, Horror, Sci-Fi
    const char* genres[] = {"Action", "Comedy", "Drama", "Horror", "Sci-Fi"};

    for (int i = 0; i < movieCount; i++) {
        totalRating += movieList[i].rating;
        if (movieList[i].rating > maxRating) {
            maxRating = movieList[i].rating;
        }
        if (movieList[i].rating < minRating) {
            minRating = movieList[i].rating;
        }

        for (int j = 0; j < 5; j++) {
            if (strcmp(movieList[i].genre, genres[j]) == 0) {
                genresCount[j]++;
                break;
            }
        }
    }

    printf("\nStatistics:\n");
    printf("Total movies: %d\n", movieCount);
    printf("Average rating: %.2f\n", totalRating / movieCount);
    printf("Max rating: %.1f\n", maxRating);
    printf("Min rating: %.1f\n", minRating);

    printf("Genre Distribution:\n");
    for (int k = 0; k < 5; k++) {
        printf("%s: %d\n", genres[k], genresCount[k]);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Calculate Statistics\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addMovie();
                break;
            case 2: 
                displayMovies();
                break;
            case 3: 
                calculateStatistics();
                break;
            case 4: 
                printf("Exiting the system. Goodbye!\n");
                break;
            default: 
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}