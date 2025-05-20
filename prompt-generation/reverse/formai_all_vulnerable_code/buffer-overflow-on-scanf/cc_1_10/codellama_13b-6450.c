//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
// Movie Rating System
#include <stdio.h>

// Structure to store movie details
struct Movie {
    char name[20];
    int rating;
};

// Function to add a new movie
void addMovie(struct Movie *movies, int *numMovies) {
    printf("Enter the name of the movie: ");
    scanf("%s", movies[*numMovies].name);
    printf("Enter the rating of the movie: ");
    scanf("%d", &movies[*numMovies].rating);
    *numMovies += 1;
}

// Function to display all movies
void displayMovies(struct Movie *movies, int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("%s - %d\n", movies[i].name, movies[i].rating);
    }
}

// Function to search for a movie
void searchMovie(struct Movie *movies, int numMovies) {
    char name[20];
    printf("Enter the name of the movie to search: ");
    scanf("%s", name);
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("%s - %d\n", movies[i].name, movies[i].rating);
            return;
        }
    }
    printf("Movie not found\n");
}

// Function to delete a movie
void deleteMovie(struct Movie *movies, int *numMovies) {
    char name[20];
    printf("Enter the name of the movie to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            for (int j = i; j < *numMovies - 1; j++) {
                movies[j] = movies[j + 1];
            }
            *numMovies -= 1;
            return;
        }
    }
    printf("Movie not found\n");
}

int main() {
    struct Movie movies[100];
    int numMovies = 0;
    char choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("a. Add a new movie\n");
        printf("b. Display all movies\n");
        printf("c. Search for a movie\n");
        printf("d. Delete a movie\n");
        printf("e. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                addMovie(movies, &numMovies);
                break;
            case 'b':
                displayMovies(movies, numMovies);
                break;
            case 'c':
                searchMovie(movies, numMovies);
                break;
            case 'd':
                deleteMovie(movies, &numMovies);
                break;
            case 'e':
                return 0;
        }
    }
    return 0;
}