//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int year;
    float rating;
    char genre[TITLE_LENGTH];
} Movie;

void displayMenu();
void addMovie(Movie *movies, int *count);
void viewMovies(Movie *movies, int count);
void averageRating(Movie *movies, int count);
void findMoviesByGenre(Movie *movies, int count);
void sortMovies(Movie *movies, int count);
void clearBuffer();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                averageRating(movies, movieCount);
                break;
            case 4:
                findMoviesByGenre(movies, movieCount);
                break;
            case 5:
                sortMovies(movies, movieCount);
                break;
            case 6:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Average Rating of Movies\n");
    printf("4. Find Movies by Genre\n");
    printf("5. Sort Movies by Rating\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("Enter movie title: ");
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0;  // remove newline character
    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);
    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    clearBuffer();
    printf("Enter movie genre: ");
    fgets(movies[*count].genre, TITLE_LENGTH, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0;  // remove newline character
    
    (*count)++;
    printf("Movie added successfully! You now have %d movies.\n", *count);
}

void viewMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Year: %d, Rating: %.1f, Genre: %s\n", 
                movies[i].title, movies[i].year, movies[i].rating, movies[i].genre);
    }
}

void averageRating(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available for rating.\n");
        return;
    }

    float totalRating = 0;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }
    printf("Average Rating of Movies: %.2f\n", totalRating / count);
}

void findMoviesByGenre(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available for selection.\n");
        return;
    }

    char genre[TITLE_LENGTH];
    printf("Enter genre to search: ");
    fgets(genre, TITLE_LENGTH, stdin);
    genre[strcspn(genre, "\n")] = 0;  // remove newline character

    printf("\n--- Movies in Genre: %s ---\n", genre);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            printf("Title: %s, Year: %d, Rating: %.1f\n", 
                    movies[i].title, movies[i].year, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

void sortMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
    printf("Movies sorted by rating in descending order.\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}