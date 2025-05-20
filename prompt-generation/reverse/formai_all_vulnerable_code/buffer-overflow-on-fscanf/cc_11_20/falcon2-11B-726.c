//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

struct movie {
    char title[50];
    int rating;
    char comment[100];
};

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    FILE *fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %s\n", movies[num_movies].title, &movies[num_movies].rating, movies[num_movies].comment) == 3) {
        num_movies++;
    }

    fclose(fp);

    printf("Movie Rating System\n");
    printf("--------------------\n");
    printf("1. Display Movie\n");
    printf("2. Search Movie\n");
    printf("3. Add Movie\n");
    printf("4. Update Movie Rating\n");
    printf("5. Delete Movie\n");
    printf("6. Exit\n");
    printf("--------------------\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_movies; i++) {
                    printf("Title: %s\n", movies[i].title);
                    printf("Rating: %d\n", movies[i].rating);
                    printf("Comment: %s\n", movies[i].comment);
                }
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].title, movies[num_movies].title) == 0) {
                        printf("Movie found!\n");
                        printf("Title: %s\n", movies[i].title);
                        printf("Rating: %d\n", movies[i].rating);
                        printf("Comment: %s\n", movies[i].comment);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].title, movies[num_movies].title) == 0) {
                        printf("Movie added!\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].title, movies[num_movies].title) == 0) {
                        printf("Enter new rating: ");
                        scanf("%d", &movies[i].rating);
                        printf("Movie rating updated!\n");
                        break;
                    }
                }
                break;
            case 5:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].title, movies[num_movies].title) == 0) {
                        printf("Movie deleted!\n");
                        break;
                    }
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}