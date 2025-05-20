//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int rating;
} Movie;

Movie movies[MAX_RATINGS];
int num_movies = 0;

int main() {
    int i, j, k;
    char input[50];

    // Create some movies
    for (i = 0; i < MAX_RATINGS; i++) {
        strcpy(movies[i].title, "Movie #");
        movies[i].rating = rand() % 10 + 1;
        num_movies++;
    }

    // Display the movies and their ratings
    printf("Movie Rating System\n\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Edit a movie's rating\n");
    printf("4. Remove a movie\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &j);

    switch (j) {
        case 1:
            printf("Enter the title of the movie: ");
            scanf("%s", input);
            for (i = 0; i < MAX_RATINGS; i++) {
                if (strcmp(input, movies[i].title) == 0) {
                    printf("Movie with the same title already exists.\n");
                    break;
                }
            }
            if (i == MAX_RATINGS) {
                strcpy(movies[i].title, input);
                movies[i].rating = rand() % 10 + 1;
                num_movies++;
                printf("Movie added.\n");
            }
            break;
        case 2:
            printf("Movies:\n");
            for (i = 0; i < MAX_RATINGS; i++) {
                printf("Movie #%d: %s - %d\n", i+1, movies[i].title, movies[i].rating);
            }
            break;
        case 3:
            printf("Enter the title of the movie: ");
            scanf("%s", input);
            for (i = 0; i < MAX_RATINGS; i++) {
                if (strcmp(input, movies[i].title) == 0) {
                    printf("Enter the new rating: ");
                    scanf("%d", &k);
                    movies[i].rating = k;
                    printf("Rating updated.\n");
                    break;
                }
            }
            break;
        case 4:
            printf("Enter the title of the movie: ");
            scanf("%s", input);
            for (i = 0; i < MAX_RATINGS; i++) {
                if (strcmp(input, movies[i].title) == 0) {
                    printf("Movie removed.\n");
                    for (j = i; j < num_movies - 1; j++) {
                        strcpy(movies[j].title, movies[j+1].title);
                        movies[j].rating = movies[j+1].rating;
                    }
                    num_movies--;
                    break;
                }
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}