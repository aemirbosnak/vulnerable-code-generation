//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char title[NAME_LENGTH];
    char genre[NAME_LENGTH];
    float rating;
    int year;
} Movie;

void displayMenu();
void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void searchMovie(Movie *movies, int count);
void sortMovies(Movie *movies, int count);
void saveToFile(Movie *movies, int count);
void loadFromFile(Movie *movies, int *count);

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    loadFromFile(movies, &count);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                sortMovies(movies, count);
                break;
            case 5:
                saveToFile(movies, count);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Sort Movies by Rating\n");
    printf("5. Save Movies to File\n");
    printf("6. Exit\n");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear the input buffer
    fgets(newMovie.title, NAME_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = '\0'; // Remove newline character

    printf("Enter movie genre: ");
    fgets(newMovie.genre, NAME_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = '\0'; // Remove newline character

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    printf("Enter movie release year: ");
    scanf("%d", &newMovie.year);

    movies[*count] = newMovie;
    (*count)++;
    
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\n--- Movies List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Rating: %.1f, Year: %d\n", 
                movies[i].title, movies[i].genre, movies[i].rating, movies[i].year);
    }
}

void searchMovie(Movie *movies, int count) {
    char searchTitle[NAME_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Clear the input buffer
    fgets(searchTitle, NAME_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline character

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            found = 1;
            printf("Found Movie! Title: %s, Genre: %s, Rating: %.1f, Year: %d\n", 
                    movies[i].title, movies[i].genre, movies[i].rating, movies[i].year);
            break;
        }
    }

    if (!found) {
        printf("Movie not found!\n");
    }
}

void sortMovies(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
    printf("Movies sorted by rating successfully!\n");
}

void saveToFile(Movie *movies, int count) {
    FILE *file = fopen("movies.txt", "w");
    if (file == NULL) {
        printf("Error saving to file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%.1f\n%d\n", 
                movies[i].title, movies[i].genre, movies[i].rating, movies[i].year);
    }

    fclose(file);
    printf("Movies saved to file successfully!\n");
}

void loadFromFile(Movie *movies, int *count) {
    FILE *file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("No saved movies found. Starting fresh.\n");
        return;
    }

    while (!feof(file) && *count < MAX_MOVIES) {
        fgets(movies[*count].title, NAME_LENGTH, file);
        movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0'; // Remove newline character

        fgets(movies[*count].genre, NAME_LENGTH, file);
        movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0'; // Remove newline character

        fscanf(file, "%f\n", &movies[*count].rating);
        fscanf(file, "%d\n", &movies[*count].year);
        
        (*count)++;
    }

    fclose(file);
    printf("Movies loaded from file successfully!\n");
}