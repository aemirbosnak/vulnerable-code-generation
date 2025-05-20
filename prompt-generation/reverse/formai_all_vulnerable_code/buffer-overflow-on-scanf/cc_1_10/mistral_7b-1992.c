//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50
#define MAX_REVIEW_LENGTH 100
#define RATING_MIN 1
#define RATING_MAX 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    int rating;
} movie_t;

movie_t movies[MAX_MOVIES];
int num_movies = 0;

void print_movies() {
    printf("Post-Apocalyptic Movie Database:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%d): %s\n", movies[i].name, movies[i].rating, movies[i].review);
    }
}

void add_movie() {
    if (num_movies >= MAX_MOVIES) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter movie name: ");
    scanf("%s", movies[num_movies].name);

    printf("Enter movie review: ");
    scanf("%s", movies[num_movies].review);

    printf("Enter movie rating (1-10): ");
    scanf("%d", &movies[num_movies].rating);

    if (movies[num_movies].rating < RATING_MIN || movies[num_movies].rating > RATING_MAX) {
        printf("Invalid rating. Please try again.\n");
        return;
    }

    num_movies++;
}

int main() {
    int choice;

    while (1) {
        printf("\nPost-Apocalyptic Movie Database Menu:\n");
        printf("1. Add movie\n");
        printf("2. View movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                print_movies();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}