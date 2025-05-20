//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

struct movie {
    char title[MAX_WORD_LENGTH];
    char director[MAX_WORD_LENGTH];
    char actors[MAX_WORD_LENGTH];
    int rating;
    char genre[MAX_WORD_LENGTH];
};

void read_movie(struct movie *movie) {
    printf("Enter the movie title: ");
    scanf("%s", movie->title);

    printf("Enter the director: ");
    scanf("%s", movie->director);

    printf("Enter the actors: ");
    scanf("%s", movie->actors);

    printf("Enter the rating (1-10): ");
    scanf("%d", &movie->rating);

    printf("Enter the genre: ");
    scanf("%s", movie->genre);
}

void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Rating: %d\n", movie->rating);
    printf("Genre: %s\n", movie->genre);
}

int main() {
    struct movie movie;
    int num_movies = 0;
    char choice;

    do {
        printf("Welcome to the Movie Rating System!\n");
        printf("What would you like to do?\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                read_movie(&movie);
                num_movies++;
                break;
            case '2':
                printf("You have %d movie(s).\n", num_movies);
                printf("=============================\n");
                for(int i=0; i<num_movies; i++) {
                    print_movie(&movie);
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}