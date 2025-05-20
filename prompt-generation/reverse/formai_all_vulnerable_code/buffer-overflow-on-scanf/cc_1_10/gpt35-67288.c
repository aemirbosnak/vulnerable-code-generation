//FormAI DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_STRING_LENGTH 50
#define MIN_RATING 0
#define MAX_RATING 10

typedef struct movie {
    char title[MAX_STRING_LENGTH];
    char director[MAX_STRING_LENGTH];
    int year;
    char genre[MAX_STRING_LENGTH];
    char rating[MAX_STRING_LENGTH];
} Movie;

int addMovie(Movie movies[], int count);
void listMovies(Movie movies[], int count);
void searchMovies(Movie movies[], int count);
void deleteMovie(Movie movies[], int count);
int isRatingValid(char rating[]);

int main(void) {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("Welcome to the C Movie Rating System!\n");
        printf("1. Add a movie\n");
        printf("2. List movies\n");
        printf("3. Search for a movie\n");
        printf("4. Delete a movie\n");
        printf("5. Quit the program\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addMovie(movies, count);
                break;
            case 2:
                listMovies(movies, count);
                break;
            case 3:
                searchMovies(movies, count);
                break;
            case 4:
                deleteMovie(movies, count);
                break;
            case 5:
                printf("Thank you for using the C Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

int addMovie(Movie movies[], int count) {
    if (count == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return count;
    }

    printf("Please enter the title of the movie: ");
    scanf(" %[^\n]", movies[count].title);
    printf("Please enter the name of the director: ");
    scanf(" %[^\n]", movies[count].director);
    printf("Please enter the year of release: ");
    scanf("%d", &movies[count].year);
    printf("Please enter the genre of the movie: ");
    scanf(" %[^\n]", movies[count].genre);
    printf("Please enter the rating of the movie (0-10): ");
    scanf(" %[^\n]", movies[count].rating);

    if (isRatingValid(movies[count].rating)) {
        printf("Movie added successfully!\n");
        return count + 1;
    } else {
        printf("Invalid rating. Movie not added.\n");
        return count;
    }
}

void listMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies found.\n");
    } else {
        printf("Title                 Director              Year  Genre                 Rating\n");
        printf("--------------------------------------------------------------------------------\n");

        for (int i = 0; i < count; i++) {
            printf("%-20s %-20s %-5d %-20s %-10s\n", movies[i].title, movies[i].director,
                movies[i].year, movies[i].genre, movies[i].rating);
        }
    }
}

void searchMovies(Movie movies[], int count) {
    char searchGenre[MAX_STRING_LENGTH];
    int found = 0;

    printf("Please enter the genre to search for: ");
    scanf(" %[^\n]", searchGenre);

    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].genre, searchGenre) != NULL) {
            printf("%-20s %-20s %-5d %-20s %-10s\n", movies[i].title, movies[i].director,
                movies[i].year, movies[i].genre, movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in the %s genre.\n", searchGenre);
    }
}

void deleteMovie(Movie movies[], int count) {
    char title[MAX_STRING_LENGTH];
    int found = 0;
    int index;

    printf("Please enter the title of the movie to delete: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        for (int i = index; i < count - 1; i++) {
            movies[i] = movies[i+1];
        }
        printf("Movie deleted successfully!\n");
        count--;
    } else {
        printf("Movie not found.\n");
    }
}

int isRatingValid(char rating[]) {
    int len = strlen(rating);

    if (len == 1) {
        return (rating[0] >= '0' && rating[0] <= '9');
    } else if (len == 2) {
        return (rating[0] >= '0' && rating[0] <= '9' &&
                rating[1] >= '0' && rating[1] <= '9');
    } else {
        return 0;
    }
}