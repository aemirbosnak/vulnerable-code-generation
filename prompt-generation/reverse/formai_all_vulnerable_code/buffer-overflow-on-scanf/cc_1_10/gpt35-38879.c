//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

// struct to hold movie details
typedef struct {
    char title[50];
    char genre[20];
    int releaseYear;
    float rating;
} Movie;

// function to add a movie to the system
void addMovie(Movie movies[], int index) {
    printf("Enter title of the movie: ");
    scanf("%s", movies[index].title);
    printf("Enter the genre of the movie: ");
    scanf("%s", movies[index].genre);
    printf("Enter the release year of the movie: ");
    scanf("%d", &movies[index].releaseYear);
    printf("Enter the rating of the movie (out of 10): ");
    scanf("%f", &movies[index].rating);
    printf("Movie added successfully!\n");
}

// function to display all movies in the system
void displayMovies(Movie movies[], int numMovies) {
    printf("All Movies:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%d. %s (%s) - %d - %.1f/10\n", i+1, movies[i].title, movies[i].genre, movies[i].releaseYear, movies[i].rating);
    }
}

// function to update the rating of a movie
void updateRating(Movie movies[], int index) {
    printf("Enter new rating for %s: ", movies[index].title);
    scanf("%f", &movies[index].rating);
    printf("Rating updated successfully!\n");
}

int main() {
    // array to hold movies
    Movie movies[50];
    int numMovies = 0;
    char input;

    // loop to display menu
    while (1) {
        printf("\nC Movie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Update rating of a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &input);

        // switch to perform selected action
        switch(input) {
            case '1':
                addMovie(movies, numMovies);
                numMovies++;
                break;
            case '2':
                displayMovies(movies, numMovies);
                break;
            case '3':
                if (numMovies == 0) {
                    printf("No movies in the system. Please add a movie first.\n");
                    break;
                }
                int index;
                printf("Enter index of movie to update: ");
                scanf("%d", &index);
                index -= 1;
                if (index < 0 || index >= numMovies) {
                    printf("Invalid movie index. Please try again.\n");
                    break;
                }
                updateRating(movies, index);
                break;
            case '4':
                printf("Thank you for using C Movie Rating System!\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}