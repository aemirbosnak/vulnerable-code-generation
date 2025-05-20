//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    int numberOfMovies;
    printf("Welcome to the Movie Rating System! \n");
    printf("How many movies do you want to rate? ");
    scanf("%d", &numberOfMovies);
    int ratings[numberOfMovies];
    char movieTitles[numberOfMovies][50];
    char genres[numberOfMovies][50];
    int criticsRatings[numberOfMovies];
    int boxOfficeEarnings[numberOfMovies];
    int audienceRatings[numberOfMovies];
    char directors[numberOfMovies][50];
    char actors[numberOfMovies][50];
    int i, j;
    for (i = 0; i < numberOfMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movieTitles[i]);
        printf("Enter the genre of movie %d: ", i+1);
        scanf("%s", genres[i]);
        printf("Enter the critics rating for movie %d (out of 10): ", i+1);
        scanf("%d", &criticsRatings[i]);
        printf("Enter the box office earnings for movie %d (in millions): ", i+1);
        scanf("%d", &boxOfficeEarnings[i]);
        printf("Enter the audience rating for movie %d (out of 10): ", i+1);
        scanf("%d", &audienceRatings[i]);
        printf("Enter the name of the director for movie %d: ", i+1);
        scanf("%s", directors[i]);
        printf("Enter the name of the lead actor/actress for movie %d: ", i+1);
        scanf("%s", actors[i]);
        ratings[i] = (criticsRatings[i] + boxOfficeEarnings[i] + audienceRatings[i])/3;
    }
    printf("\nThe Movie Ratings:\n");
    for (i = 0; i < numberOfMovies; i++) {
        printf("%s\n", movieTitles[i]);
        printf("Genre: %s\n", genres[i]);
        printf("Critics Rating: %d/10\n", criticsRatings[i]);
        printf("Box Office Earnings: $%d Million\n", boxOfficeEarnings[i]);
        printf("Audience Rating: %d/10\n", audienceRatings[i]);
        printf("Director: %s\n", directors[i]);
        printf("Lead Actor/Actress: %s\n", actors[i]);
        printf("Overall Rating: %d/10\n\n", ratings[i]);
    }
    return 0;
}