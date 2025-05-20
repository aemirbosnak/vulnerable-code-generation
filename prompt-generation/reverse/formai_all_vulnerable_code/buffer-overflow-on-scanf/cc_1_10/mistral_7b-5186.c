//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 50
#define MAX_RATING 11

typedef struct {
    char title[MAX_TITLE];
    int rating;
} Movie;

void addMovie(Movie movies[], char title[], int rating) {
    int i;
    for (i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].rating == 0) {
            strcpy(movies[i].title, title);
            movies[i].rating = rating;
            break;
        }
    }
}

void displayMovies(Movie movies[]) {
    int i, maxRating = 0, maxRatingIndex;
    for (i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].rating > maxRating) {
            maxRating = movies[i].rating;
            maxRatingIndex = i;
        }
    }

    printf("\n***** Top Rated Movie *****\n");
    printf("Title: %s\n", movies[maxRatingIndex].title);
    printf("Rating: %d\n", movies[maxRatingIndex].rating);

    printf("\n***** All Movies *****\n");
    for (i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].rating != 0) {
            printf("%s - %d\n", movies[i].title, movies[i].rating);
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES] = { {0} };
    char title[MAX_TITLE];
    int rating;

    while (1) {
        printf("\n1. Add Movie\n2. Display Top Rated Movie\n3. Display All Movies\n4. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating (1-10): ");
                scanf("%d", &rating);
                addMovie(movies, title, rating);
                break;

            case 2:
                displayMovies(movies);
                break;

            case 3:
                displayMovies(movies);
                printf("\nDisplaying all movies...\n");
                break;

            case 4:
                printf("Quitting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}