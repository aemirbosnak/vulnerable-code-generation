//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
#define RATING_G "G"
#define RATING_PG "PG"
#define RATING_PG13 "PG-13"
#define RATING_R "R"
#define RATING_NC17 "NC-17"

// Define the movie genres
#define GENRE_ACTION "Action"
#define GENRE_COMEDY "Comedy"
#define GENRE_DRAMA "Drama"
#define GENRE_HORROR "Horror"
#define GENRE_ROMANCE "Romance"

// Define the maximum number of movies
#define MAX_MOVIES 100

// Define the structure of a movie
typedef struct {
    char title[50];
    char genre[20];
    char rating[5];
    int year;
} Movie;

// Define the array of movies
Movie movies[MAX_MOVIES];

// Initialize the number of movies
int num_movies = 0;

// Get the rating of a movie
char *get_rating(int age) {
    if (age < 13) {
        return RATING_G;
    } else if (age < 17) {
        return RATING_PG;
    } else if (age < 21) {
        return RATING_PG13;
    } else if (age < 65) {
        return RATING_R;
    } else {
        return RATING_NC17;
    }
}

// Get the genre of a movie
char *get_genre(int choice) {
    switch (choice) {
        case 1:
            return GENRE_ACTION;
        case 2:
            return GENRE_COMEDY;
        case 3:
            return GENRE_DRAMA;
        case 4:
            return GENRE_HORROR;
        case 5:
            return GENRE_ROMANCE;
        default:
            return "";
    }
}

// Add a movie to the array of movies
void add_movie(char *title, char *genre, char *rating, int year) {
    strcpy(movies[num_movies].title, title);
    strcpy(movies[num_movies].genre, genre);
    strcpy(movies[num_movies].rating, rating);
    movies[num_movies].year = year;
    num_movies++;
}

// Print the array of movies
void print_movies() {
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%s, %s, %d)\n", movies[i].title, movies[i].genre, movies[i].rating, movies[i].year);
    }
}

// Get the user's input
void get_input() {
    char title[50];
    char genre[20];
    char rating[5];
    int year;

    printf("Enter the title of the movie: ");
    scanf("%s", title);

    printf("Enter the genre of the movie (1 for Action, 2 for Comedy, 3 for Drama, 4 for Horror, 5 for Romance): ");
    int choice;
    scanf("%d", &choice);
    strcpy(genre, get_genre(choice));

    printf("Enter the rating of the movie (G, PG, PG-13, R, NC-17): ");
    scanf("%s", rating);

    printf("Enter the year the movie was released: ");
    scanf("%d", &year);

    add_movie(title, genre, rating, year);
}

// Main function
int main() {

    // Get the user's input
    get_input();

    // Print the array of movies
    print_movies();

    return 0;
}