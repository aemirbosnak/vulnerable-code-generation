//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define NAME_LENGTH 50

typedef struct {
    char title[NAME_LENGTH];
    int rating; // Assume rating out of 10
} Movie;

void displayMovies(Movie movies[], int count) {
    printf("Star-crossed Films:\n");
    for (int i = 0; i < count; i++) {
        printf("Movie %d: %s - Rating: %d/10\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Alas! Cannot add more movies, the list is full.\n");
        return;
    }
    printf("Enter the title of the movie (maximum %d characters): ", NAME_LENGTH - 1);
    fgets(movies[*count].title, NAME_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("By what light dost thou rate this movie (0-10): ");
    scanf("%d", &movies[*count].rating);
    getchar();  // Eat the newline character after scanf

    if (movies[*count].rating < 0 || movies[*count].rating > 10) {
        printf("O fair youth, please give the rating a value between 0 and 10!\n");
        return;
    }

    (*count)++;
    printf("Thus, the movie '%s' hath been added with a rating of %d/10.\n", movies[*count - 1].title, movies[*count - 1].rating);
}

void showRatedMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No films have entered this tale of love.\n");
        return;
    }
    displayMovies(movies, count);
}

void editMovieRating(Movie movies[], int count) {
    int choice = 0;
    printf("Which movie wouldst thou like to change the rating of? (1-%d, 0 to exit): ", count);
    scanf("%d", &choice);
    getchar(); // Eat the newline character after scanf

    if (choice > 0 && choice <= count) {
        printf("Enter new rating for '%s' (0-10): ", movies[choice - 1].title);
        scanf("%d", &movies[choice - 1].rating);
        getchar(); // Eat the newline character after scanf

        if (movies[choice - 1].rating < 0 || movies[choice - 1].rating > 10) {
            printf("O gentle friend, please choose a proper rating between 0 and 10.\n");
        } else {
            printf("The rating for '%s' hath been changed to %d/10.\n", movies[choice - 1].title, movies[choice - 1].rating);
        }
    } else if (choice != 0) {
        printf("Verily, that number dost not reflect a movie in our collection.\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice = -1;

    printf("Welcome to the Tragic Loves of Cinema Rating System!\n");
    printf("Where art thou, sweet movie lover? Choose thy fate:\n");

    while (choice != 0) {
        printf("\nMenu:\n");
        printf("1. Add a movie\n");
        printf("2. Display rated movies\n");
        printf("3. Edit a movie rating\n");
        printf("0. Exit\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);
        getchar();  // Eat the newline character after scanf

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                showRatedMovies(movies, count);
                break;
            case 3:
                editMovieRating(movies, count);
                break;
            case 0:
                printf("Parting is such sweet sorrow! Until next we meet...\n");
                break;
            default:
                printf("A choice most foul; choose again, dear lover.\n");
        }
    }
    return 0;
}