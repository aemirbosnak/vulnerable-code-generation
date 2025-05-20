//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie genres
typedef enum {
    ACTION,
    ADVENTURE,
    COMEDY,
    DRAMA,
    FANTASY,
    HORROR,
    MUSICAL,
    ROMANCE,
    SCI_FI,
    THRILLER,
    WESTERN
} Genre;

// Define the movie structure
typedef struct {
    char *title;
    Rating rating;
    Genre genre;
    int release_year;
    int runtime;
} Movie;

// Create a function to print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General Audiences\n");
    printf("PG: Parental Guidance Suggested\n");
    printf("PG13: Parents Strongly Cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No One 17 and Under Admitted\n");
}

// Create a function to print the movie genres
void print_genres() {
    printf("Movie Genres:\n");
    printf("ACTION: Action Movies\n");
    printf("ADVENTURE: Adventure Movies\n");
    printf("COMEDY: Comedy Movies\n");
    printf("DRAMA: Drama Movies\n");
    printf("FANTASY: Fantasy Movies\n");
    printf("HORROR: Horror Movies\n");
    printf("MUSICAL: Musical Movies\n");
    printf("ROMANCE: Romance Movies\n");
    printf("SCI_FI: Sci-Fi Movies\n");
    printf("THRILLER: Thriller Movies\n");
    printf("WESTERN: Western Movies\n");
}

// Create a function to print the movie details
void print_movie(Movie *movie) {
    printf("Movie Title: %s\n", movie->title);
    printf("Movie Rating: %d\n", movie->rating);
    printf("Movie Genre: %d\n", movie->genre);
    printf("Movie Release Year: %d\n", movie->release_year);
    printf("Movie Runtime: %d minutes\n", movie->runtime);
}

// Create a function to get the user's input
void get_user_input(Movie *movie) {
    char *title;
    int rating;
    int genre;
    int release_year;
    int runtime;

    printf("Enter the movie title: ");
    scanf("%s", title);

    printf("Enter the movie rating (0-4): ");
    scanf("%d", &rating);

    printf("Enter the movie genre (0-10): ");
    scanf("%d", &genre);

    printf("Enter the movie release year: ");
    scanf("%d", &release_year);

    printf("Enter the movie runtime (in minutes): ");
    scanf("%d", &runtime);

    movie->title = title;
    movie->rating = rating;
    movie->genre = genre;
    movie->release_year = release_year;
    movie->runtime = runtime;
}

// Create a function to main()
int main() {
    Movie movie;

    // Print the movie rating system
    print_rating_system();

    // Print the movie genres
    print_genres();

    // Get the user's input
    get_user_input(&movie);

    // Print the movie details
    print_movie(&movie);

    return 0;
}