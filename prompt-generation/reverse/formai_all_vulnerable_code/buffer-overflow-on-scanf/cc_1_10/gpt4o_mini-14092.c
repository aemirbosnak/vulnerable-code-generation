//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 30
#define MAX_REVIEW_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;  // rating out of 5.0
    char review[MAX_REVIEW_LENGTH];
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    
    printf("Enter movie title: ");
    getchar();  // Clear the newline left by previous input
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = '\0';  // Remove newline character
    
    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = '\0';  // Remove newline character
    
    printf("Enter rating (0.0 - 5.0): ");
    scanf("%f", &newMovie.rating);
    
    getchar();  // Clear newline left by scanf
    printf("Enter your review: ");
    fgets(newMovie.review, MAX_REVIEW_LENGTH, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = '\0';  // Remove newline character
    
    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("\nMovie #%d\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %.1f/5.0\n", movies[i].rating);
        printf("Review: %s\n", movies[i].review);
    }
}

void findHighestRatedMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }

    float highestRating = 0.0;
    int highestIndex = 0;

    for (int i = 0; i < count; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestIndex = i;
        }
    }

    printf("\nHighest Rated Movie:\n");
    printf("Title: %s\n", movies[highestIndex].title);
    printf("Genre: %s\n", movies[highestIndex].genre);
    printf("Rating: %.1f/5.0\n", movies[highestIndex].rating);
    printf("Review: %s\n", movies[highestIndex].review);
}

void saveMoviesToFile(Movie movies[], int count) {
    FILE *file = fopen("movies.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Title: %s\nGenre: %s\nRating: %.1f\nReview: %s\n\n",
                movies[i].title, movies[i].genre, movies[i].rating, movies[i].review);
    }

    fclose(file);
    printf("Movies saved to movies.txt successfully!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\nMovie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Find Highest Rated Movie\n");
        printf("4. Save Movies to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                findHighestRatedMovie(movies, movieCount);
                break;
            case 4:
                saveMoviesToFile(movies, movieCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}