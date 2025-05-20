//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RATING 10
#define MAX_LENGTH 100
#define MAX_MOVIES 100

typedef struct {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    char actor[MAX_LENGTH];
    char release_date[MAX_LENGTH];
    int rating;
} movie;

int main() {
    int i, n;
    movie movies[MAX_MOVIES];
    char input[MAX_LENGTH];

    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n\n");
    printf("Please enter the number of movies you want to rate: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nMovie %d:\n", i+1);
        printf("Title: ");
        scanf("%[^\n]", movies[i].title);
        printf("Director: ");
        scanf("%[^\n]", movies[i].director);
        printf("Actor: ");
        scanf("%[^\n]", movies[i].actor);
        printf("Release Date: ");
        scanf("%[^\n]", movies[i].release_date);
        printf("Rating (1-10): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\n\nThank you for using the Post-Apocalyptic Movie Rating System!\n\n");
    for (i = 0; i < n; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actor: %s\n", movies[i].actor);
        printf("Release Date: %s\n", movies[i].release_date);
        printf("Rating: %d\n\n", movies[i].rating);
    }

    return 0;
}