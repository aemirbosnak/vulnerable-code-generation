//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rating;
    char movie_title[50];
    char director[50];
    char actor1[50];
    char actor2[50];
    char actor3[50];
    char genre[50];
    char studio[50];
    char release_date[50];
    char plot_summary[200];
    char critic_review[200];
    char user_review[200];

    printf("Welcome to the Surrealist Movie Rating System!\n");
    printf("Please enter the movie title: ");
    scanf("%s", movie_title);
    printf("Please enter the director's name: ");
    scanf("%s", director);
    printf("Please enter the names of the lead actors: ");
    scanf("%s %s %s", actor1, actor2, actor3);
    printf("Please enter the movie's genre: ");
    scanf("%s", genre);
    printf("Please enter the name of the movie studio: ");
    scanf("%s", studio);
    printf("Please enter the release date of the movie: ");
    scanf("%s", release_date);
    printf("Please enter a brief plot summary: ");
    scanf("%s", plot_summary);
    printf("Please enter a critic's review: ");
    scanf("%s", critic_review);
    printf("Please enter your own review: ");
    scanf("%s", user_review);

    srand(time(NULL));
    rating = rand() % 6 + 1;

    printf("\n\nMovie Title: %s\n", movie_title);
    printf("Director: %s\n", director);
    printf("Lead Actors: %s, %s, %s\n", actor1, actor2, actor3);
    printf("Genre: %s\n", genre);
    printf("Studio: %s\n", studio);
    printf("Release Date: %s\n", release_date);
    printf("Plot Summary: %s\n", plot_summary);
    printf("Critic's Review: %s\n", critic_review);
    printf("Your Review: %s\n", user_review);
    printf("Surrealist Rating: %d out of 6\n", rating);

    return 0;
}