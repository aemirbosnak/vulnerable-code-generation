//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char title[NAME_LENGTH];
    char director[NAME_LENGTH];
    float rating;
    int year;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // To consume newline character from previous input
    fgets(movies[*count].title, NAME_LENGTH, stdin);
    strtok(movies[*count].title, "\n"); // Remove newline
    
    printf("Enter movie director: ");
    fgets(movies[*count].director, NAME_LENGTH, stdin);
    strtok(movies[*count].director, "\n"); // Remove newline
    
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    printf("Enter movie release year: ");
    scanf("%d", &movies[*count].year);
    
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Year: %d\n", movies[i].year);
        printf("---------------------------\n");
    }
}

void averageRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No ratings to calculate average!\n");
        return;
    }

    float totalRating = 0.0f;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }
    printf("Average Movie Rating: %.2f\n", totalRating / count);
}

void searchByTitle(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to search!\n");
        return;
    }

    char searchTitle[NAME_LENGTH];
    printf("Enter movie title to search: ");
    getchar(); // consume newline from previous input
    fgets(searchTitle, NAME_LENGTH, stdin);
    strtok(searchTitle, "\n"); // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Movie Found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Year: %d\n", movies[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printf("\nMovie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Average Rating\n");
        printf("4. Search by Title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addMovie(movies, &count);
                break;
            case 2: 
                displayMovies(movies, count);
                break;
            case 3: 
                averageRating(movies, count);
                break;
            case 4: 
                searchByTitle(movies, count);
                break;
            case 5: 
                printf("Exiting the system. Goodbye!\n");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}