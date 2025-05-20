//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define NUM_CATEGORIES 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float ratings[NUM_CATEGORIES];
    float average_rating;
} Movie;

void input_movie(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, MAX_TITLE_LENGTH, stdin);
    strtok(movie->title, "\n"); // Remove trailing newline character

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("Enter rating for category %d (0-10): ", i + 1);
        scanf("%f", &movie->ratings[i]);
        while (movie->ratings[i] < 0 || movie->ratings[i] > 10) {
            printf("Invalid rating. Please enter again for category %d: ", i + 1);
            scanf("%f", &movie->ratings[i]);
        }
    }

    // Calculate average rating
    movie->average_rating = 0;
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        movie->average_rating += movie->ratings[i];
    }
    movie->average_rating /= NUM_CATEGORIES;
}

void display_movie(const Movie *movie) {
    printf("\nMovie Title: %s\n", movie->title);
    printf("Ratings: ");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%.2f ", movie->ratings[i]);
    }
    printf("\nAverage Rating: %.2f\n", movie->average_rating);
}

void sort_movies(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].average_rating < movies[j + 1].average_rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void display_all_movies(const Movie *movies, int count) {
    for (int i = 0; i < count; i++) {
        display_movie(&movies[i]);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char continue_input;

    do {
        if (num_movies >= MAX_MOVIES) {
            printf("Movie limit reached! Cannot add more movies.\n");
            break;
        }

        input_movie(&movies[num_movies]);
        num_movies++;
        
        printf("Do you want to add another movie? (y/n): ");
        getchar(); // To consume newline after entering ratings
        scanf("%c", &continue_input);
    } while (continue_input == 'y' || continue_input == 'Y');

    sort_movies(movies, num_movies);

    printf("\nSorted Movies by Average Rating:\n");
    display_all_movies(movies, num_movies);

    return 0;
}