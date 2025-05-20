//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

void initializeMovie(Movie *movie, const char *title, const char *director, int year, float rating) {
    snprintf(movie->title, sizeof(movie->title), "%s", title);
    snprintf(movie->director, sizeof(movie->director), "%s", director);
    movie->year = year;
    movie->rating = rating;
}

void displayMovie(const Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Year: %d\n", movie->year);
    printf("Rating: %.1f/5.0\n", movie->rating);
}

float calculateAverageRating(Movie *movies, int count) {
    if (count == 0) return 0.0;
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    return total / count;
}

void sortMoviesByRating(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void findTopRatedMovies(Movie *movies, int count, int n) {
    if (n > count) n = count;
    printf("\nTop %d Rated Movies:\n", n);
    sortMoviesByRating(movies, count);
    for (int i = 0; i < n; i++) {
        displayMovie(&movies[i]);
        printf("---------------------------\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");
    printf("Please select an option:\n");
    printf("1. Add a Movie\n");
    printf("2. Display all Movies\n");
    printf("3. Calculate Average Rating\n");
    printf("4. Find Top Rated Movies\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                if (movieCount >= MAX_MOVIES) {
                    printf("Cannot add more movies. Maximum limit reached!\n");
                    break;
                }
                {
                    char title[100], director[100];
                    int year;
                    float rating;
                    printf("Enter movie title: ");
                    fgets(title, sizeof(title), stdin);
                    title[strcspn(title, "\n")] = 0; // Remove newline
                    printf("Enter director name: ");
                    fgets(director, sizeof(director), stdin);
                    director[strcspn(director, "\n")] = 0; // Remove newline
                    printf("Enter release year: ");
                    scanf("%d", &year);
                    printf("Enter rating (0.0 - 5.0): ");
                    scanf("%f", &rating);
                    initializeMovie(&movies[movieCount], title, director, year, rating);
                    movieCount++;
                    printf("Movie added successfully!\n");
                }
                break;
            case 2:
                if (movieCount == 0) {
                    printf("No movies to display.\n");
                } else {
                    printf("\nList of Movies:\n");
                    for (int i = 0; i < movieCount; i++) {
                        displayMovie(&movies[i]);
                        printf("---------------------------\n");
                    }
                }
                break;
            case 3:
                {
                    float average = calculateAverageRating(movies, movieCount);
                    printf("Average Movie Rating: %.1f/5.0\n", average);
                }
                break;
            case 4:
                {
                    int n;
                    printf("Enter how many top rated movies you want to see: ");
                    scanf("%d", &n);
                    findTopRatedMovies(movies, movieCount, n);
                }
                break;
            case 5:
                printf("Exiting the Movie Rating System. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}