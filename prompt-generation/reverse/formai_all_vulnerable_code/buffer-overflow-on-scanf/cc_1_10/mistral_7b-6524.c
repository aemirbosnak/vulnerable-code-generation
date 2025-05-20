//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    int year;
    float rating;
} Movie;

Movie movies[5] = {{"The Shawshank Redemption", 1994, 0}, {"The Godfather", 1972, 0}, {"Pulp Fiction", 1994, 0}, {"The Dark Knight", 2008, 0}, {"12 Angry Men", 1957, 0}};

void initMovies() {
    for (int i = 0; i < 5; i++) {
        printf("Enter title for movie %d: ", i + 1);
        scanf("%s", movies[i].title);
        printf("Enter year for movie %d: ", i + 1);
        scanf("%d", &movies[i].year);
        movies[i].rating = 0;
    }
}

void printMovie(Movie movie) {
    printf("\nTitle: %s", movie.title);
    printf("\nYear: %d", movie.year);
    printf("\nRating: %.1f\n", movie.rating);
}

float avgRating() {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += movies[i].rating;
    }
    return sum / 5;
}

void rateMovie(int index, float newRating) {
    movies[index].rating = newRating;
}

int main() {
    initMovies();
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
    }
    printf("\nAverage rating: %.1f\n", avgRating());

    int movieIndex;
    float newRating;
    printf("\nEnter index of the movie to rate: ");
    scanf("%d", &movieIndex);
    printf("Enter new rating for the movie: ");
    scanf("%f", &newRating);
    rateMovie(movieIndex - 1, newRating);

    printf("\nUpdated movie list: \n");
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
    }
    printf("\nAverage rating: %.1f\n", avgRating());

    return 0;
}