//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    int rating;
    char genre[20];
} Movie;

void print_menu() {
    printf("\n-----------------------------------\n");
    printf("| Welcome to the C Movie Ratings! |\n");
    printf("-----------------------------------\n");
    printf("| 1. Add Movie\n");
    printf("| 2. Display Movies\n");
    printf("| 3. Search Movie\n");
    printf("| 4. Update Movie Rating\n");
    printf("| 5. Delete Movie\n");
    printf("| 6. Exit\n");
    printf("-----------------------------------\n");
}

void add_movie(Movie *movies, int *num_movies) {
    if (*num_movies == 10) {
        printf("Maximum movies limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf("%s", movies[*num_movies].title);

    printf("Enter movie genre: ");
    scanf("%s", movies[*num_movies].genre);

    printf("Enter initial movie rating: ");
    scanf("%d", &movies[*num_movies].rating);

    (*num_movies)++;
}

void display_movies(Movie movies[], int num_movies) {
    printf("\n------------------------\n");
    printf("| Movie Title           |\n");
    printf("|------------------------|");
    printf("| Genre                 |\n");
    printf("|------------------------|");
    printf("| Current Rating         |\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_movies; i++) {
        printf("\n| %-20s | %-10s | %-10d |\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

int main() {
    int num_movies = 0;
    Movie movies[10];
    char command;

    do {
        print_menu();
        scanf(" %c", &command);

        switch (command) {
            case '1':
                add_movie(movies, &num_movies);
                break;
            case '2':
                display_movies(movies, num_movies);
                break;
            case '3':
                // Search movie logic here
                break;
            case '4':
                // Update movie rating logic here
                break;
            case '5':
                // Delete movie logic here
                break;
            case '6':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command.\n");
        }
    } while (command != '6');

    return 0;
}