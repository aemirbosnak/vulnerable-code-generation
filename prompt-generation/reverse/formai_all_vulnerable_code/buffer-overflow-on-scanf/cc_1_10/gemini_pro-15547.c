//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>

// Define the rating categories
#define G "G"
#define PG "PG"
#define PG13 "PG-13"
#define R "R"
#define NC17 "NC-17"

// Define the movie titles
#define ROMEO_AND_JULIET "Romeo and Juliet"
#define TITANIC "Titanic"
#define THE_LORD_OF_THE_RINGS "The Lord of the Rings"
#define THE_DARK_KNIGHT "The Dark Knight"
#define THE_AVENGERS "The Avengers"

// Define the movie ratings
#define ROMEO_AND_JULIET_RATING G
#define TITANIC_RATING PG13
#define THE_LORD_OF_THE_RINGS_RATING PG13
#define THE_DARK_KNIGHT_RATING PG13
#define THE_AVENGERS_RATING PG13

// Get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Get the movie title
char *get_movie_title() {
    char *movie_title;
    printf("Enter the movie title: ");
    scanf("%s", movie_title);
    return movie_title;
}

// Get the movie rating
char *get_movie_rating(char *movie_title) {
    char *movie_rating;
    if (strcmp(movie_title, ROMEO_AND_JULIET) == 0) {
        movie_rating = ROMEO_AND_JULIET_RATING;
    } else if (strcmp(movie_title, TITANIC) == 0) {
        movie_rating = TITANIC_RATING;
    } else if (strcmp(movie_title, THE_LORD_OF_THE_RINGS) == 0) {
        movie_rating = THE_LORD_OF_THE_RINGS_RATING;
    } else if (strcmp(movie_title, THE_DARK_KNIGHT) == 0) {
        movie_rating = THE_DARK_KNIGHT_RATING;
    } else if (strcmp(movie_title, THE_AVENGERS) == 0) {
        movie_rating = THE_AVENGERS_RATING;
    } else {
        movie_rating = "Invalid movie title";
    }
    return movie_rating;
}

// Print the movie rating
void print_movie_rating(char *movie_title, char *movie_rating) {
    printf("The movie %s is rated %s.\n", movie_title, movie_rating);
}

// Main function
int main() {
    int age = get_age();
    char *movie_title = get_movie_title();
    char *movie_rating = get_movie_rating(movie_title);
    print_movie_rating(movie_title, movie_rating);
    return 0;
}