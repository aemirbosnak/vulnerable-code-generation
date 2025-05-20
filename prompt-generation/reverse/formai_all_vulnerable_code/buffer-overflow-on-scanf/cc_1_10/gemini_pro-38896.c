//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Define the movie struct
struct movie {
    char *title;
    char *director;
    int year;
    enum rating rating;
};

// Create a new movie
struct movie *create_movie(char *title, char *director, int year, enum rating rating) {
    struct movie *m = malloc(sizeof(struct movie));
    m->title = title;
    m->director = director;
    m->year = year;
    m->rating = rating;
    return m;
}

// Print the movie information
void print_movie(struct movie *m) {
    printf("%s (%d) - %s - %s\n", m->title, m->year, m->director, m->rating == G ? "G" : m->rating == PG ? "PG" : m->rating == PG13 ? "PG-13" : m->rating == R ? "R" : "NC-17");
}

// Get the user's movie rating
enum rating get_rating() {
    int rating;
    printf("Enter the movie's rating (G, PG, PG-13, R, NC-17): ");
    scanf("%d", &rating);
    return rating;
}

// Main function
int main() {
    // Create a few movies
    struct movie *m1 = create_movie("The Shawshank Redemption", "Frank Darabont", 1994, R);
    struct movie *m2 = create_movie("The Godfather", "Francis Ford Coppola", 1972, R);
    struct movie *m3 = create_movie("The Dark Knight", "Christopher Nolan", 2008, PG13);
    struct movie *m4 = create_movie("Schindler's List", "Steven Spielberg", 1993, R);
    struct movie *m5 = create_movie("The Lord of the Rings: The Return of the King", "Peter Jackson", 2003, PG13);

    // Print the movies
    print_movie(m1);
    print_movie(m2);
    print_movie(m3);
    print_movie(m4);
    print_movie(m5);

    // Get the user's rating for a new movie
    enum rating rating = get_rating();

    // Create a new movie with the user's rating
    struct movie *m6 = create_movie("My Movie", "My Director", 2023, rating);

    // Print the new movie
    print_movie(m6);

    // Free the movies
    free(m1);
    free(m2);
    free(m3);
    free(m4);
    free(m5);
    free(m6);

    return 0;
}