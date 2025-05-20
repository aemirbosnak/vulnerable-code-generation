//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

//initialize struct for each movie's information
struct movie {
    char title[50];
    char director[50];
    int releaseYear;
    float rating;
} database[100];

int main() {
    int numMovies;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("How many movies would you like to rate? (max 100)\n");
    scanf("%d", &numMovies);

    //loop through user input to collect each movie's information
    for (int i=0; i<numMovies; i++) {
        printf("Enter title of movie #%d: ", i+1);
        scanf("%s", &database[i].title);
        printf("Enter director of %s: ", database[i].title);
        scanf("%s", &database[i].director);
        printf("Enter release year of %s: ", database[i].title);
        scanf("%d", &database[i].releaseYear);

        //ask user to rate the movie (1-10)
        printf("On a scale of 1 to 10, how would you rate %s? ", database[i].title);
        scanf("%f", &database[i].rating);
    }

    //display each movie's information including rating in stars
    printf("\nHere are the ratings for each movie in our database:\n");

    for (int i=0; i<numMovies; i++) {
        printf("\nMovie Title: %s\n", database[i].title);
        printf("Director: %s\n", database[i].director);
        printf("Release Year: %d\n", database[i].releaseYear);

        printf("Rating: ");
        //convert rating float to integer and print that many stars
        for (int j=0; j<(int)database[i].rating; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nThanks for using our Unique C Movie Rating System!\n");
    return 0;
}