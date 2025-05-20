//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print the movie ratings
void print_ratings(int ratings[], int n) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < n; i++) {
        printf("%d stars\n", ratings[i]);
    }
}

// Function to calculate the average rating of a movie
float calculate_average_rating(int ratings[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ratings[i];
    }
    return (float) sum / n;
}

// Function to get user input for movie ratings
void get_movie_ratings(int ratings[], int n) {
    printf("Enter movie ratings (1-5 stars):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
    }
}

// Recursive function to get user input for movie titles
void get_movie_titles(char titles[], int n) {
    printf("Enter movie titles:\n");
    scanf("%s", titles);
    if (n > 1) {
        printf("Enter %d more movie titles:\n", n - 1);
        get_movie_titles(titles + strlen(titles) + 1, n - 1);
    }
}

// Function to print the movie titles
void print_titles(char titles[], int n) {
    printf("Movie Titles:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", titles + i * (strlen(titles) + 1));
    }
}

// Function to calculate the average rating of all movies
float calculate_average_ratings(int ratings[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ratings[i];
    }
    return sum / n;
}

// Function to get user input for number of movies
void get_num_movies(int n) {
    printf("Enter number of movies:\n");
    scanf("%d", &n);
}

int main() {
    int n;
    get_num_movies(n);
    char titles[n][100];
    get_movie_titles(titles, n);
    int ratings[n];
    get_movie_ratings(ratings, n);
    print_titles(titles, n);
    print_ratings(ratings, n);
    float avg_rating = calculate_average_ratings(ratings, n);
    printf("Average rating: %.2f stars\n", avg_rating);
    return 0;
}