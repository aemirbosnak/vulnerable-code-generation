//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie information
struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// Function to search for a movie by title
void searchMovie(struct movie *movies, int n) {
    char searchTitle[50];
    printf("Enter the movie title: ");
    scanf("%s", searchTitle);
    int found = 0;
    for(int i=0; i<n; i++) {
        if(strcmp(movies[i].title, searchTitle)==0) {
            printf("\nMovie Title: %s", movies[i].title);
            printf("\nDirector: %s", movies[i].director);
            printf("\nYear: %d", movies[i].year);
            printf("\nRating: %.1f\n", movies[i].rating);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Movie not found!\n");
    }
}

// Function to display all movies in the database
void displayAllMovies(struct movie *movies, int n) {
    printf("All Movies:\n");
    for(int i=0; i<n; i++) {
        printf("\nMovie Title: %s", movies[i].title);
        printf("\nDirector: %s", movies[i].director);
        printf("\nYear: %d", movies[i].year);
        printf("\nRating: %.1f\n", movies[i].rating);
    }
}

int main() {
    int choice, n, i;
    printf("Enter the number of movies: ");
    scanf("%d", &n);
    struct movie *movies = (struct movie*) malloc(n * sizeof(struct movie));
    for(i=0; i<n; i++) {
        printf("\nEnter movie information:\n");
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating: ");
        scanf("%f", &movies[i].rating);
    }
    while(1) {
        printf("\n\n1. Search for a movie by title\n2. Display all movies\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                searchMovie(movies, n);
                break;
            case 2:
                displayAllMovies(movies, n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}