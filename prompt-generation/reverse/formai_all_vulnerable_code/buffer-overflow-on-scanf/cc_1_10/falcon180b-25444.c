//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 500

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    char rating[MAX_RATING_LEN];
    char review[MAX_REVIEW_LEN];
} Movie;

int main() {
    Movie movie;
    int choice;

    do {
        printf("Movie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movie.title);
                printf("Enter director name: ");
                scanf("%s", movie.director);
                printf("Enter actors (comma-separated): ");
                scanf("%s", movie.actors);
                printf("Enter genre: ");
                scanf("%s", movie.genre);
                printf("Enter rating (out of 10): ");
                scanf("%s", movie.rating);
                printf("Enter review: ");
                scanf("%[^\n]", movie.review);
                printf("Movie added successfully!\n");
                break;
            case 2:
                printf("Movie Title\tDirector\tActors\tGenre\tRating\tReview\n");
                printf("-------------------------------------------------------------\n");
                system("ls *.txt | sort | while read file; do echo $(cat $file | cut -d'|' -f1); done");
                break;
            case 3:
                printf("Enter movie title to search: ");
                scanf("%s", movie.title);
                system("grep -l \"$title\" *.txt");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}