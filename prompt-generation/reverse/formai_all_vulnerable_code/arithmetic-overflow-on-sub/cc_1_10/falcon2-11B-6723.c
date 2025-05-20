//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    int rating;
    char genre[20];
};

int main() {
    struct movie movies[10]; // Array to store movie details
    int num_movies = 0; // Number of movies in the array

    // Prompt user to enter movie details
    printf("Enter the number of movies to be rated: ");
    scanf("%d", &num_movies);
    printf("Enter the title of the first movie: ");
    scanf("%s", movies[0].title);
    printf("Enter the rating of the first movie: ");
    scanf("%d", &movies[0].rating);
    printf("Enter the genre of the first movie: ");
    scanf("%s", movies[0].genre);

    // Display the first movie details
    printf("\nMovie 1:\nTitle: %s\nRating: %d\nGenre: %s\n\n", movies[0].title, movies[0].rating, movies[0].genre);

    // Prompt user to enter details for remaining movies
    for (int i = 1; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);
        printf("Enter the rating of movie %d: ", i + 1);
        scanf("%d", &movies[i].rating);
        printf("Enter the genre of movie %d: ", i + 1);
        scanf("%s", movies[i].genre);

        // Display the movie details
        printf("\nMovie %d:\nTitle: %s\nRating: %d\nGenre: %s\n\n", i + 1, movies[i].title, movies[i].rating, movies[i].genre);
    }

    // Sort movies by rating in descending order
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = 0; j < num_movies - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                struct movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    // Display the sorted movies
    printf("\nSorted Movies by Rating:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Movie %d:\nTitle: %s\nRating: %d\nGenre: %s\n\n", i + 1, movies[i].title, movies[i].rating, movies[i].genre);
    }

    return 0;
}