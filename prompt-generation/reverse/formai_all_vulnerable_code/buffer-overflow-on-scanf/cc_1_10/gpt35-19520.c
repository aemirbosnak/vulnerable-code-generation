//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include<stdio.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

// Struct to hold movie details and ratings
struct movie {
    char title[50];
    char genre[20];
    int year;
    float rating[MAX_RATINGS];
};

// Function to calculate the average rating of a movie
float calculate_average_rating(struct movie m) {
    float sum = 0;
    int i;
    for(i=0; i<MAX_RATINGS; i++) {
        sum += m.rating[i];
    }
    return (sum / MAX_RATINGS);
}

int main() {
    struct movie movies[MAX_MOVIES];

    int num_movies, i, j;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Get details of each movie
    for(i=0; i<num_movies; i++) {
        printf("\n\nEnter the details of movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Year: ");
        scanf("%d", &movies[i].year);

        // Get ratings of the movie
        printf("Enter the ratings of the movie (out of 5):\n");
        for(j=0; j<MAX_RATINGS; j++) {
            printf("Rating %d: ", j+1);
            scanf("%f", &movies[i].rating[j]);
        }
    }

    // Display the details of each movie
    printf("\n\nDetails of all the movies:\n");
    for(i=0; i<num_movies; i++) {
        printf("\n\nMovie %d:\nTitle: %s\nGenre: %s\nYear: %d\n",i+1, movies[i].title, movies[i].genre, movies[i].year);
        printf("Average Rating: %.2f\n", calculate_average_rating(movies[i]));
    }

    return 0;
}