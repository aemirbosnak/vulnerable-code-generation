//FormAI DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to store movie data */
typedef struct {
    char title[50];
    char director[50];
    int year;
    int rating;
} Movie;

/* Function prototypes */
void add_movie(Movie *movie);
void print_movie_list(Movie *movie_list, int size);
void search_movie_by_title(Movie *movie_list, int size);
void search_movie_by_director(Movie *movie_list, int size);
void search_movie_by_year(Movie *movie_list, int size);
void rate_movie(Movie *movie_list, int size);

/* Main function */
int main() {
    int choice = 0;
    int size = 0;
    Movie *movies = NULL;

    while (1) {
        printf("\n1. Add movie\n");
        printf("2. Print movie list\n");
        printf("3. Search movie by title\n");
        printf("4. Search movie by director\n");
        printf("5. Search movie by year\n");
        printf("6. Rate movie\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(&movies[size]);
                ++size;
                break;
            case 2:
                if (size == 0) {
                    printf("No movies to display!\n");
                } else {
                    print_movie_list(movies, size);
                }
                break;
            case 3:
                if (size == 0) {
                    printf("No movies to search!\n");
                } else {
                    search_movie_by_title(movies, size);
                }
                break;
            case 4:
                if (size == 0) {
                    printf("No movies to search!\n");
                } else {
                    search_movie_by_director(movies, size);
                }
                break;
            case 5:
                if (size == 0) {
                    printf("No movies to search!\n");
                } else {
                    search_movie_by_year(movies, size);
                }
                break;
            case 6:
                if (size == 0) {
                    printf("No movies to rate!\n");
                } else {
                    rate_movie(movies, size);
                }
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
}

/* Function to add a movie to the list */
void add_movie(Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter director name: ");
    scanf("%s", movie->director);
    printf("Enter release year: ");
    scanf("%d", &movie->year);
    printf("Enter movie rating out of 10: ");
    scanf("%d", &movie->rating);
}

/* Function to print the movie list */
void print_movie_list(Movie *movie_list, int size) {
    printf("\nMovie List:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s, %s (%d) - %d/10\n", i + 1, movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
    }
}

/* Function to search for a movie by title */
void search_movie_by_title(Movie *movie_list, int size) {
    char title[50];
    printf("Enter movie title: ");
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(title, movie_list[i].title) == 0) {
            printf("Found movie: %s, %s (%d) - %d/10\n", movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
            ++found;
        }
    }

    if (found == 0) {
        printf("Movie not found!\n");
    }
}

/* Function to search for a movie by director */
void search_movie_by_director(Movie *movie_list, int size) {
    char director[50];
    printf("Enter director name: ");
    scanf("%s", director);

    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(director, movie_list[i].director) == 0) {
            printf("Found movie: %s, %s (%d) - %d/10\n", movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
            ++found;
        }
    }

    if (found == 0) {
        printf("Movie not found!\n");
    }
}

/* Function to search for a movie by year */
void search_movie_by_year(Movie *movie_list, int size) {
    int year;
    printf("Enter release year: ");
    scanf("%d", &year);

    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (year == movie_list[i].year) {
            printf("Found movie: %s, %s (%d) - %d/10\n", movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
            ++found;
        }
    }

    if (found == 0) {
        printf("Movie not found!\n");
    }
}

/* Function to rate a movie in the list */
void rate_movie(Movie *movie_list, int size) {
    int choice = 0;
    printf("Select movie to rate:\n");
    print_movie_list(movie_list, size);
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > size) {
        printf("Invalid choice, please try again!\n");
        return;
    }

    printf("Enter new rating out of 10: ");
    scanf("%d", &movie_list[choice - 1].rating);

    printf("Rating updated!\n");
}