//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

void displayMovies(Movie movies[], int count) {
    printf("\nMovie List:\n");
    printf("------------------------------------------------\n");
    printf("| %s | %s |\n", "Movie Title", "Rating");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %.2f |\n", movies[i].title, movies[i].rating);
    }
    printf("------------------------------------------------\n");
}

float calculateAverageRating(Movie movies[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    return count > 0 ? total / count : 0.0;
}

int findMovie(Movie movies[], int count, const char *title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return i; // Movie found
        }
    }
    return -1; // Movie not found
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title (max %d characters): ", MAX_TITLE_LENGTH - 1);
    getchar(); // To consume the newline character left in the buffer
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = '\0'; // Remove newline character

    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    
    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Rating must be between 0.0 and 10.0. Movie not added.\n");
        return;
    }

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void updateMovie(Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title to update: ");
    getchar(); // To consume the newline character left in the buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    int index = findMovie(movies, count, title);
    if (index != -1) {
        printf("Update rating for '%s': ", title);
        scanf("%f", &movies[index].rating);

        if (movies[index].rating < 0 || movies[index].rating > 10) {
            printf("Rating must be between 0.0 and 10.0. Update failed.\n");
            return;
        }

        printf("Rating updated successfully!\n");
    } else {
        printf("Movie not found in the list.\n");
    }
}

void deleteMovie(Movie movies[], int *count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title to delete: ");
    getchar(); // To consume the newline character left in the buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    int index = findMovie(movies, *count, title);
    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            movies[i] = movies[i + 1];
        }
        (*count)--;
        printf("Movie deleted successfully!\n");
    } else {
        printf("Movie not found in the list.\n");
    }
}

void saveMoviesToFile(Movie movies[], int count) {
    FILE *file = fopen("movies.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%.2f\n", movies[i].title, movies[i].rating);
    }
    fclose(file);
    printf("Movies saved to file successfully!\n");
}

void loadMoviesFromFile(Movie movies[], int *count) {
    FILE *file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("No saved movie list found.\n");
        return;
    }
    
    while (fscanf(file, "%[^|]|%f\n", movies[*count].title, &movies[*count].rating) != EOF) {
        (*count)++;
        if (*count >= MAX_MOVIES) {
            printf("Movie list loaded up to max limit.\n");
            break;
        }
    }
    fclose(file);
    printf("Movies loaded from file successfully!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    loadMoviesFromFile(movies, &count);
    
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Update Movie Rating\n");
        printf("3. Delete Movie\n");
        printf("4. Display Movies\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Calculate Average Rating\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMovie(movies, &count); break;
            case 2: updateMovie(movies, count); break;
            case 3: deleteMovie(movies, &count); break;
            case 4: displayMovies(movies, count); break;
            case 5: saveMoviesToFile(movies, count); break;
            case 6: loadMoviesFromFile(movies, &count); break;
            case 7: {
                float average = calculateAverageRating(movies, count);
                printf("Average Rating: %.2f\n", average);
                break;
            }
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}