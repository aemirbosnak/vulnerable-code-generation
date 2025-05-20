//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

// Structure to represent a movie
struct movie {
    char title[50];
    char genre[20];
    int release_year;
    float rating;
};

// Array of movies
struct movie movies[MAX_MOVIES];

// Number of movies in the array
int num_movies = 0;

// Function to add a new movie
void add_movie() {
    struct movie new_movie;
    printf("Enter movie title: ");
    scanf("%s", new_movie.title);
    printf("Enter movie genre: ");
    scanf("%s", new_movie.genre);
    printf("Enter movie release year: ");
    scanf("%d", &new_movie.release_year);

    // Generate a unique ID for the movie
    int id = rand() % MAX_MOVIES;
    while (movies[id].title[0] != '\0') {
        id = rand() % MAX_MOVIES;
    }

    new_movie.rating = 0;
    movies[id] = new_movie;
    num_movies++;
    printf("Added movie with ID %d\n", id);
}

// Function to rate a movie
void rate_movie() {
    int id, rating;
    printf("Enter movie ID: ");
    scanf("%d", &id);
    if (movies[id].title[0] == '\0') {
        printf("Movie not found\n");
        return;
    }
    printf("Enter rating (1-5): ");
    scanf("%d", &rating);
    if (rating < 1 || rating > 5) {
        printf("Invalid rating\n");
        return;
    }
    float old_rating = movies[id].rating;
    int num_ratings = (int)(old_rating * 2);
    int total_rating = num_ratings * old_rating;
    total_rating += rating;
    num_ratings++;
    float new_rating = (float)total_rating / (float)(num_ratings * 2);
    movies[id].rating = new_rating;
    printf("Rated movie %s with %d stars (old rating: %.2f, new rating: %.2f)\n", movies[id].title, rating, old_rating, new_rating);
}

// Function to print all movies
void print_movies() {
    printf("Movies:\n");
    printf("%-10s %-20s %-10s %-6s\n", "ID", "Title", "Genre", "Rating");
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].title[0] != '\0') {
            printf("%-10d %-20s %-10s %-6.2f\n", i, movies[i].title, movies[i].genre, movies[i].rating);
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Display menu
    char choice;
    do {
        printf("\nMovie Rating System\n");
        printf("====================\n");
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Print all movies\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_movie();
                break;
            case '2':
                rate_movie();
                break;
            case '3':
                print_movies();
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != '4');

    return 0;
}