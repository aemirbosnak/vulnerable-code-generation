//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie(char *title, char *genre, int rating) {
    if (num_movies >= MAX_MOVIES) {
        printf("Cannot add movie, maximum movies limit reached.\n");
        return;
    }
    strcpy(movies[num_movies].title, title);
    strcpy(movies[num_movies].genre, genre);
    movies[num_movies].rating = rating;
    num_movies++;
}

void view_movies() {
    if (num_movies == 0) {
        printf("No movies in the system.\n");
        return;
    }
    printf("\nMovie Title\tGenre\tRating\n--------------------------------------\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t\t%s\t%d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

int main() {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    int choice, rating;

    while (1) {
        printf("\n1. Add Movie\n2. View Movies\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie genre: ");
                scanf("%s", genre);
                printf("Enter movie rating (1-10): ");
                scanf("%d", &rating);
                add_movie(title, genre, rating);
                break;
            case 2:
                view_movies();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}