//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Declare the movie rating system
enum rating {G, PG, PG13, R, NC17, UNRATED};

// Declare the movie struct
struct movie {
    char *title;
    int year;
    enum rating rating;
};

// Create a new movie
struct movie *create_movie(char *title, int year, enum rating rating) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Year: %d\n", movie->year);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG-13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC-17\n");
            break;
        case UNRATED:
            printf("Unrated\n");
            break;
    }
}

// Get the user's input
void get_input(char *prompt, char *input) {
    printf("%s", prompt);
    scanf("%s", input);
}

// Main function
int main() {
    // Create a new movie
    struct movie *movie = create_movie("The Shawshank Redemption", 1994, R);

    // Print the movie information
    print_movie(movie);

    // Get the user's input
    char input[100];
    get_input("Enter a new rating for the movie: ", input);

    // Convert the user's input to an enum rating
    enum rating rating;
    if (strcmp(input, "G") == 0) {
        rating = G;
    } else if (strcmp(input, "PG") == 0) {
        rating = PG;
    } else if (strcmp(input, "PG-13") == 0) {
        rating = PG13;
    } else if (strcmp(input, "R") == 0) {
        rating = R;
    } else if (strcmp(input, "NC-17") == 0) {
        rating = NC17;
    } else if (strcmp(input, "Unrated") == 0) {
        rating = UNRATED;
    } else {
        printf("Invalid rating\n");
        return 1;
    }

    // Update the movie's rating
    movie->rating = rating;

    // Print the updated movie information
    print_movie(movie);

    // Free the allocated memory
    free(movie->title);
    free(movie);

    return 0;
}