//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_RATING 10

typedef struct {
    char title[MAX_NAME_LENGTH];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int numMovies = 0;

void addMovie() {
    if (numMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[numMovies].title, MAX_NAME_LENGTH, stdin);
    movies[numMovies].title[strcspn(movies[numMovies].title, "\n")] = '\0';

    printf("Enter movie rating (1-10): ");
    scanf("%d", &movies[numMovies].rating);

    numMovies++;
}

void printMovies() {
    printf("\nMovie Title\tRating\n");

    for (int i = 0; i < numMovies; i++) {
        printf("%s\t%d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Print Movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                printMovies();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}