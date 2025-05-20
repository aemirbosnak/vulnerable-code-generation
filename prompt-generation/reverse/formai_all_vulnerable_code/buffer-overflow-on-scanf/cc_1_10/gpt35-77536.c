//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_NAME_LENGTH 50

struct movie {
    char name[MAX_NAME_LENGTH];
    int rating;
};

typedef struct movie Movie;

void print_menu() {
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. View All Movies\n");
    printf("4. Exit\n");
}

void add_movie(Movie* movies, int* num_movies) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the movie: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n"); // remove newline character

    if (*num_movies == MAX_MOVIES) {
        printf("Sorry, you have reached the maximum number of movies.\n");
        return;
    }

    // check if movie already exists
    for (int i = 0; i < *num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("Sorry, this movie already exists.\n");
            return;
        }
    }

    // add new movie
    strcpy(movies[*num_movies].name, name);
    movies[*num_movies].rating = 0;
    (*num_movies)++;
    printf("Movie added!\n");
}

void rate_movie(Movie* movies, int num_movies) {
    char name[MAX_NAME_LENGTH];
    int rating;
    printf("Enter the name of the movie: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n"); // remove newline character

    // find movie in array
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            found = 1;
            printf("Enter the rating (0-10): ");
            scanf("%d", &rating);
            getchar(); // remove newline character from stdin buffer
            while (rating < 0 || rating > 10) {
                printf("Invalid rating. Please enter a rating between 0 and 10: ");
                scanf("%d", &rating);
                getchar(); // remove newline character from stdin buffer
            }
            movies[i].rating = rating;
            printf("Rating added!\n");
        }
    }

    if (!found) {
        printf("Sorry, this movie does not exist.\n");
    }
}

void view_all_movies(Movie* movies, int num_movies) {
    printf("Name\t\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t\t%d\n", movies[i].name, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // remove newline character from stdin buffer

        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                view_all_movies(movies, num_movies);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}