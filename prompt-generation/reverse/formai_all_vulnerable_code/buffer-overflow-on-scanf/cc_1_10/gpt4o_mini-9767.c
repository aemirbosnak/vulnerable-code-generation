//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 256

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float rating;
    int year;
} Movie;

void printMovie(const Movie* movie) {
    printf("Title: %s\n", movie->name);
    printf("Year: %d\n", movie->year);
    printf("Rating: %.1f\n", movie->rating);
    printf("Description: %s\n", movie->description);
    printf("-------------------------------------\n");
}

void addMovie(Movie* movies, int* count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // to remove newline from previous input
    fgets(newMovie.name, NAME_LENGTH, stdin);
    newMovie.name[strcspn(newMovie.name, "\n")] = '\0'; // remove trailing newline
    
    printf("Enter movie year: ");
    scanf("%d", &newMovie.year);
    
    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &newMovie.rating);
    
    getchar(); // to remove newline from previous input
    printf("Enter movie description: ");
    fgets(newMovie.description, DESCRIPTION_LENGTH, stdin);
    newMovie.description[strcspn(newMovie.description, "\n")] = '\0'; // remove trailing newline

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void viewMovies(const Movie* movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printMovie(&movies[i]);
    }
}

void deleteMovie(Movie* movies, int* count) {
    if (*count == 0) {
        printf("No movies to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the movie to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid index. Cannot delete movie.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        movies[i] = movies[i + 1];
    }

    (*count)--;
    printf("Movie deleted successfully!\n");
}

void searchMovie(const Movie* movies, int count) {
    if (count == 0) {
        printf("No movies to search.\n");
        return;
    }

    char searchTerm[NAME_LENGTH];
    printf("Enter movie title to search: ");
    getchar(); // to remove newline from previous input
    fgets(searchTerm, NAME_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // remove trailing newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].name, searchTerm)) {
            printMovie(&movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found with the title \"%s\".\n", searchTerm);
    }
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Delete Movie\n");
    printf("4. Search Movie\n");
    printf("5. Exit\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                deleteMovie(movies, &count);
                break;
            case 4:
                searchMovie(movies, count);
                break;
            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}