//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie();
void viewMovies();
float calculateAverageRating();
void clearBuffer();

int main() {
    int choice;

    while(1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. Calculate Average Rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            clearBuffer(); // Clear the input buffer in case of invalid input
            printf("Please enter a valid choice.\n");
            continue;
        }

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                calculateAverageRating();
                break;
            case 4:
                printf("Exiting the system... Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }
    
    Movie movie;
    printf("Enter movie title: ");
    clearBuffer(); // Clear the input buffer
    fgets(movie.title, TITLE_LENGTH, stdin);
    movie.title[strcspn(movie.title, "\n")] = '\0'; // Remove newline
    
    printf("Enter movie rating (0 - 10): ");
    while (1) {
        // Input validation for rating
        if (scanf("%f", &movie.rating) != 1 || movie.rating < 0 || movie.rating > 10) {
            printf("Please enter a valid rating between 0 and 10: ");
            clearBuffer(); // Clear the input buffer
        } else {
            break;
        }
    }
    
    movieList[movieCount] = movie;
    movieCount++;
    printf("Movie \"%s\" with rating %.1f added successfully!\n", movie.title, movie.rating);
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies found!\n");
        return;
    }
    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s (Rating: %.1f)\n", i + 1, movieList[i].title, movieList[i].rating);
    }
}

float calculateAverageRating() {
    if (movieCount == 0) {
        printf("No movies found to calculate average rating!\n");
        return 0;
    }
    
    float sum = 0;
    for (int i = 0; i < movieCount; i++) {
        sum += movieList[i].rating;
    }
    float average = sum / movieCount;
    printf("The average rating is: %.2f\n", average);
    return average;
}

void clearBuffer() {
    while (getchar() != '\n');
}