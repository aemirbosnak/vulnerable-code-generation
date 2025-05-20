//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie information
typedef struct {
    char title[100];
    char genre[50];
    float rating;
    int year;
} Movie;

// Function prototypes
void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void rateMovie(Movie *movies, int count);
void sortMovies(Movie *movies, int count);
void saveMoviesToFile(Movie *movies, int count);
void loadMoviesFromFile(Movie *movies, int *count);
void displayMenu();

int main() {
    Movie movies[100];
    int count = 0;
    loadMoviesFromFile(movies, &count);

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                sortMovies(movies, count);
                break;
            case 5:
                saveMoviesToFile(movies, count);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n---- Movie Rating System ----\n");
    printf("1. Add a Movie\n");
    printf("2. Display Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Sort Movies by Rating\n");
    printf("5. Save Movies to File\n");
    printf("6. Exit\n");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= 100) {
        printf("Movie list is full!\n");
        return;
    }
    Movie newMovie;
    printf("Enter title: ");
    getchar();  // Clear newline from buffer
    fgets(newMovie.title, 100, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter genre: ");
    fgets(newMovie.genre, 50, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline

    printf("Enter year of release: ");
    scanf("%d", &newMovie.year);
    
    printf("Enter rating (0.0 - 10.0): ");
    scanf("%f", &newMovie.rating);

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\n--- Movies List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n\n", movies[i].rating);
    }
}

void rateMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available to rate.\n");
        return;
    }
    char title[100];
    printf("Enter movie title to rate: ");
    getchar();  // Clear newline from buffer
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter new rating (0.0 - 10.0): ");
            scanf("%f", &movies[i].rating);
            printf("Rating updated successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void sortMovies(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating.\n");
}

void saveMoviesToFile(Movie *movies, int count) {
    FILE *file = fopen("movies.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%d;%.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
    fclose(file);
    printf("Movies saved to file successfully.\n");
}

void loadMoviesFromFile(Movie *movies, int *count) {
    FILE *file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("No saved movies found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%[^;];%[^;];%d;%f\n", movies[*count].title, movies[*count].genre, 
           &movies[*count].year, &movies[*count].rating) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Movies loaded from file successfully.\n");
}