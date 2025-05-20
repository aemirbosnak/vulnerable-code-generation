//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50
#define MAX_RATING_LEN 5

typedef struct {
    char title[MAX_TITLE_LEN];
    char rating[MAX_RATING_LEN];
} Movie;

Movie movies[MAX_MOVIES];
int numMovies = 0;

void addMovie() {
    if (numMovies >= MAX_MOVIES) {
        printf("Maximum number of movies reached!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf("%s", movies[numMovies].title);

    printf("Enter movie rating: ");
    scanf("%s", movies[numMovies].rating);

    numMovies++;
}

void displayMovies() {
    int i;

    printf("\nMovie Ratings:\n");
    for (i = 0; i < numMovies; i++) {
        printf("%d. %s - %s\n", i+1, movies[i].title, movies[i].rating);
    }
}

void searchMovie() {
    char title[MAX_TITLE_LEN];
    int i;

    printf("Enter movie title to search: ");
    scanf("%s", title);

    for (i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie found!\n");
            printf("Rating: %s\n", movies[i].rating);
            return;
        }
    }

    printf("Movie not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Movie\n2. Display Movies\n3. Search Movie\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}