//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[100];
    char director[100];
    char actors[200];
    int year;
    int rating;
} Movie;

void readMovie(Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter director name: ");
    scanf("%s", movie->director);
    printf("Enter actors (separated by commas): ");
    scanf("%s", movie->actors);
    printf("Enter year of release: ");
    scanf("%d", &movie->year);
    printf("Enter movie rating (1-5): ");
    scanf("%d", &movie->rating);
}

void printMovie(Movie movie) {
    printf("\nMovie Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Year of release: %d\n", movie.year);
    printf("Rating: %d stars\n\n", movie.rating);
}

int main() {
    int choice;
    char filename[100];
    FILE *fp;
    Movie movie;

    printf("Welcome to the Movie Rating System\n");
    printf("1. Read movie data from file\n");
    printf("2. Enter movie data manually\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if(fp == NULL) {
                printf("File not found\n");
                break;
            }
            while(fscanf(fp, "%s %s %s %d %d", movie.title, movie.director, movie.actors, &movie.year, &movie.rating)!= EOF) {
                printMovie(movie);
            }
            fclose(fp);
            break;
        case 2:
            printf("Enter movie data:\n");
            readMovie(&movie);
            printMovie(movie);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}