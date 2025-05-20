//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 50
#define MAX_RATING_LEN 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actor[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    char rating[MAX_RATING_LEN];
} Movie;

int main() {
    Movie movie;
    int choice;
    char input[100];

    do {
        printf("1. Enter movie title\n");
        printf("2. Enter movie director\n");
        printf("3. Enter movie actor\n");
        printf("4. Enter movie genre\n");
        printf("5. Enter movie rating\n");
        printf("6. Display movie details\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movie.title);
                break;
            case 2:
                printf("Enter movie director: ");
                scanf("%s", movie.director);
                break;
            case 3:
                printf("Enter movie actor: ");
                scanf("%s", movie.actor);
                break;
            case 4:
                printf("Enter movie genre: ");
                scanf("%s", movie.genre);
                break;
            case 5:
                printf("Enter movie rating: ");
                scanf("%s", movie.rating);
                break;
            case 6:
                printf("Movie Title: %s\n", movie.title);
                printf("Movie Director: %s\n", movie.director);
                printf("Movie Actor: %s\n", movie.actor);
                printf("Movie Genre: %s\n", movie.genre);
                printf("Movie Rating: %s\n", movie.rating);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}