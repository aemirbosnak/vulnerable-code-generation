//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing movie information
struct movie {
    char title[50];
    char director[50];
    int rating;
};

// Function to read in movie information from user
void readMovieInfo(struct movie *m) {
    char title[50], director[50];
    int rating;
    printf("\nTitle: ");
    scanf("%s", title);
    strcpy(m->title, title);
    printf("Director: ");
    scanf("%s", director);
    strcpy(m->director, director);
    printf("Rating (1-10): ");
    scanf("%d", &rating);
    m->rating = rating;
}

// Function to display a movie's information
void displayMovieInfo(struct movie m) {
    printf("\n%s\nDirector: %s\nRating: %d\n", m.title, m.director, m.rating);
}

// Main function
int main() {
    struct movie movies[10]; // Array of movie structs
    int numMovies = 0; // Number of movies in array
    int option = 0; // User's menu option
    while (option != 4) {
        // Display menu options
        printf("\n1. Add a movie\n2. View all movies\n3. View top rated movies\n4. Exit\nOption: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                if (numMovies >= 10) {
                    printf("\nError: Maximum number of movies reached.\n");
                } else {
                    readMovieInfo(&movies[numMovies]);
                    numMovies++;
                }
                break;
            case 2:
                if (numMovies == 0) {
                    printf("\nNo movies added yet.\n");
                } else {
                    for (int i = 0; i < numMovies; i++) {
                        displayMovieInfo(movies[i]);
                    }
                }
                break;
            case 3:
                if (numMovies == 0) {
                    printf("\nNo movies added yet.\n");
                } else {
                    int highestRating = 0;
                    for (int i = 0; i < numMovies; i++) {
                        if (movies[i].rating > highestRating) {
                            highestRating = movies[i].rating;
                        }
                    }
                    printf("\nTop rated movies:\n");
                    for (int i = 0; i < numMovies; i++) {
                        if (movies[i].rating == highestRating) {
                            displayMovieInfo(movies[i]);
                        }
                    }
                }
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}