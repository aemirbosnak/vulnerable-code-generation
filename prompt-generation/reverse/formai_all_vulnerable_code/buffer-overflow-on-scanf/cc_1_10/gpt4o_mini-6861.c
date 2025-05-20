//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: authentic
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

void addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }
    printf("Enter movie title: ");
    getchar(); // to consume the newline character from previous input
    fgets(movies[*movieCount].title, MAX_TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // remove newline
    movies[*movieCount].ratingCount = 0;
    (*movieCount)++;
    printf("Movie added successfully.\n");
}

void rateMovie(Movie *movies, int movieCount) {
    char title[MAX_TITLE_LENGTH];
    int rating;
    
    printf("Enter movie title to rate: ");
    getchar(); // to consume the newline character from previous input
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].ratingCount < MAX_MOVIES) {
                printf("Enter rating (1-5): ");
                scanf("%d", &rating);
                if (rating >= 1 && rating <= 5) {
                    movies[i].ratings[movies[i].ratingCount] = rating;
                    movies[i].ratingCount++;
                    printf("Rating added successfully.\n");
                } else {
                    printf("Invalid rating. Please enter a number between 1 and 5.\n");
                }
            } else {
                printf("Maximum number of ratings already given for this movie.\n");
            }
            return;
        }
    }
    printf("Movie not found.\n");
}

void viewAverageRating(Movie *movies, int movieCount) {
    char title[MAX_TITLE_LENGTH];
    
    printf("Enter movie title to view average rating: ");
    getchar(); // to consume the newline character from previous input
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            int totalRating = 0;
            for (int j = 0; j < movies[i].ratingCount; j++) {
                totalRating += movies[i].ratings[j];
            }
            float average = (float)totalRating / movies[i].ratingCount;
            printf("Average rating for '%s': %.2f\n", movies[i].title, average);
            return;
        }
    }
    printf("Movie not found.\n");
}

void displayMovies(Movie *movies, int movieCount) {
    printf("Movies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("- %s\n", movies[i].title);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. View Average Rating\n");
        printf("4. Display Movies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                viewAverageRating(movies, movieCount);
                break;
            case 4:
                displayMovies(movies, movieCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}