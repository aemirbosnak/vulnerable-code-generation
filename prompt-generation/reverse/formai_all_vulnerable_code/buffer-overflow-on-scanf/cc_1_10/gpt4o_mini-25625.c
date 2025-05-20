//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    int year;
    float score;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void addMovie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[movie_count].title);
    
    printf("Enter movie rating (e.g. PG, R, NC-17): ");
    scanf(" %[^\n]", movies[movie_count].rating);
    
    printf("Enter release year: ");
    scanf("%d", &movies[movie_count].year);
    
    printf("Enter movie score (1-10): ");
    scanf("%f", &movies[movie_count].score);

    movie_count++;
    printf("Movie added successfully!\n\n");
}

void displayMovies() {
    if (movie_count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    printf("\nList of movies:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s, Rating: %s, Year: %d, Score: %.1f\n",
               movies[i].title, movies[i].rating, movies[i].year, movies[i].score);
    }
    printf("\n");
}

void findMovie() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    scanf(" %[^\n]", searchTitle);
    
    for (int i = 0; i < movie_count; i++) {
        if (strstr(movies[i].title, searchTitle) != NULL) {
            printf("Found: Title: %s, Rating: %s, Year: %d, Score: %.1f\n",
                   movies[i].title, movies[i].rating, movies[i].year, movies[i].score);
            return;
        }
    }
    printf("Movie not found.\n\n");
}

void deleteMovie() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    scanf(" %[^\n]", deleteTitle);
    
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].title, deleteTitle) == 0) {
            for (int j = i; j < movie_count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            movie_count--;
            printf("Movie deleted successfully!\n\n");
            return;
        }
    }
    printf("Movie not found.\n\n");
}

void saveMoviesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < movie_count; i++) {
        fprintf(file, "%s|%s|%d|%.1f\n", movies[i].title, movies[i].rating, movies[i].year, movies[i].score);
    }
    
    fclose(file);
    printf("Movies saved to file successfully!\n\n");
}

void loadMoviesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No file found. Starting with an empty movie list.\n\n");
        return;
    }
    
    while (fscanf(file, " %[^|]|%[^|]|%d|%f\n", movies[movie_count].title, movies[movie_count].rating,
                  &movies[movie_count].year, &movies[movie_count].score) == 4) {
        movie_count++;
        if (movie_count >= MAX_MOVIES) {
            break;
        }
    }

    fclose(file);
    printf("Movies loaded from file successfully!\n\n");
}

int main() {
    int choice;
    const char *filename = "movies.txt";
    
    loadMoviesFromFile(filename);
    
    do {
        printf("Movie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Find Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Save Movies to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                findMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                saveMoviesToFile(filename);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 6);

    return 0;
}