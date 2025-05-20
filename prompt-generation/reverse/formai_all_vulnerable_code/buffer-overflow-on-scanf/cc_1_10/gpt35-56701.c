//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// define a struct for movies
typedef struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
} movie;

// declare functions
void add_movie(movie *m);
void display_movies(movie *m, int size);
void search_movie(movie *m, int size);
void rate_movie(movie *m, int size);

int main() {
    int choice, size = 0;
    movie *m = NULL;

    do {
        // display menu
        printf("\nMovie Rating System\n");
        printf("====================\n");
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. Search movie\n");
        printf("4. Rate movie\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(m);
                size++;
                break;
            case 2:
                display_movies(m, size);
                break;
            case 3:
                search_movie(m, size);
                break;
            case 4:
                rate_movie(m, size);
                break;
            case 5:
                printf("\nExiting program... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while(choice != 5);

    // free the memory allocated for the movies
    if (m) {
        free(m);
    }

    return 0;
}

// function to add a movie
void add_movie(movie *m) {
    if (m == NULL) {
        // allocate memory for the first movie
        m = (movie*) malloc(sizeof(movie));
    } else {
        // increase the allocated memory for the movies
        m = (movie*) realloc(m, sizeof(movie) * (sizeof(m) + 1));
    }

    printf("\nEnter details of the movie:\n");
    printf("Title: ");
    scanf("%s", m[sizeof(m) - 1].title);
    printf("Director: ");
    scanf("%s", m[sizeof(m) - 1].director);
    printf("Year: ");
    scanf("%d", &m[sizeof(m) - 1].year);
    printf("Rating: ");
    scanf("%f", &m[sizeof(m) - 1].rating);
}

// function to display all movies
void display_movies(movie *m, int size) {
    if (size == 0) {
        printf("\nNo movies added yet.\n");
    } else {
        printf("\nAll movies:\n");
        printf("Title\tDirector\tYear\tRating\n");
        for (int i = 0; i < size; i++) {
            printf("%s\t%s\t\t%d\t%.1f\n", m[i].title, m[i].director, m[i].year, m[i].rating);
        }
    }
}

// function to search for a movie
void search_movie(movie *m, int size) {
    if (size == 0) {
        printf("\nNo movies added yet.\n");
    } else {
        char title[50];
        printf("\nEnter the title of the movie to search: ");
        scanf("%s", title);

        for (int i = 0; i < size; i++) {
            if (strcmp(m[i].title, title) == 0) {
                printf("\nMovie found:\n");
                printf("Title\tDirector\tYear\tRating\n");
                printf("%s\t%s\t\t%d\t%.1f\n", m[i].title, m[i].director, m[i].year, m[i].rating);
                return;
            }
        }

        printf("\nMovie not found, please try again.\n");
    }
}

// function to rate a movie
void rate_movie(movie *m, int size) {
    if (size == 0) {
        printf("\nNo movies added yet.\n");
    } else {
        char title[50];
        printf("\nEnter the title of the movie to rate: ");
        scanf("%s", title);

        for (int i = 0; i < size; i++) {
            if (strcmp(m[i].title, title) == 0) {
                printf("\nCurrent rating of the movie: %.1f\n", m[i].rating);
                printf("Enter new rating (0.0 to 10.0): ");
                scanf("%f", &m[i].rating);
                printf("\nRating updated successfully.\n");
                return;
            }
        }

        printf("\nMovie not found, please try again.\n");
    }
}