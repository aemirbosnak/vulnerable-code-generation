//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char director[50];
    char rating[3];
} movie;

void addMovie(movie *m) {
    printf("Enter movie title: ");
    scanf("%s", m->title);
    printf("Enter movie director: ");
    scanf("%s", m->director);
    printf("Enter movie rating: ");
    scanf("%s", m->rating);
    printf("Movie added!\n\n");
}

void displayRating(movie *m) {
    printf("%s has a rating of %s\n\n", m->title, m->rating);
}

void displayAllMovies(movie *movies, int size) {
    printf("All Movies:\n\n");
    for (int i = 0; i < size; i++) {
        printf("%d) %s\n", i+1, movies[i].title);
    }
    printf("\n");
}

int main() {
    int option, numMovies = 0, numRatings = 0;
    movie *movies = malloc(sizeof(movie)); // allocate memory for one movie
    
    printf("Welcome to the Genius Movie Rating System!\n\n");
    
    do {
        printf("Menu:\n");
        printf("1. Add a movie\n");
        printf("2. View a movie's rating\n");
        printf("3. View all movies\n");
        printf("4. Exit program\n\n");
        printf("Enter an option (1-4): ");
        scanf("%d", &option);
        printf("\n");
        
        switch(option) {
            case 1:
                numMovies++;
                movies = realloc(movies, numMovies * sizeof(movie)); // increase memory for new movie
                addMovie(&movies[numMovies-1]); // add movie to end of list
                break;
            case 2:
                if (numMovies == 0) {
                    printf("Error: No movies added yet!\n\n");
                    break;
                }
                int movieChoice;
                displayAllMovies(movies, numMovies);
                printf("Enter the number of the movie to view its rating: ");
                scanf("%d", &movieChoice);
                printf("\n");
                if (movieChoice < 1 || movieChoice > numMovies) {
                    printf("Error: Invalid movie choice!\n\n");
                    break;
                }
                displayRating(&movies[movieChoice-1]);
                numRatings++; // increment number of ratings
                break;
            case 3:
                if (numMovies == 0) {
                    printf("Error: No movies added yet!\n\n");
                    break;
                }
                printf("All movie ratings:\n\n");
                for (int i = 0; i < numMovies; i++) {
                    displayRating(&movies[i]);
                }
                break;
            case 4:
                printf("Exiting Genius Movie Rating System...\n");
                break;
            default:
                printf("Error: Invalid option!\n\n");
        }
    } while (option != 4);
    
    free(movies); // free memory used by movies array
    return 0;
}