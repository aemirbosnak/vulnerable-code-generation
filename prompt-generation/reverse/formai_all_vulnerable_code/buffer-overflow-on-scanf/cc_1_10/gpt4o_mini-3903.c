//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float ratings[MAX_MOVIES];
    int ratingCount;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies.\n");
        return;
    }
    
    printf("Enter movie title: ");
    scanf(" %[^\n]%*c", movies[movieCount].title);
    movies[movieCount].ratingCount = 0; // Initialize rating count
    movieCount++;
    printf("Movie '%s' added successfully!\n", movies[movieCount - 1].title);
}

void rateMovie() {
    char title[MAX_TITLE_LENGTH];
    float rating;

    printf("Enter movie title to rate: ");
    scanf(" %[^\n]%*c", title);
    
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter your rating (0-10): ");
            scanf("%f", &rating);
            if (rating < 0 || rating > 10) {
                printf("Invalid rating. Please enter a number between 0 and 10.\n");
            } else {
                movies[i].ratings[movies[i].ratingCount] = rating;
                movies[i].ratingCount++;
                printf("Thank you for rating '%s' with %.1f!\n", title, rating);
            }
            return;
        }
    }
    
    printf("Movie not found.\n");
}

void displayAverageRatings() {
    printf("\nAverage Movie Ratings:\n");
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].ratingCount > 0) {
            float sum = 0;
            for (int j = 0; j < movies[i].ratingCount; j++) {
                sum += movies[i].ratings[j];
            }
            float average = sum / movies[i].ratingCount;
            printf("'%s' - Average Rating: %.2f\n", movies[i].title, average);
        } else {
            printf("'%s' has not been rated yet.\n", movies[i].title);
        }
    }
}

void saveMoviesToFile() {
    FILE *file = fopen("movies.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(movies, sizeof(Movie), movieCount, file);
    fclose(file);
    printf("Movies saved to file successfully!\n");
}

void loadMoviesFromFile() {
    FILE *file = fopen("movies.dat", "rb");
    if (file == NULL) {
        printf("No saved movies found.\n");
        return;
    }
    movieCount = fread(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
    printf("Movies loaded from file successfully!\n");
}

void showMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Display Average Ratings\n");
    printf("4. Save Movies to File\n");
    printf("5. Load Movies from File\n");
    printf("6. Exit\n");
    printf("===========================\n");
}

int main() {
    int choice;
    loadMoviesFromFile();
    
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayAverageRatings();
                break;
            case 4:
                saveMoviesToFile();
                break;
            case 5:
                loadMoviesFromFile();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}