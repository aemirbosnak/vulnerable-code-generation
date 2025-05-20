//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct movie {
    char title[100];
    char director[50];
    char actors[200];
    char genre[50];
    char rating[10];
    int duration;
    char plot[500];
};

struct movie create_movie() {
    struct movie movie;
    printf("Enter the movie title: ");
    scanf("%s", movie.title);
    printf("Enter the director name: ");
    scanf("%s", movie.director);
    printf("Enter the actors' names (separated by comma): ");
    scanf("%s", movie.actors);
    printf("Enter the movie genre: ");
    scanf("%s", movie.genre);
    printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");
    scanf("%s", movie.rating);
    printf("Enter the movie duration (in minutes): ");
    scanf("%d", &movie.duration);
    printf("Enter the movie plot: ");
    scanf("%[^\n]", movie.plot);
    return movie;
}

void print_movie(struct movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %s\n", movie.rating);
    printf("Duration: %d minutes\n", movie.duration);
    printf("Plot: %s\n", movie.plot);
}

int main() {
    struct movie movie;
    char choice;
    do {
        printf("\n1. Create movie\n2. Print movie\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                movie = create_movie();
                break;
            case '2':
                print_movie(movie);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(1);
    return 0;
}