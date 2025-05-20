//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_SCALE 5

typedef struct {
    char title[TITLE_LENGTH];
    int ratings[RATING_SCALE]; // Array to hold ratings from different age groups
    float averageRating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movieList[movieCount].title);
    
    for (int i = 0; i < RATING_SCALE; i++) {
        printf("Enter rating (0-10) for age group %d: ", i + 1);
        scanf("%d", &movieList[movieCount].ratings[i]);

        // Validate rating input
        while (movieList[movieCount].ratings[i] < 0 || movieList[movieCount].ratings[i] > 10) {
            printf("Invalid rating. Please enter a rating between 0 and 10: ");
            scanf("%d", &movieList[movieCount].ratings[i]);
        }
    }

    movieCount++;
    printf("Movie added successfully!\n");
}

void calculateAverageRatings() {
    for (int i = 0; i < movieCount; i++) {
        int total = 0;
        for (int j = 0; j < RATING_SCALE; j++) {
            total += movieList[i].ratings[j];
        }
        movieList[i].averageRating = (float)total / RATING_SCALE;
    }
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n*** Movie Ratings ***\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movieList[i].title);
        printf("Ratings: ");
        for (int j = 0; j < RATING_SCALE; j++) {
            printf("%d ", movieList[i].ratings[j]);
        }
        printf("\nAverage Rating: %.2f\n", movieList[i].averageRating);
        printf("-----------------------------\n");
    }
}

void saveMoviesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(file, "%s,", movieList[i].title);
        for (int j = 0; j < RATING_SCALE; j++) {
            fprintf(file, "%d", movieList[i].ratings[j]);
            if (j < RATING_SCALE - 1) fprintf(file, ",");
        }
        fprintf(file, ",%.2f\n", movieList[i].averageRating);
    }

    fclose(file);
    printf("Movies saved to %s successfully!\n", filename);
}

void loadMoviesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fgets(movieList[movieCount].title, TITLE_LENGTH, file) && movieCount < MAX_MOVIES) {
        char *token = strtok(movieList[movieCount].title, ",");
        int j = 0;

        while (token != NULL && j < RATING_SCALE) {
            movieList[movieCount].ratings[j] = atoi(token);
            token = strtok(NULL, ",");
            j++;
        }
        movieList[movieCount].averageRating = atof(strtok(NULL, ","));
        movieCount++;
    }

    fclose(file);
    printf("Movies loaded from %s successfully!\n", filename);
}

int main() {
    int choice;
    char filename[50];

    do {
        printf("\n*** Movie Rating System Menu ***\n");
        printf("1. Add Movie\n");
        printf("2. Calculate Average Ratings\n");
        printf("3. Display Movies\n");
        printf("4. Save Movies to File\n");
        printf("5. Load Movies from File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                calculateAverageRatings();
                printf("Average ratings calculated.\n");
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("Enter filename to save movies: ");
                scanf("%s", filename);
                saveMoviesToFile(filename);
                break;
            case 5:
                printf("Enter filename to load movies: ");
                scanf("%s", filename);
                loadMoviesFromFile(filename);
                break;
            case 6:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}