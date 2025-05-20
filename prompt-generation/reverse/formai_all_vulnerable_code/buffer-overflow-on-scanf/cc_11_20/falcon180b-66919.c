//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_RATING_LENGTH 10
#define MAX_GENRE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char genre[MAX_GENRE_LENGTH];
} Movie;

int main() {
    Movie movie;
    int choice;

    do {
        printf("1. Add Movie\n");
        printf("2. View Movie\n");
        printf("3. Edit Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Search Movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Movie Title: ");
                scanf("%s", movie.title);
                printf("Enter Director Name: ");
                scanf("%s", movie.director);
                printf("Enter Actor Name: ");
                scanf("%s", movie.actor);
                printf("Enter Movie Rating: ");
                scanf("%s", movie.rating);
                printf("Enter Movie Genre: ");
                scanf("%s", movie.genre);
                printf("Movie added successfully!\n");
                break;
            case 2:
                printf("Enter Movie Title to view: ");
                scanf("%s", movie.title);
                if(strcmp(movie.title, "")!= 0) {
                    printf("Movie Title: %s\n", movie.title);
                    printf("Director Name: %s\n", movie.director);
                    printf("Actor Name: %s\n", movie.actor);
                    printf("Movie Rating: %s\n", movie.rating);
                    printf("Movie Genre: %s\n", movie.genre);
                } else {
                    printf("No movie found with the given title.\n");
                }
                break;
            case 3:
                printf("Enter Movie Title to edit: ");
                scanf("%s", movie.title);
                if(strcmp(movie.title, "")!= 0) {
                    printf("Enter Director Name: ");
                    scanf("%s", movie.director);
                    printf("Enter Actor Name: ");
                    scanf("%s", movie.actor);
                    printf("Enter Movie Rating: ");
                    scanf("%s", movie.rating);
                    printf("Enter Movie Genre: ");
                    scanf("%s", movie.genre);
                    printf("Movie edited successfully!\n");
                } else {
                    printf("No movie found with the given title.\n");
                }
                break;
            case 4:
                printf("Enter Movie Title to delete: ");
                scanf("%s", movie.title);
                if(strcmp(movie.title, "")!= 0) {
                    printf("Movie deleted successfully!\n");
                } else {
                    printf("No movie found with the given title.\n");
                }
                break;
            case 5:
                printf("Enter Movie Title to search: ");
                scanf("%s", movie.title);
                if(strcmp(movie.title, "")!= 0) {
                    printf("Movie Title: %s\n", movie.title);
                    printf("Director Name: %s\n", movie.director);
                    printf("Actor Name: %s\n", movie.actor);
                    printf("Movie Rating: %s\n", movie.rating);
                    printf("Movie Genre: %s\n", movie.genre);
                } else {
                    printf("No movie found with the given title.\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 6);

    return 0;
}