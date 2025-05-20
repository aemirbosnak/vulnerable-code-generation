//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    int ratings[MAX_MOVIES];
    int ratingCount;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

// Function prototypes
void addMovie(const char* title);
void rateMovie(const char* title, int rating);
void displayMovies();
float averageRating(const char* title);

// Main function
int main() {
    int choice;
    char title[MAX_TITLE_LEN];
    int rating;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                addMovie(title);
                break;

            case 2:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter rating (1-5): ");
                scanf("%d", &rating);
                if (rating >= 1 && rating <= 5) {
                    rateMovie(title, rating);
                } else {
                    printf("Invalid rating. Please enter a number between 1 and 5.\n");
                }
                break;

            case 3:
                displayMovies();
                break;

            case 4:
                printf("Exiting the system.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function implementations
void addMovie(const char* title) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movies[movieCount].title, title);
        movies[movieCount].ratingCount = 0;
        movieCount++;
        printf("Movie \"%s\" added successfully.\n", title);
    } else {
        printf("Movie list is full, cannot add more movies.\n");
    }
}

void rateMovie(const char* title, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].ratingCount < MAX_MOVIES) {
                movies[i].ratings[movies[i].ratingCount++] = rating;
                printf("Rating of %d added for movie \"%s\".\n", rating, title);
            } else {
                printf("Rating list for movie \"%s\" is full.\n", title);
            }
            return;
        }
    }
    printf("Movie \"%s\" not found.\n", title);
}

void displayMovies() {
    for (int i = 0; i < movieCount; i++) {
        float avgRating = averageRating(movies[i].title);
        printf("Movie Title: \"%s\", Average Rating: %.2f\n", movies[i].title, avgRating);
    }
}

float averageRating(const char* title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0 && movies[i].ratingCount > 0) {
            int total = 0;
            for (int j = 0; j < movies[i].ratingCount; j++) {
                total += movies[i].ratings[j];
            }
            return (float)total / movies[i].ratingCount;
        }
    }
    return 0.0; // No ratings available
}