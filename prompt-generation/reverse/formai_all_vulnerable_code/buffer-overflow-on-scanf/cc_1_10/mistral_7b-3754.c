//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    if (num_movies >= MAX_MOVIES) {
        printf("Max movies limit reached!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);

    printf("Enter movie rating (1-5): ");
    scanf("%d", &movies[num_movies].rating);

    num_movies++;
}

void display_movies() {
    if (num_movies == 0) {
        printf("No movies added yet!\n");
        return;
    }

    printf("\nMovie titles and ratings:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s - %d stars\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add a new movie\n");
        printf("2. Display all movies and ratings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}