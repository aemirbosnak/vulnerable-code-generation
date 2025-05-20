//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // to consume the newline character left by previous input
    fgets(movieList[movieCount].title, TITLE_LENGTH, stdin);
    
    // Remove newline character from title
    size_t len = strlen(movieList[movieCount].title);
    if (len > 0 && movieList[movieCount].title[len - 1] == '\n') {
        movieList[movieCount].title[len - 1] = '\0';
    }

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movieList[movieCount].rating);

    if (movieList[movieCount].rating < 0.0 || movieList[movieCount].rating > 10.0) {
        printf("Rating must be between 0.0 and 10.0. Movie not added.\n");
        return;
    }

    movieCount++;
    printf("Movie added successfully!\n");
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies added!\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %.1f\n", i + 1, movieList[i].title, movieList[i].rating);
    }
}

void searchMovie() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    getchar(); // consume newline
    fgets(searchTitle, TITLE_LENGTH, stdin);
    
    // Remove newline character from search title
    size_t len = strlen(searchTitle);
    if (len > 0 && searchTitle[len - 1] == '\n') {
        searchTitle[len - 1] = '\0';
    }

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            printf("Found: %s - Rating: %.1f\n", movieList[i].title, movieList[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

void deleteMovie() {
    char delTitle[TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    getchar(); // consume newline
    fgets(delTitle, TITLE_LENGTH, stdin);
    
    // Remove newline character from delete title
    size_t len = strlen(delTitle);
    if (len > 0 && delTitle[len - 1] == '\n') {
        delTitle[len - 1] = '\0';
    }

    int found = -1;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, delTitle) == 0) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        for (int i = found; i < movieCount - 1; i++) {
            movieList[i] = movieList[i + 1];
        }
        movieCount--;
        printf("Movie deleted successfully!\n");
    } else {
        printf("Movie not found.\n");
    }
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}