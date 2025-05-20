//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void addMovie(Movie *movies, int *count);
void listMovies(const Movie *movies, int count);
void searchMovie(const Movie *movies, int count);
void rateMovie(Movie *movies, int count);
void saveToFile(const Movie *movies, int count);
void loadFromFile(Movie *movies, int *count);
void displayMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    loadFromFile(movies, &movieCount);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                listMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 4:
                rateMovie(movies, movieCount);
                break;
            case 5:
                saveToFile(movies, movieCount);
                printf("Movie list saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add a new movie\n");
    printf("2. List all movies\n");
    printf("3. Search for a movie\n");
    printf("4. Rate a movie\n");
    printf("5. Save movie list to file\n");
    printf("6. Exit\n");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // To clear the newline from the buffer
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, MAX_GENRE_LENGTH, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0; // Remove newline

    strcpy(movies[*count].rating, "N/A"); // Default rating is "N/A"
    (*count)++;
    printf("Movie added successfully!\n");
}

void listMovies(const Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Rating: %s\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void searchMovie(const Movie *movies, int count) {
    char titleToSearch[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // To clear the newline
    fgets(titleToSearch, MAX_TITLE_LENGTH, stdin);
    titleToSearch[strcspn(titleToSearch, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, titleToSearch) == 0) {
            printf("Found movie: Title: %s, Genre: %s, Rating: %s\n", movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void rateMovie(Movie *movies, int count) {
    char titleToRate[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to rate: ");
    getchar(); // To clear the newline
    fgets(titleToRate, MAX_TITLE_LENGTH, stdin);
    titleToRate[strcspn(titleToRate, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, titleToRate) == 0) {
            printf("Enter your rating (e.g., 8.5): ");
            fgets(movies[i].rating, MAX_RATING_LENGTH, stdin);
            movies[i].rating[strcspn(movies[i].rating, "\n")] = 0; // Remove newline
            printf("Rating updated successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void saveToFile(const Movie *movies, int count) {
    FILE *file = fopen("movies.dat", "w");
    if (file == NULL) {
        printf("Error saving to file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s\n", movies[i].title, movies[i].genre, movies[i].rating);
    }

    fclose(file);
}

void loadFromFile(Movie *movies, int *count) {
    FILE *file = fopen("movies.dat", "r");
    if (file == NULL) {
        return; // No file to load, it's fine to start fresh
    }

    while (fscanf(file, "%[^;];%[^;];%[^;\n]\n", movies[*count].title, movies[*count].genre, movies[*count].rating) == 3) {
        (*count)++;
    }
    fclose(file);
}