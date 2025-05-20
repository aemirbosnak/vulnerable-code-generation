//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players and movies
#define MAX_PLAYERS 10
#define MAX_MOVIES 10

// Define the structure of a player
typedef struct {
    char name[50];
    int ratings[MAX_MOVIES];
} Player;

// Define the structure of a movie
typedef struct {
    char title[50];
    int rating;
} Movie;

// Define the array of players
Player players[MAX_PLAYERS];

// Define the array of movies
Movie movies[MAX_MOVIES];

// Get the number of players
int num_players;

// Get the number of movies
int num_movies;

// Get the ratings from the players
void get_ratings() {
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);

        for (int j = 0; j < num_movies; j++) {
            printf("Enter the rating for movie %d by player %d: ", j + 1, i + 1);
            scanf("%d", &players[i].ratings[j]);
        }
    }
}

// Calculate the average rating for each movie
void calculate_average_ratings() {
    for (int i = 0; i < num_movies; i++) {
        int total = 0;

        for (int j = 0; j < num_players; j++) {
            total += players[j].ratings[i];
        }

        movies[i].rating = total / num_players;
    }
}

// Print the movie ratings
void print_ratings() {
    printf("Movie Ratings:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

// Main function
int main() {
    // Get the number of players
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Get the number of movies
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Get the ratings from the players
    get_ratings();

    // Calculate the average rating for each movie
    calculate_average_ratings();

    // Print the movie ratings
    print_ratings();

    return 0;
}