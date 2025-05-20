//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    char rating[5];
    int watched;
};

typedef struct movie Movie;

int main(void) {
    int choice = 0;
    int count = 0;
    int index = 0;
    Movie *movies = NULL;
    int i = 0;
    
    while (1) {
        printf("Movie Rating System\n\n");
        printf("1. Add a movie\n");
        printf("2. Update movie rating\n");
        printf("3. Print watched movies\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        
        if (choice == 1) {
            // add movie
            Movie movie;
            printf("Enter movie title: ");
            fgets(movie.title, 50, stdin);
            movie.title[strlen(movie.title)-1] = '\0'; // remove newline character
            printf("Enter movie rating (1-5): ");
            fgets(movie.rating, 5, stdin);
            movie.rating[strlen(movie.rating)-1] = '\0'; // remove newline character
            movie.watched = 0;
            if (count == 0) {
                movies = (Movie*) malloc(sizeof(Movie));
            } else {
                movies = (Movie*) realloc(movies, (count+1)*sizeof(Movie));
            }
            
            movies[count++] = movie;
            printf("Movie added successfully!\n\n");
        } else if (choice == 2) {
            // update rating
            printf("Enter index of movie to update rating: ");
            scanf("%d", &index);
            fflush(stdin);
            if (index < 0 || index >= count) {
                printf("Invalid index\n\n");
            } else {
                printf("Enter new rating (1-5): ");
                fgets(movies[index].rating, 5, stdin);
                movies[index].rating[strlen(movies[index].rating)-1] = '\0'; // remove newline character
                printf("Rating updated successfully!\n\n");
            }
        } else if (choice == 3) {
            // print watched movies
            printf("Watched Movies:\n");
            for (i = 0; i < count; i++) {
                if (movies[i].watched == 1) {
                    printf("%d. %s (Rating: %s)\n", i+1, movies[i].title, movies[i].rating);
                }
            }
            printf("\n");
        } else if (choice == 4) {
            // exit
            printf("Goodbye!\n");
            exit(0);
        } else {
            // invalid choice
            printf("Invalid choice\n\n");
        }
    }
    
    // free memory
    free(movies);
    
    return 0;
}