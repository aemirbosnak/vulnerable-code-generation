//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char director[50];
    char cast[100];
    char rating[5];
} movie;

void addMovie(movie* m) {
    printf("Enter movie title: ");
    getchar();
    fgets(m->title, 100, stdin);
    printf("Enter movie director: ");
    fgets(m->director, 50, stdin);
    printf("Enter movie cast: ");
    fgets(m->cast, 100, stdin);
    printf("Enter movie rating (out of 10): ");
    fgets(m->rating, 5, stdin);
}

void viewMovie(movie* m) {
    printf("Title: %s", m->title);
    printf("Director: %s", m->director);
    printf("Cast: %s", m->cast);
    printf("Rating: %s/10\n", m->rating);
}

int main() {
    int choice, numMovies = 0, i;
    char searchTitle[100];
    movie* movies = (movie*) malloc(sizeof(movie));
    do {
        printf("\n=========");
        printf("\nMAIN MENU");
        printf("\n=========");
        printf("\n1. Add a movie");
        printf("\n2. View all movies");
        printf("\n3. Search for a movie");
        printf("\n4. Exit");
        printf("\nEnter your choice [1-4]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numMovies++;
                movies = (movie*) realloc(movies, numMovies * sizeof(movie));
                addMovie(&movies[numMovies-1]);
                break;
            case 2:
                printf("\n============= MOVIE LIST =============\n");
                for (i = 0; i < numMovies; i++) {
                    printf("\nMovie #%d:\n", i+1);
                    viewMovie(&movies[i]);
                }
                break;
            case 3:
                printf("\nEnter the title of the movie you want to search for: ");
                getchar();
                fgets(searchTitle, 100, stdin);
                for (i = 0; i < numMovies; i++) {
                    if (strcmp(searchTitle, movies[i].title) == 0) {
                        printf("\nMovie found!\n");
                        viewMovie(&movies[i]);
                        break;
                    }
                }
                if (i == numMovies) {
                    printf("\nMovie not found.\n");
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }    
    } while (choice != 4);
    free(movies);
    return 0;
}