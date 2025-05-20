//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int totalRatings;
    int numberOfRatings;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *name) {
    if (movieCount < MAX_MOVIES) {
        strncpy(movies[movieCount].name, name, NAME_LENGTH);
        movies[movieCount].totalRatings = 0;
        movies[movieCount].numberOfRatings = 0;
        movieCount++;
        printf("Movie '%s' added successfully!\n", name);
    } else {
        printf("Cannot add movie: Movie limit reached.\n");
    }
}

void rateMovie(const char *name, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            if (rating >= 1 && rating <= 5) {
                movies[i].totalRatings += rating;
                movies[i].numberOfRatings++;
                printf("Rated '%s' with a score of %d.\n", name, rating);
            } else {
                printf("Invalid rating! Please provide a rating between 1 and 5.\n");
            }
            return;
        }
    }
    printf("Movie '%s' not found!\n", name);
}

void displayMovies() {
    printf("\nMovies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movies[i].name);
        if (movies[i].numberOfRatings > 0) {
            float avgRating = (float) movies[i].totalRatings / movies[i].numberOfRatings;
            printf("Average Rating: %.2f\n", avgRating);
        } else {
            printf("Average Rating: No Ratings Yet\n");
        }
        printf("\n");
    }
}

void saveMoviesToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(movies, sizeof(Movie), movieCount, file);
        fclose(file);
        printf("Movies saved to '%s' successfully!\n", filename);
    } else {
        printf("Could not open file '%s' for writing!\n", filename);
    }
}

void loadMoviesFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        movieCount = fread(movies, sizeof(Movie), MAX_MOVIES, file);
        fclose(file);
        printf("Movies loaded from '%s' successfully!\n", filename);
    } else {
        printf("Could not open file '%s' for reading! Starting fresh.\n", filename);
    }
}

int main() {
    char movieName[NAME_LENGTH];
    char command[10];
    int rating;

    loadMoviesFromFile("movies.dat");

    while (1) {
        printf("\nCommands:\n");
        printf("1. Add Movie\n2. Rate Movie\n3. Display Movies\n4. Save & Exit\n5. Exit Without Saving\n");
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "1") == 0) {
            printf("Enter movie name: ");
            fgets(movieName, sizeof(movieName), stdin);
            movieName[strcspn(movieName, "\n")] = 0; // Remove newline
            addMovie(movieName);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter movie name to rate: ");
            fgets(movieName, sizeof(movieName), stdin);
            movieName[strcspn(movieName, "\n")] = 0; // Remove newline
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);
            getchar(); // Clear newline
            rateMovie(movieName, rating);
        } else if (strcmp(command, "3") == 0) {
            displayMovies();
        } else if (strcmp(command, "4") == 0) {
            saveMoviesToFile("movies.dat");
            break; // Exit after saving
        } else if (strcmp(command, "5") == 0) {
            break; // Exit without saving
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}