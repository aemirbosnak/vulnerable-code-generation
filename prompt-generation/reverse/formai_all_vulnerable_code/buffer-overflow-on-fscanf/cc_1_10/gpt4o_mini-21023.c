//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int totalRatings;
    float averageRating;
    int ratingCount;
} Movie;

void initializeMovies(Movie movies[], int *movieCount) {
    *movieCount = 0;
}

void readRatingsFromFile(const char *filename, Movie movies[], int *movieCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oops! Can't open the file: %s\n", filename);
        return;
    }
    
    char movieName[MAX_NAME_LENGTH];
    int rating;

    while (fscanf(file, "%s %d", movieName, &rating) != EOF) {
        int found = 0;
        for (int i = 0; i < *movieCount; i++) {
            if (strcmp(movies[i].name, movieName) == 0) {
                movies[i].totalRatings += rating;
                movies[i].ratingCount += 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(movies[*movieCount].name, movieName);
            movies[*movieCount].totalRatings = rating;
            movies[*movieCount].ratingCount = 1;
            (*movieCount)++;
        }
    }

    fclose(file);
}

void calculateAverageRatings(Movie movies[], int movieCount) {
    for (int i = 0; i < movieCount; i++) {
        movies[i].averageRating = (float)movies[i].totalRatings / movies[i].ratingCount;
    }
}

void displayMovies(const Movie movies[], int movieCount) {
    printf("\nYay! Here are the movie ratings:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie: %s | Average Rating: %.2f | Ratings Count: %d\n", 
               movies[i].name, movies[i].averageRating, movies[i].ratingCount);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount;

    initializeMovies(movies, &movieCount);
    readRatingsFromFile("movie_ratings.txt", movies, &movieCount);
    calculateAverageRatings(movies, movieCount);
    
    displayMovies(movies, movieCount);

    printf("\nThank you for using the Happy Movie Rating Miner!\n");
    return 0;
}