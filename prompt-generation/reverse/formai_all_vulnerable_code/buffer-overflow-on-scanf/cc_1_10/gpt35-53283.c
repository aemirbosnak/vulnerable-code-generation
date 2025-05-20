//FormAI DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>

// Define a struct for movie ratings
typedef struct {
    char title[50];
    int rating;
} movie;

// Function to find the average rating of all movies in the system
float findAverageRating(movie movies[], int numMovies) {
    float sum = 0;
    for (int i = 0; i < numMovies; i++) {
        sum += movies[i].rating;
    }
    return sum / numMovies;
}

int main() {
    // Define an array of movies
    movie movies[5];

    // Prompt the user to enter titles and ratings for the movies
    for (int i = 0; i < 5; i++) {
        printf("Enter the title of movie #%d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter the rating (0-100) for %s: ", movies[i].title);
        scanf("%d", &movies[i].rating);
    }

    // Print out the movies and their ratings
    printf("The movies and their ratings are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }

    // Find the average rating of all movies
    float average = findAverageRating(movies, 5);

    // Print out the average rating
    printf("The average movie rating is: %.2f\n", average);

    // Assign cinematic ratings based on the average rating
    char cinematicRating[20] = "";
    if (average >= 90) {
        sprintf(cinematicRating, "Masterpiece");
    } else if (average >= 80) {
        sprintf(cinematicRating, "Must-see");
    } else if (average >= 70) {
        sprintf(cinematicRating, "Recommended");
    } else if (average >= 60) {
        sprintf(cinematicRating, "Watchable");
    } else {
        sprintf(cinematicRating, "Avoid at all costs");
    }

    // Print out the cinematic rating
    printf("Cinematic rating: %s\n", cinematicRating);

    return 0;
}