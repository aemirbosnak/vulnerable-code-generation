//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Define the criteria for each rating
#define CRITERIA_COUNT 5
#define CRITERIA_LENGTH 50
char *criteria[CRITERIA_COUNT] = {"Plot", "Acting", "Cinematography", "Soundtrack", "Overall Enjoyment"};

typedef struct {
    char title[CRITERIA_LENGTH];
    int rating[CRITERIA_COUNT];
    float average_rating;
} Movie;

// Function to get user input for movie title and ratings
void get_movie_info(Movie *movie) {
    printf("Enter the movie title: ");
    scanf("%s", movie->title);

    for (int i = 0; i < CRITERIA_COUNT; i++) {
        printf("Enter your rating for %s (1-10): ", criteria[i]);
        scanf("%d", &movie->rating[i]);
    }
}

// Function to calculate the average rating for a movie
void calculate_average_rating(Movie *movie) {
    int sum = 0;
    for (int i = 0; i < CRITERIA_COUNT; i++) {
        sum += movie->rating[i];
    }

    movie->average_rating = (float) sum / CRITERIA_COUNT;
}

// Function to print the movie information and average rating
void print_movie_info(Movie *movie) {
    printf("Movie Title: %s\n", movie->title);

    for (int i = 0; i < CRITERIA_COUNT; i++) {
        printf("%s: %d\n", criteria[i], movie->rating[i]);
    }

    printf("Average Rating: %.2f\n", movie->average_rating);
}

int main() {
    Movie movie;

    // Get movie information from user
    get_movie_info(&movie);

    // Calculate average rating
    calculate_average_rating(&movie);

    // Print movie information and average rating
    print_movie_info(&movie);

    return 0;
}