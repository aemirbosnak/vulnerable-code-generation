//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>

// struct to store movie information
typedef struct {
    char title[100];
    char director[100];
    int year;
    double rating;
} Movie;

// function to get movie information from user
Movie getMovieInfo() {
    Movie movie;
    printf("Enter movie title: ");
    scanf("%[^\n]", movie.title);
    fflush(stdin);
    printf("Enter director name: ");
    scanf("%[^\n]", movie.director);
    fflush(stdin);
    printf("Enter release year: ");
    scanf("%d", &movie.year);
    fflush(stdin);
    printf("Enter movie rating (out of 10): ");
    scanf("%lf", &movie.rating);
    fflush(stdin);
    return movie;
}

// function to print movie information
void printMovieInfo(Movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year of release: %d\n", movie.year);
    printf("Rating: %.1lf\n", movie.rating);
}

// function to rate a movie
double rateMovie(Movie movie) {
    double newRating;
    printf("Enter your rating for the movie '%s' (out of 10): ", movie.title);
    scanf("%lf", &newRating);
    fflush(stdin);
    return (movie.rating + newRating) / 2;
}

int main() {
    int choice, numMovies;
    Movie movies[10];
    printf("Welcome to the Movie Rating System!\n\n");

    // loop until user chooses to exit
    do {
        printf("Enter your choice (1 - Add movie; 2 - Rate movie; 3 - Print movie list; 4 - Exit): ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                if (numMovies < 10) {
                    Movie newMovie = getMovieInfo();
                    movies[numMovies] = newMovie;
                    numMovies++;
                } else {
                    printf("\nSorry, the maximum number of movies has been reached.\n\n");
                }
                break;
            case 2:
                if (numMovies > 0) {
                    printf("\nEnter the index (1 - %d) of the movie you would like to rate: ", numMovies);
                    int index;
                    scanf("%d", &index);
                    fflush(stdin);
                    if (index >= 1 && index <= numMovies) {
                        movies[index-1].rating = rateMovie(movies[index-1]);
                    } else {
                        printf("\nInvalid index entered. Please try again.\n\n");
                    }
                } else {
                    printf("\nNo movies have been added yet.\n\n");
                }
                break;
            case 3:
                if (numMovies > 0) {
                    printf("\nMovie List:\n\n");
                    for (int i = 0; i < numMovies; i++) {
                        printf("%d) ", i+1);
                        printMovieInfo(movies[i]);
                        printf("\n");
                    }
                } else {
                    printf("\nNo movies have been added yet.\n\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Movie Rating System. Goodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice entered. Please try again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}