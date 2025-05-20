//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float rating;
    int numRatings;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int movieCount;
} MovieRatingSystem;

void initializeSystem(MovieRatingSystem *system) {
    system->movieCount = 0;
}

void addMovie(MovieRatingSystem *system, const char *name) {
    if (system->movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum capacity reached.\n");
        return;
    }
    strncpy(system->movies[system->movieCount].name, name, NAME_LENGTH);
    system->movies[system->movieCount].rating = 0.0;
    system->movies[system->movieCount].numRatings = 0;
    system->movieCount++;
    printf("Movie '%s' added successfully!\n", name);
}

void rateMovie(MovieRatingSystem *system, const char *name, float rating) {
    for (int i = 0; i < system->movieCount; i++) {
        if (strcmp(system->movies[i].name, name) == 0) {
            system->movies[i].numRatings++;
            system->movies[i].rating += (rating - system->movies[i].rating) / system->movies[i].numRatings;
            printf("Rating of %.1f added to movie '%s'. Current average rating: %.1f\n",
                   rating, name, system->movies[i].rating);
            return;
        }
    }
    printf("Movie '%s' not found!\n", name);
}

void displayRatings(MovieRatingSystem *system) {
    if (system->movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < system->movieCount; i++) {
        printf("Movie: %s | Average Rating: %.1f | Ratings Count: %d\n",
               system->movies[i].name, system->movies[i].rating, system->movies[i].numRatings);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    MovieRatingSystem system;
    initializeSystem(&system);
    
    int choice;
    char name[NAME_LENGTH];
    float rating;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Ratings\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove trailing newline
                addMovie(&system, name);
                break;
            case 2:
                printf("Enter movie name to rate: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove trailing newline
                printf("Enter rating (0 to 10): ");
                scanf("%f", &rating);
                clearInputBuffer();
                if (rating < 0 || rating > 10) {
                    printf("Rating must be between 0 and 10!\n");
                } else {
                    rateMovie(&system, name, rating);
                }
                break;
            case 3:
                displayRatings(&system);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}