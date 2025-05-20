//FormAI DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[20];
    float rating;
};

void printMenu() {
    printf("C Movie Rating System\n");
    printf("======================\n");
    printf("1. Add a movie\n");
    printf("2. Edit a movie\n");
    printf("3. Remove a movie\n");
    printf("4. Display all movies\n");
    printf("5. Exit\n");
}

void addMovie(struct Movie movies[], int* numMovies) {
    if (*numMovies == 50) {
        printf("Maximum number of movies has been reached.\n");
    } else {
        struct Movie newMovie;
        printf("Enter the title of the movie: ");
        scanf("%s", newMovie.title);
        printf("Enter the genre of the movie: ");
        scanf("%s", newMovie.genre);
        printf("Enter the rating of the movie (out of 10): ");
        scanf("%f", &newMovie.rating);
        movies[*numMovies] = newMovie;
        (*numMovies)++;
        printf("Movie added successfully.\n");
    }
}

void editMovie(struct Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("There are no movies in the system.\n");
    } else {
        char title[50];
        printf("Enter the title of the movie that you want to edit: ");
        scanf("%s", title);
        int i;
        for (i = 0; i < numMovies; i++) {
            if (strcmp(movies[i].title, title) == 0) {
                printf("Enter the new rating of the movie (out of 10): ");
                scanf("%f", &movies[i].rating);
                printf("Movie edited successfully.\n");
                return;
            }
        }
        printf("Movie not found.\n");
    }
}

void removeMovie(struct Movie movies[], int* numMovies) {
    if (*numMovies == 0) {
        printf("There are no movies in the system.\n");
    } else {
        char title[50];
        printf("Enter the title of the movie that you want to remove: ");
        scanf("%s", title);
        int i, j;
        for (i = 0; i < *numMovies; i++) {
            if (strcmp(movies[i].title, title) == 0) {
                for (j = i; j < *numMovies - 1; j++) {
                    movies[j] = movies[j+1];
                }
                (*numMovies)--;
                printf("Movie removed successfully.\n");
                return;
            }
        }
        printf("Movie not found.\n");
    }
}

void displayMovies(struct Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("There are no movies in the system.\n");
    } else {
        printf("%-50s %-20s %-10s\n", "Title", "Genre", "Rating");
        int i;
        for (i = 0; i < numMovies; i++) {
            printf("%-50s %-20s %-10.2f\n", movies[i].title, movies[i].genre, movies[i].rating);
        }
    }
}

int main() {
    struct Movie movies[50];
    int numMovies = 0;

    int menuOption = 0;
    while (menuOption != 5) {
        printMenu();
        printf("Enter an option: ");
        scanf("%d", &menuOption);
        switch (menuOption) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                editMovie(movies, numMovies);
                break;
            case 3:
                removeMovie(movies, &numMovies);
                break;
            case 4:
                displayMovies(movies, numMovies);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}