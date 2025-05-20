//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: safe
// Unique C Movie Rating System Example Program in Safe Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a movie
struct Movie {
    char name[50];
    int rating;
};

// Define a structure for a movie list
struct MovieList {
    struct Movie* movies;
    int num_movies;
};

// Function to add a movie to a list
void addMovie(struct MovieList* list, char* name, int rating) {
    list->num_movies++;
    list->movies = realloc(list->movies, list->num_movies * sizeof(struct Movie));
    strcpy(list->movies[list->num_movies - 1].name, name);
    list->movies[list->num_movies - 1].rating = rating;
}

// Function to get the highest rated movie in a list
int getHighestRated(struct MovieList* list) {
    int highest_rating = 0;
    int highest_rating_index = -1;
    for (int i = 0; i < list->num_movies; i++) {
        if (list->movies[i].rating > highest_rating) {
            highest_rating = list->movies[i].rating;
            highest_rating_index = i;
        }
    }
    return highest_rating_index;
}

// Function to get the lowest rated movie in a list
int getLowestRated(struct MovieList* list) {
    int lowest_rating = 100;
    int lowest_rating_index = -1;
    for (int i = 0; i < list->num_movies; i++) {
        if (list->movies[i].rating < lowest_rating) {
            lowest_rating = list->movies[i].rating;
            lowest_rating_index = i;
        }
    }
    return lowest_rating_index;
}

// Function to get the average rating of a list
float getAverageRating(struct MovieList* list) {
    float sum = 0;
    for (int i = 0; i < list->num_movies; i++) {
        sum += list->movies[i].rating;
    }
    return sum / list->num_movies;
}

// Function to get the median rating of a list
float getMedianRating(struct MovieList* list) {
    int mid = list->num_movies / 2;
    int median = list->movies[mid].rating;
    if (list->num_movies % 2 == 0) {
        median = (list->movies[mid - 1].rating + list->movies[mid].rating) / 2;
    }
    return median;
}

// Function to get the standard deviation of a list
float getStandardDeviation(struct MovieList* list) {
    float mean = getAverageRating(list);
    float sum_sq_diff = 0;
    for (int i = 0; i < list->num_movies; i++) {
        float diff = list->movies[i].rating - mean;
        sum_sq_diff += diff * diff;
    }
    return sqrt(sum_sq_diff / list->num_movies);
}

int main() {
    struct MovieList list = {NULL, 0};

    addMovie(&list, "The Shawshank Redemption", 9);
    addMovie(&list, "The Godfather", 9);
    addMovie(&list, "The Godfather: Part II", 9);
    addMovie(&list, "The Dark Knight", 8);
    addMovie(&list, "12 Angry Men", 8);

    printf("Highest rated movie: %s\n", list.movies[getHighestRated(&list)].name);
    printf("Lowest rated movie: %s\n", list.movies[getLowestRated(&list)].name);
    printf("Average rating: %.2f\n", getAverageRating(&list));
    printf("Median rating: %.2f\n", getMedianRating(&list));
    printf("Standard deviation: %.2f\n", getStandardDeviation(&list));

    return 0;
}