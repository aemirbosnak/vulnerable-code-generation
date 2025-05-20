//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    int rating; // 1 to 10
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Oh no! The movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    
    printf("Enter movie title: ");
    getchar(); // to consume the newline
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    strtok(newMovie.title, "\n"); // Remove newline character from the title
    
    printf("Enter movie director: ");
    fgets(newMovie.director, MAX_DIRECTOR_LENGTH, stdin);
    strtok(newMovie.director, "\n"); // Remove newline character from the director
    
    printf("Enter your rating (1-10): ");
    scanf("%d", &newMovie.rating);
    
    if (newMovie.rating < 1 || newMovie.rating > 10) {
        printf("Rating must be between 1 and 10. Movie not added!\n");
        return;
    }

    movieList[movieCount++] = newMovie;
    printf("Movie added: %s by %s with a rating of %d!\n", newMovie.title, newMovie.director, newMovie.rating);
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies available! Did you forget to add one?\n");
        return;
    }

    printf("Here's the list of movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s by %s - Rating: %d\n", i+1, movieList[i].title, movieList[i].director, movieList[i].rating);
    }
}

void deleteMovie() {
    int index;
    displayMovies();
    printf("Enter the movie number you want to delete (1-%d): ", movieCount);
    scanf("%d", &index);
    
    if (index < 1 || index > movieCount) {
        printf("Invalid movie number! Could it be a ghost? 😱\n");
        return;
    }

    for (int i = index - 1; i < movieCount - 1; i++) {
        movieList[i] = movieList[i + 1];
    }
    movieCount--;
    printf("Movie deleted! Now there are %d movies left.\n", movieCount);
}

void saveMoviesToFile() {
    FILE *file = fopen("movies.txt", "w");
    if (!file) {
        printf("Oh no! Could not open file for writing! 😱\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(file, "%s\n%s\n%d\n", movieList[i].title, movieList[i].director, movieList[i].rating);
    }
    
    fclose(file);
    printf("Movies saved successfully to 'movies.txt'!\n");
}

void loadMoviesFromFile() {
    FILE *file = fopen("movies.txt", "r");
    if (!file) {
        printf("Oh no! No saved movies found! 😢\n");
        return;
    }
    
    movieCount = 0;
    while (fscanf(file, "%[^\n]\n%[^\n]\n%d\n", movieList[movieCount].title, movieList[movieCount].director, &movieList[movieCount].rating) != EOF) {
        movieCount++;
    }
    
    fclose(file);
    printf("Movies loaded from 'movies.txt'. Now there are %d movies!\n", movieCount);
}

void displayMenu() {
    printf("\n========== Movie Rating System ==========\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Delete Movie\n");
    printf("4. Save Movies to File\n");
    printf("5. Load Movies from File\n");
    printf("6. Exit\n");
    printf("=========================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                deleteMovie();
                break;
            case 4:
                saveMoviesToFile();
                break;
            case 5:
                loadMoviesFromFile();
                break;
            case 6:
                printf("Exiting... Goodbye! 📽️\n");
                exit(0);
            default:
                printf("Invalid choice! Are you trying to confuse me? 😳\n");
                break;
        }
    }
    return 0;
}