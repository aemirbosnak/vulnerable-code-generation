//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    int rating;
    char movie_name[20];
    char director_name[20];
    char actor_name[20];
    char genre[20];
    char review[100];
    char release_date[10];
    char trailer_link[50];

    printf("Welcome to the Movie Rating System!\n");
    printf("Please enter the movie name: ");
    scanf("%s", movie_name);

    printf("Please enter the director's name: ");
    scanf("%s", director_name);

    printf("Please enter the actor's name: ");
    scanf("%s", actor_name);

    printf("Please enter the genre: ");
    scanf("%s", genre);

    printf("Please enter the release date (YYYY-MM-DD): ");
    scanf("%s", release_date);

    printf("Please enter the trailer link: ");
    scanf("%s", trailer_link);

    printf("Please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &rating);

    printf("Please enter a review of the movie:\n");
    scanf("%s", review);

    printf("\nMovie Name: %s\n", movie_name);
    printf("Director Name: %s\n", director_name);
    printf("Actor Name: %s\n", actor_name);
    printf("Genre: %s\n", genre);
    printf("Release Date: %s\n", release_date);
    printf("Trailer Link: %s\n", trailer_link);
    printf("Rating: %d\n", rating);
    printf("Review: %s\n", review);

    return 0;
}