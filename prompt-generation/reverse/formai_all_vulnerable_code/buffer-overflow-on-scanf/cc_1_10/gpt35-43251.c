//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Movie Struct
typedef struct Movie {
    char title[50];
    int year;
    char genre[20];
    float rating;
} Movie;

// Function Prototypes
void printMenu();
void addMovie(Movie *movieList, int *numMovies);
void viewMovies(Movie *movieList, int numMovies);
void viewByGenre(Movie *movieList, int numMovies);
void viewByRating(Movie *movieList, int numMovies);
void quit();

int main() {
    int choice, numMovies = 0;
    Movie movieList[100];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movieList, &numMovies);
                break;
            case 2:
                viewMovies(movieList, numMovies);
                break;
            case 3:
                viewByGenre(movieList, numMovies);
                break;
            case 4:
                viewByRating(movieList, numMovies);
                break;
            case 5:
                quit();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function Definitions
void printMenu() {
    printf("\n=====Movie Rating System=====\n");
    printf("1. Add Movie\n");
    printf("2. View All Movies\n");
    printf("3. View Movies by Genre\n");
    printf("4. View Movies by Rating\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void addMovie(Movie *movieList, int *numMovies) {
    printf("\nEnter the movie details:\n");

    printf("Title: ");
    scanf("%s", movieList[*numMovies].title);

    printf("Year: ");
    scanf("%d", &movieList[*numMovies].year);

    printf("Genre: ");
    scanf("%s", movieList[*numMovies].genre);

    printf("Rating: ");
    scanf("%f", &movieList[*numMovies].rating);

    *numMovies += 1;
}

void viewMovies(Movie *movieList, int numMovies) {
    printf("\nAll Movies:\n");

    for (int i = 0; i < numMovies; i++) {
        printf("\nTitle: %s", movieList[i].title);
        printf("\nYear: %d", movieList[i].year);
        printf("\nGenre: %s", movieList[i].genre);
        printf("\nRating: %.1f\n", movieList[i].rating);
    }
}

void viewByGenre(Movie *movieList, int numMovies) { 
    char genre[20];
    int count = 0;

    printf("\nEnter the genre: ");
    scanf("%s", genre);

    printf("\nMovies in the %s genre:\n", genre);

    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movieList[i].genre, genre) == 0) {
            printf("\nTitle: %s", movieList[i].title);
            printf("\nYear: %d", movieList[i].year);
            printf("\nRating: %.1f\n", movieList[i].rating);
            count += 1;
        }
    }

    if (count == 0) {
        printf("\nNo movies found in the %s genre.\n", genre);
    }
}

void viewByRating(Movie *movieList, int numMovies) { 
    float minRating, maxRating;
    int count = 0;

    printf("\nEnter the minimum rating: ");
    scanf("%f", &minRating);
    printf("\nEnter the maximum rating: ");
    scanf("%f", &maxRating);

    printf("\nMovies with ratings between %.1f and %.1f:\n", minRating, maxRating);

    for (int i = 0; i < numMovies; i++) {
        if (movieList[i].rating >= minRating && movieList[i].rating <= maxRating) {
            printf("\nTitle: %s", movieList[i].title);
            printf("\nYear: %d", movieList[i].year);
            printf("\nGenre: %s", movieList[i].genre);
            printf("\nRating: %.1f\n", movieList[i].rating);
            count += 1;
        }
    }

    if (count == 0) {
        printf("\nNo movies found with ratings between %.1f and %.1f.\n", minRating, maxRating);
    }
}

void quit() {
    printf("\nThank you for using Movie Rating System. Goodbye!\n");
}