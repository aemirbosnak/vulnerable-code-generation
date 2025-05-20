//FormAI DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MOVIES 10

struct movie {
    char title[50];
    char director[50];
    int year;
    int rating;
};

struct movie movie_collection[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    if (num_movies == MAX_MOVIES) {
        printf("Sorry, the movie collection is already at its maximum capacity.\n");
        return;
    }
    struct movie new_movie;
    printf("Enter the title of the movie: ");
    scanf("%s", new_movie.title);
    printf("Enter the director of the movie: ");
    scanf("%s", new_movie.director);
    printf("Enter the year the movie was released: ");
    scanf("%d", &new_movie.year);
    printf("Enter your rating (from 1 to 10) of the movie: ");
    scanf("%d", &new_movie.rating);
    movie_collection[num_movies] = new_movie;
    num_movies++;
}

void display_movies() {
    if (num_movies == 0) {
        printf("There are no movies in the collection.\n");
        return;
    }
    printf("Title\t\tDirector\tYear\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%d\t%d\n",
                movie_collection[i].title,
                movie_collection[i].director,
                movie_collection[i].year,
                movie_collection[i].rating);
    }
}

int main() {
    int choice;
    while (1) {
        printf("==============\n");
        printf(" MOVIE RATINGS \n");
        printf("==============\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_movie(); break;
            case 2: display_movies(); break;
            case 3: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}