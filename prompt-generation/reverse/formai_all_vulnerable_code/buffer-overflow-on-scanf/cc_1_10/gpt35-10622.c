//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// function to display the age appropriateness of a movie based on its rating
void displayAgeAppropriateness(char rating)
{
    if (rating == 'G') {
        printf("Suitable for all ages.\n");
    } else if (rating == 'PG') {
        printf("Parental guidance suggested. Some material may not be suitable for children.\n");
    } else if (rating == 'PG-13') {
        printf("Parental guidance strongly suggested. Some material may be inappropriate for children under 13.\n");
    } else if (rating == 'R') {
        printf("Restricted. People under 17 require accompanying parent or adult guardian.\n");
    } else if (rating == 'NC-17') {
        printf("No one under 17 admitted.\n");
    }
}

// function to obtain and validate the rating of a movie
char getRating()
{
    char rating;

    printf("Enter the rating of the movie (G, PG, PG-13, R, NC-17): ");
    scanf("%c", &rating);

    while (rating != 'G' && rating != 'PG' && rating != 'PG-13' && rating != 'R' && rating != 'NC-17') {
        printf("Invalid rating. Please enter a valid rating: ");
        fflush(stdin);
        scanf("%c", &rating);
    }

    return rating;
}

int main()
{
    char rating;

    printf("Welcome to the Medieval Movie Rating System!\n");

    rating = getRating();

    printf("\nBased on the movie's rating of %c, the age appropriateness is:\n", rating);

    displayAgeAppropriateness(rating);

    return 0;
}