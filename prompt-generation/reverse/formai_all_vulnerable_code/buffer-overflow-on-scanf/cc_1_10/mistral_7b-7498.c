//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie(char* title, int rating) {
    if (num_movies >= MAX_MOVIES) {
        printf("Max number of movies reached.\n");
        return;
    }

    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = rating;
    num_movies++;
}

void update_rating(char* title, int new_rating) {
    int i;

    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating = new_rating;
            break;
        }
    }
}

void print_movies() {
    int i;

    for (i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    char title[MAX_TITLE_LENGTH];
    int choice, rating;

    while (1) {
        printf("\n1. Add movie\n2. Update rating\n3. Print movies\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating: ");
                scanf("%d", &rating);
                add_movie(title, rating);
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter new movie rating: ");
                scanf("%d", &rating);
                update_rating(title, rating);
                break;
            case 3:
                print_movies();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}