//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a struct for movies
struct movie {
    char title[50];
    int releasedYear;
    char director[50];
    char genre[20];
    float rating;
};

// Declare functions
void printMovie(struct movie m);
void rateMovie(struct movie *m, float rating);
void getTopRatedMovies(struct movie m[], int size);
void getMoviesByGenre(struct movie m[], int size, char *genre);
int compareByRating(const void *a, const void *b);

// Main function
int main() {
    int option;
    int numMovies = 5;
    struct movie allMovies[numMovies];
    allMovies[0] = (struct movie){"The Godfather", 1972, "Francis Ford Coppola", "Crime, Drama", 9.2};
    allMovies[1] = (struct movie){"The Dark Knight", 2008, "Christopher Nolan", "Action, Crime, Drama", 9.0};
    allMovies[2] = (struct movie){"The Shawshank Redemption", 1994, "Frank Darabont", "Drama", 9.3};
    allMovies[3] = (struct movie){"Pulp Fiction", 1994, "Quentin Tarantino", "Crime, Drama", 8.9};
    allMovies[4] = (struct movie){"The Matrix", 1999, "The Wachowski Brothers", "Action, Sci-Fi", 8.7};

    do {
        printf("Welcome to the C Movie Rating System!\n\n");
        printf("1. View all movies\n");
        printf("2. Rate a movie\n");
        printf("3. Get top rated movies\n");
        printf("4. Get movies by genre\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // View all movies
                for (int i = 0; i < numMovies; i++) {
                    printMovie(allMovies[i]);
                }
                break;
            case 2:
                // Rate a movie
                printf("\nEnter the title of the movie you want to rate: ");
                char title[50];
                scanf("%s", title);
                for (int i = 0; i < numMovies; i++) {
                    if (strcmp(allMovies[i].title, title) == 0) {
                        printf("Enter your rating (out of 10): ");
                        float rating;
                        scanf("%f", &rating);
                        rateMovie(&allMovies[i], rating);
                        printf("\nThank you for rating the movie!\n\n");
                        break;
                    } else if (i == numMovies - 1) {
                        printf("\nMovie not found.\n\n");
                    }
                }
                break;
            case 3:
                // Get top rated movies
                getTopRatedMovies(allMovies, numMovies);
                break;
            case 4:
                // Get movies by genre
                printf("\nEnter a genre: ");
                char genre[20];
                scanf("%s", genre);
                getMoviesByGenre(allMovies, numMovies, genre);
                break;
            case 5:
                // Exit
                printf("\nThank you for using the C Movie Rating System! Goodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    } while (option != 5);

    return 0;
}

void printMovie(struct movie m) {
    printf("\nTitle: %s\nReleased year: %d\nDirector: %s\nGenre: %s\nRating: %.1f\n", m.title, m.releasedYear, m.director, m.genre, m.rating);
}

void rateMovie(struct movie *m, float rating) {
    m->rating = rating;
}

void getTopRatedMovies(struct movie m[], int size) {
    printf("\nTop rated movies:\n");
    qsort(m, size, sizeof(struct movie), compareByRating);
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, m[i].title);
    }
    printf("\n");
}

void getMoviesByGenre(struct movie m[], int size, char *genre) {
    printf("\nMovies in the %s genre:\n", genre);
    for (int i = 0; i < size; i++) {
        if (strstr(m[i].genre, genre) != NULL) {
            printf("%d. %s\n", i + 1, m[i].title);
        }
    }
    printf("\n");
}

int compareByRating(const void *a, const void *b) {
    struct movie *movieA = (struct movie *)a;
    struct movie *movieB = (struct movie *)b;
    if (movieA->rating > movieB->rating) {
        return -1;
    } else if (movieA->rating < movieB->rating) {
        return 1;
    } else {
        return 0;
    }
}