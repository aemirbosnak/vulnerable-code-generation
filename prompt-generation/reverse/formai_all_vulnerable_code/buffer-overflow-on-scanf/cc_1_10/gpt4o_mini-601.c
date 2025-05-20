//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char title[MAX_NAME_LENGTH];
    float rating;
    int year;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar();  // to consume the newline character from the previous input
    fgets(movies[*count].title, MAX_NAME_LENGTH, stdin);
    strtok(movies[*count].title, "\n");  // remove newline character

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    printf("Enter movie release year: ");
    scanf("%d", &movies[*count].year);
    
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (%.1f) - %d\n", i + 1, movies[i].title, movies[i].rating, movies[i].year);
    }
}

void searchMovie(const Movie movies[], int count) {
    char searchTitle[MAX_NAME_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar();  // to consume the newline character
    fgets(searchTitle, MAX_NAME_LENGTH, stdin);
    strtok(searchTitle, "\n");  // remove newline character
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Found: %s (%.1f) - %d\n", movies[i].title, movies[i].rating, movies[i].year);
            return;
        }
    }
    printf("Movie not found.\n");
}

void deleteMovie(Movie movies[], int *count) {
    int index;
    printf("Enter the number of the movie to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid movie number.\n");
        return;
    }
    
    index--;  // convert to 0-based index
    for (int i = index; i < *count - 1; i++) {
        movies[i] = movies[i + 1];
    }
    (*count)--;
    printf("Movie deleted successfully!\n");
}

void saveMovies(const Movie movies[], int count) {
    FILE *file = fopen("movies.dat", "wb");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    fwrite(movies, sizeof(Movie), count, file);
    fclose(file);
    printf("Movies saved to 'movies.dat'.\n");
}

void loadMovies(Movie movies[], int *count) {
    FILE *file = fopen("movies.dat", "rb");
    if (!file) {
        printf("Could not open file for reading. Starting fresh.\n");
        return;
    }
    
    *count = fread(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
    printf("Movies loaded: %d\n", *count);
}

void displayMenu() {
    printf("\nMovie Rating System Menu:\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Save Movies\n");
    printf("6. Load Movies\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    loadMovies(movies, &count);
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                saveMovies(movies, count);
                break;
            case 6:
                loadMovies(movies, &count);
                break;
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}