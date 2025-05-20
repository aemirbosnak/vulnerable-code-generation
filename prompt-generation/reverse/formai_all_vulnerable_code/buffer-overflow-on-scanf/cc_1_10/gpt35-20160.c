//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

/* Constants for movie ratings */
#define FRESH 1
#define ROTTEN 0

/* Struct for a movie rating */
struct movie_rating {
    char* title;
    int rating;
};

/* Function to add a new movie rating */
void add_movie_rating(struct movie_rating* ratings, int* num_ratings) {
    char buffer[256];
    int rating;

    printf("Enter the name of the movie: ");
    fgets(buffer, 256, stdin);
    ratings[*num_ratings].title = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(ratings[*num_ratings].title, buffer);

    printf("Enter the rating of the movie (1 for fresh, 0 for rotten): ");
    scanf("%d", &rating);
    getchar();
    if (rating != FRESH && rating != ROTTEN) {
        printf("Invalid rating. Please enter either 1 for fresh or 0 for rotten.\n");
        return;
    }

    ratings[*num_ratings].rating = rating;
    *num_ratings = *num_ratings + 1;

    printf("Movie rating added.\n");
}

/* Function to display all movie ratings */
void display_movie_ratings(struct movie_rating* ratings, int num_ratings) {
    if (num_ratings == 0) {
        printf("No movie ratings available.\n");
        return;
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("- %s %s\n", ratings[i].title, ratings[i].rating == FRESH ? "(Fresh)" : "(Rotten)");
    }
}

int main() {
    struct movie_rating ratings[10];
    int num_ratings = 0;
    char input[256];

    while (1) {
        printf("Enter a command (add, display, exit): ");
        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "add") == 0) {
            add_movie_rating(ratings, &num_ratings);
        } else if (strcmp(input, "display") == 0) {
            display_movie_ratings(ratings, num_ratings);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please enter either add, display, or exit.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}