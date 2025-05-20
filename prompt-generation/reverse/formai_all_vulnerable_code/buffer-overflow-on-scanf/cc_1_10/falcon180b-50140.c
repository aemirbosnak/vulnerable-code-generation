//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main() {
    //initialize variables
    int choice = 0;
    char movie[100];
    char rating[10];
    char review[500];
    char title[100];
    char director[100];
    char actors[500];
    char genre[100];
    int length;
    int year;
    int rating_int;
    int rating_count = 0;
    double rating_avg;
    int i;

    //seed random number generator
    srand(time(NULL));

    //display menu
    printf("Welcome to the Surrealist Movie Rating System!\n");
    printf("Please enter the name of the movie you would like to rate:\n");
    scanf("%s", movie);

    //get movie details
    printf("Enter the length of the movie in minutes:\n");
    scanf("%d", &length);
    printf("Enter the year the movie was released:\n");
    scanf("%d", &year);

    //get rating
    printf("On a scale of 1 to 10, how would you rate this movie?\n");
    scanf("%s", rating);

    //convert rating to integer
    rating_int = atoi(rating);

    //add rating to array
    for (i = 0; i < strlen(rating); i++) {
        rating_count += rating[i] - '0';
    }

    //calculate average rating
    rating_avg = (double)rating_count / strlen(rating);

    //display rating
    printf("You rated this movie a %.1f out of 10.\n", rating_avg);

    //get movie details
    printf("Enter the director of the movie:\n");
    scanf("%s", director);
    printf("Enter the actors in the movie (separated by commas):\n");
    scanf("%s", actors);
    printf("Enter the genre of the movie:\n");
    scanf("%s", genre);

    //display movie details
    printf("Movie: %s\n", movie);
    printf("Length: %d minutes\n", length);
    printf("Year: %d\n", year);
    printf("Director: %s\n", director);
    printf("Actors: %s\n", actors);
    printf("Genre: %s\n", genre);

    //display surrealist review
    printf("\nSurrealist Review:\n");
    printf("The %s is a %.1f-minute journey through the mind of director %s, featuring an ensemble cast of %s. Released in the year %d, this film defies conventional genres and instead exists in a realm of its own creation.\n", movie, length, director, actors, year);
    printf("With its abstract visuals and enigmatic storytelling, %s is a true masterpiece of surrealist cinema.\n", movie);

    return 0;
}