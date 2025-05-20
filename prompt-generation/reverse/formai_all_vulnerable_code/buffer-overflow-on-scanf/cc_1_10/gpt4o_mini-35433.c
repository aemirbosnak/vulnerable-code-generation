//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50

struct Movie {
    char title[TITLE_LENGTH];
    int rating;
};

void addMovie(struct Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }
    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[*count].title);
    
    printf("Enter rating (1-5): ");
    scanf("%d", &movies[*count].rating);
    
    if (movies[*count].rating < 1 || movies[*count].rating > 5) {
        printf("Rating must be between 1 and 5. Movie not added.\n");
        return;
    }

    (*count)++;
    printf("Movie added successfully!\n");
}

void viewMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }
    printf("\nMovies and Ratings:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Rating: %d\n", i + 1, movies[i].title, movies[i].rating);
    }
}

float calculateAverageRating(struct Movie movies[], int count) {
    if (count == 0) return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }
    return (float)totalRating / count;
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. View Average Rating\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                printf("Average Rating: %.2f\n", calculateAverageRating(movies, count));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}