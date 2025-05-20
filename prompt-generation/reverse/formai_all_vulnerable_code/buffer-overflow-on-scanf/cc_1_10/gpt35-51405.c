//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie; // Define Movie structure

void addMovie(Movie movies[], int *count) {
    printf("\nEnter movie title: ");
    scanf("%s", movies[*count].title);
    printf("Enter director name: ");
    scanf("%s", movies[*count].director);
    printf("Enter year of release: ");
    scanf("%d", &movies[*count].year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++; // Increment movie count
}

void listMovies(Movie movies[], int count) {
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f/10\n\n", movies[i].rating);
    }
}

void searchMovie(Movie movies[], int count) {
    char searchTitle[50];
    printf("\nEnter movie title to search: ");
    scanf("%s", searchTitle);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f/10\n\n", movies[i].rating);
            return;
        }
    }
    printf("\nMovie not found.\n");
}

int main() {
    Movie movies[100];
    int count = 0;
    int choice;

    while (1) { // Loop until user exits program
        printf("\nC Movie Rating System\n");
        printf("----------------------\n");
        printf("1. Add a movie\n");
        printf("2. List all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Exit program\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                listMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0; // End program
}