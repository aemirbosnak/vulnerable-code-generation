//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>

// Define the movie struct
typedef struct {
    char title[50];     // movie title
    char director[50];  // movie director
    int year;           // movie release year
    float rating;       // movie rating out of 10
} Movie;

int main() {

    // Define an array of movies
    Movie movies[10];

    // Loop to take input for each movie
    for (int i = 0; i < 10; i++) {
        printf("Enter the title of movie #%d: ", i+1);
        fgets(movies[i].title, 50, stdin);

        printf("Enter the director of movie #%d: ", i+1);
        fgets(movies[i].director, 50, stdin);

        printf("Enter the release year of movie #%d: ", i+1);
        scanf("%d", &movies[i].year);

        printf("Enter the rating of movie #%d out of 10: ", i+1);
        scanf("%f", &movies[i].rating);

        getchar();  // consume the newline character left in the stream
        printf("\n");
    }

    // Print the list of movies with ratings
    printf("Movie Ratings:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s, directed by %s, released in %d, has a rating of %.1f\n",
                i+1, movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }

    // Calculate the average rating of all movies
    float average_rating = 0;
    for (int i = 0; i < 10; i++) {
        average_rating += movies[i].rating;
    }
    average_rating /= 10;

    // Print the average rating
    printf("\nThe average rating of all movies is %.1f", average_rating);

    return 0;
}