//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 10

typedef struct movie {
    char title[50];
    int rating;
} Movie;

void print_menu();
Movie movies[MAX_MOVIES];
int num_movies = 0;

int main() {
    int choice;
    char title[50];
    int rating;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_movies < MAX_MOVIES) {
                    printf("Enter movie title: ");
                    scanf("%s", title);
                    strcpy(movies[num_movies].title, title);

                    printf("Enter movie rating: ");
                    scanf("%d", &rating);
                    movies[num_movies].rating = rating;

                    num_movies++;
                    printf("Movie added successfully!\n");
                } else {
                    printf("Maximum number of movies reached.\n");
                }
                break;
            case 2:
                if (num_movies > 0) {
                    printf("Enter movie title to update: ");
                    scanf("%s", title);

                    for (int i = 0; i < num_movies; i++) {
                        if (strcmp(movies[i].title, title) == 0) {
                            printf("Enter new movie rating: ");
                            scanf("%d", &rating);
                            movies[i].rating = rating;
                            printf("Movie updated successfully!\n");
                            break;
                        }
                    }
                } else {
                    printf("No movies to update.\n");
                }
                break;
            case 3:
                if (num_movies > 0) {
                    for (int i = 0; i < num_movies; i++) {
                        printf("%d. %s - %d\n", i + 1, movies[i].title, movies[i].rating);
                    }
                } else {
                    printf("No movies to display.\n");
                }
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("\nCyberpunk Movie Rating System\n");
    printf("------------------------------\n");
    printf("1. Add a movie\n");
    printf("2. Update a movie rating\n");
    printf("3. Display movies and ratings\n");
    printf("4. Exit\n");
}