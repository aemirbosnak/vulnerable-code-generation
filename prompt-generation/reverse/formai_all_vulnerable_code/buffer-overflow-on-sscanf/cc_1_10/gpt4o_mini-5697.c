//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int year;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieList;

void initializeMovieList(MovieList* list) {
    list->count = 0;
}

void addMovie(MovieList* list, const char* title, float rating, int year) {
    if (list->count < MAX_MOVIES) {
        strncpy(list->movies[list->count].title, title, TITLE_LENGTH);
        list->movies[list->count].rating = rating;
        list->movies[list->count].year = year;
        list->count++;
        printf("Movie added: %s (%d) with rating %.1f\n", title, year, rating);
    } else {
        printf("Movie list is full. Cannot add more movies.\n");
    }
}

void displayMovies(const MovieList* list) {
    if (list->count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%d) - Rating: %.1f\n", i + 1, list->movies[i].title, list->movies[i].year, list->movies[i].rating);
    }
}

void displayAverageRating(const MovieList* list) {
    if (list->count == 0) {
        printf("No movies to calculate an average rating.\n");
        return;
    }

    float totalRating = 0.0f;
    for (int i = 0; i < list->count; i++) {
        totalRating += list->movies[i].rating;
    }
    float averageRating = totalRating / list->count;
    printf("Average rating of all movies: %.1f\n", averageRating);
}

void saveMoviesToFile(const MovieList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%d,%.1f\n", list->movies[i].title, list->movies[i].year, list->movies[i].rating);
    }
    
    fclose(file);
    printf("Movies saved to %s.\n", filename);
}

void loadMoviesFromFile(MovieList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    char buffer[200]; // Buffer to hold a line from the file
    while (fgets(buffer, sizeof(buffer), file) && list->count < MAX_MOVIES) {
        char title[TITLE_LENGTH];
        int year;
        float rating;
        sscanf(buffer, "%99[^,],%d,%f", title, &year, &rating);
        
        addMovie(list, title, rating, year);
    }
    
    fclose(file);
    printf("Movies loaded from %s.\n", filename);
}

int main() {
    MovieList myMovies;
    initializeMovieList(&myMovies);
    
    int choice;
    do {
        printf("\nMovie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Display Average Rating\n");
        printf("4. Save Movies to File\n");
        printf("5. Load Movies from File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1: {
                char title[TITLE_LENGTH];
                float rating;
                int year;

                printf("Enter movie title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                printf("Enter movie rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                printf("Enter movie year: ");
                scanf("%d", &year);

                addMovie(&myMovies, title, rating, year);
                break;
            }
            case 2:
                displayMovies(&myMovies);
                break;
            case 3:
                displayAverageRating(&myMovies);
                break;
            case 4: {
                char filename[50];
                printf("Enter filename to save movies: ");
                scanf("%s", filename);
                saveMoviesToFile(&myMovies, filename);
                break;
            }
            case 5: {
                char filename[50];
                printf("Enter filename to load movies: ");
                scanf("%s", filename);
                loadMoviesFromFile(&myMovies, filename);
                break;
            }
            case 0:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}