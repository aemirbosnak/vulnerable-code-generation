//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// Define Movie struct
typedef struct {
    char title[100];
    char director[50];
    int release_year;
    float rating;
    time_t timestamp;
} Movie;

// Function to convert rating from string to float
float string_to_rating(char* rating_str) {
    int points = 0;
    int multiplier = 1;

    for (int i = 0; i < strlen(rating_str); i++) {
        char c = rating_str[i];

        if (isdigit(c)) {
            points += (isdigit(c) - '0') * multiplier;
            multiplier *= 10;
        } else if (c == '.') {
            multiplier = 1;
        }
    }

    return (float)points / 10.0;
}

// Function to print movie details
void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Release Year: %d\n", movie.release_year);
    printf("Rating: %.2f\n", movie.rating);
    printf("Timestamp: %s\n", ctime(&movie.timestamp));
    printf("\n");
}

// Function to add a new movie to the database
void add_movie(Movie* movies, int* movies_count, int movies_capacity, char* title, char* director, int release_year, char* rating_str) {
    if (*movies_count >= movies_capacity) {
        printf("Database is full.\n");
        return;
    }

    strcpy(movies[*movies_count].title, title);
    strcpy(movies[*movies_count].director, director);
    movies[*movies_count].release_year = release_year;
    movies[*movies_count].rating = string_to_rating(rating_str);
    movies[*movies_count].timestamp = time(NULL);
    (*movies_count)++;
}

int main() {
    const int movies_capacity = 10;
    int movies_count = 0;
    Movie movies[movies_capacity];

    while (true) {
        printf("Welcome to the Futuristic Movie Rating System! (Type 'quit' to exit)\n");
        printf("Enter movie title: ");
        char title[100];
        scanf("%s", title);

        if (strcmp(title, "quit") == 0) {
            break;
        }

        printf("Enter movie director: ");
        char director[50];
        scanf("%s", director);

        printf("Enter movie release year: ");
        int release_year;
        scanf("%d", &release_year);

        printf("Enter movie rating (e.g. '3.5'): ");
        char rating_str[10];
        scanf("%s", rating_str);

        add_movie(movies, &movies_count, movies_capacity, title, director, release_year, rating_str);
    }

    printf("Database updated with %d movies.\n", movies_count);

    for (int i = 0; i < movies_count; i++) {
        print_movie(movies[i]);
    }

    return 0;
}