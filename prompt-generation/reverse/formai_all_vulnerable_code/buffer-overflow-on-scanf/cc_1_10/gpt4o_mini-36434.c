//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratings[MAX_MOVIES];
    int ratingCount;
} Movie;

Movie movieDB[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movieDB[movieCount].title, title);
        movieDB[movieCount].ratingCount = 0;
        movieCount++;
    } else {
        printf("Movie database is full!\n");
    }
}

void rateMovie(const char *title, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDB[i].title, title) == 0) {
            if (rating >= 1 && rating <= 10) {
                movieDB[i].ratings[movieDB[i].ratingCount] = rating;
                movieDB[i].ratingCount++;
                printf("Rated '%s' with %d stars.\n", title, rating);
                return;
            } else {
                printf("Rating must be between 1 and 10.\n");
                return;
            }
        }
    }
    printf("Movie '%s' not found!\n", title);
}

void displayMovies() {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s (%d ratings)\n", i + 1, movieDB[i].title, movieDB[i].ratingCount);
    }
}

float computeAverageRating(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDB[i].title, title) == 0) {
            int total = 0;
            for (int j = 0; j < movieDB[i].ratingCount; j++) {
                total += movieDB[i].ratings[j];
            }
            if (movieDB[i].ratingCount > 0) {
                return (float) total / movieDB[i].ratingCount;
            }
            return 0.0;
        }
    }
    return -1.0;  // Movie not found
}

void saveData() {
    FILE *file = fopen("movies.dat", "wb");
    if (file) {
        fwrite(movieDB, sizeof(Movie), movieCount, file);
        fclose(file);
        printf("Data saved successfully!\n");
    } else {
        printf("Error saving data!\n");
    }
}

void loadData() {
    FILE *file = fopen("movies.dat", "rb");
    if (file) {
        movieCount = fread(movieDB, sizeof(Movie), MAX_MOVIES, file);
        fclose(file);
        printf("Data loaded successfully!\n");
    } else {
        printf("No previous data found.\n");
    }
}

void showRatings(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDB[i].title, title) == 0) {
            printf("Ratings for '%s': ", title);
            for (int j = 0; j < movieDB[i].ratingCount; j++) {
                printf("%d ", movieDB[i].ratings[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Movie '%s' not found!\n", title);
}

int main() {
    loadData();
    int choice;
    char title[MAX_TITLE_LENGTH];
    int rating;

    while (1) {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Show Ratings\n");
        printf("5. Compute Average Rating\n");
        printf("6. Save Data\n");
        printf("7. Load Data\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                addMovie(title);
                break;
            case 2:
                printf("Enter movie title to rate: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter rating (1-10): ");
                scanf("%d", &rating);
                rateMovie(title, rating);
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("Enter movie title to show ratings: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;
                showRatings(title);
                break;
            case 5:
                printf("Enter movie title for average rating: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;
                float average = computeAverageRating(title);
                if (average >= 0) {
                    printf("Average rating for '%s': %.2f\n", title, average);
                } else {
                    printf("Movie '%s' not found!\n", title);
                }
                break;
            case 6:
                saveData();
                break;
            case 7:
                loadData();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}