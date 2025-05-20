//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char title[50];
    char director[50];
    char genre[50];
    int year;
    int rating;
    char review[1000];
} Movie;

Movie movies[5];

int main() {
    srand(time(NULL));

    printf("Welcome to the Ephemeral Movie Rating System!\n");
    printf("Please enter the title, director, genre, and year of the movie:\n");
    printf("Title: ");
    scanf("%s", movies[0].title);
    printf("Director: ");
    scanf("%s", movies[0].director);
    printf("Genre: ");
    scanf("%s", movies[0].genre);
    printf("Year: ");
    scanf("%d", &(movies[0].year));

    for (int i = 1; i < 5; i++) {
        srand(time(NULL));
        movies[i].title[rand() % 50] = 'X';
        movies[i].director[rand() % 50] = 'Y';
        movies[i].genre[rand() % 50] = 'Z';
        movies[i].year = rand() % 100;
        movies[i].rating = rand() % 10 + 1;
    }

    printf("\n");
    printf("Here are the top 5 rated movies:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (%s, %s, %d) - Rating: %d\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].year, movies[i].rating);
    }

    printf("\n");
    printf("Please rate the following movie:\n");
    printf("Title: ");
    scanf("%s", movies[5].title);
    printf("Director: ");
    scanf("%s", movies[5].director);
    printf("Genre: ");
    scanf("%s", movies[5].genre);
    printf("Year: ");
    scanf("%d", &(movies[5].year));

    printf("\n");
    printf("Please enter your review for the movie:\n");
    scanf("%s", movies[5].review);

    printf("\n");
    printf("Thank you for your review! Here is the updated rating:\n");
    printf("Title: ");
    scanf("%s", movies[5].title);
    printf("Director: ");
    scanf("%s", movies[5].director);
    printf("Genre: ");
    scanf("%s", movies[5].genre);
    printf("Year: ");
    scanf("%d", &(movies[5].year));
    printf("Rating: %d\n", movies[5].rating);

    return 0;
}