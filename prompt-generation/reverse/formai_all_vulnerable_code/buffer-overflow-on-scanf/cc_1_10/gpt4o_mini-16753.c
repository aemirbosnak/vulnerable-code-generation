//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float rating;
    int votes;
} Movie;

void initializeMovies(Movie movies[], int *count) {
    *count = 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie name: ");
    scanf("%s", newMovie.name);
    
    printf("Enter your rating (0 to 10): ");
    scanf("%f", &newMovie.rating);
    
    newMovie.votes = 1; // this is the first vote
    movies[*count] = newMovie;
    (*count)++;
    
    printf("Movie added successfully!\n");
}

void rateMovie(Movie movies[], int count) {
    char name[NAME_LENGTH];
    printf("Enter movie name to rate: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            float newRating;
            printf("Enter your new rating (0 to 10): ");
            scanf("%f", &newRating);
            
            // Update the average rating
            movies[i].rating = ((movies[i].rating * movies[i].votes) + newRating) / (++movies[i].votes);
            printf("Rating updated successfully!\n");
            return;
        }
    }
    
    printf("Movie not found!\n");
}

void printMovies(const Movie movies[], int count) {
    printf("\nMovies Rated:\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Rating: %.2f | Votes: %d\n", movies[i].name, movies[i].rating, movies[i].votes);
    }
    printf("-----------------------------------------------------------\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount;
    int choice;

    initializeMovies(movies, &movieCount);

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add a new movie\n");
        printf("2. Rate an existing movie\n");
        printf("3. View all movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                printMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}