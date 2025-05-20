//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>

typedef struct {
    char title[100];
    char genre[50];
    float rating;
    int reviews;
    float score;
} Movie;

float calculate_score(float rating, int reviews) {
    return (rating * reviews) / (reviews + 1);
}

void print_movie_info(Movie movie) {
    printf("----------------------------------------------------------------------\n");
    printf("Movie Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.1f\n", movie.rating);
    printf("Number of Reviews: %d\n", movie.reviews);
    printf("Calculated Score: %.2f\n", movie.score);
    printf("----------------------------------------------------------------------\n");
}

void initiate_movie(Movie *movie, char *title, char *genre, float rating, int reviews) {
    snprintf(movie->title, sizeof(movie->title), "%s", title);
    snprintf(movie->genre, sizeof(movie->genre), "%s", genre);
    movie->rating = rating;
    movie->reviews = reviews;
    movie->score = calculate_score(rating, reviews);
    printf("Movie \"%s\" initialized successfully.\n", movie->title);
}

void input_movie_details(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, sizeof(movie->title), stdin);
    movie->title[strcspn(movie->title, "\n")] = 0; // Remove newline character

    printf("Enter genre: ");
    fgets(movie->genre, sizeof(movie->genre), stdin);
    movie->genre[strcspn(movie->genre, "\n")] = 0; // Remove newline character

    printf("Enter rating (0-10): ");
    scanf("%f", &movie->rating);
    
    printf("Enter number of reviews: ");
    scanf("%d", &movie->reviews);

    movie->score = calculate_score(movie->rating, movie->reviews);
}

void sort_movies(Movie movies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (movies[i].score < movies[j].score) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void display_movies(Movie movies[], int count) {
    printf("Displaying Movies:\n");
    for (int i = 0; i < count; i++) {
        print_movie_info(movies[i]);
    }
}

int main() {
    int n;

    printf("Welcome to the Movie Rating System!\n");
    printf("How many movies would you like to input? ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    Movie movies[n];

    for (int i = 0; i < n; i++) {
        printf("Entering details for movie %d:\n", i + 1);
        input_movie_details(&movies[i]);
        printf("\n");
    }

    sort_movies(movies, n);
    printf("\nMovies sorted by score:\n");
    display_movies(movies, n);
    
    return 0;
}