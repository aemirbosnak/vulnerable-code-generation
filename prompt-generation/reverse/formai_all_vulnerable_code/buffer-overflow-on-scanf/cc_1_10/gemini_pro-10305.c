//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating categories
#define G "G - General Audiences"
#define PG "PG - Parental Guidance Suggested"
#define PG13 "PG-13 - Parents Strongly Cautioned"
#define R "R - Restricted"
#define NC17 "NC-17 - No One 17 and Under Admitted"

// Define the movie rating system
typedef struct movie_rating_system {
    char name[20];
    char description[100];
} movie_rating_system_t;

// Create an array of movie rating systems
movie_rating_system_t rating_systems[] = {
    { "G", "General Audiences" },
    { "PG", "Parental Guidance Suggested" },
    { "PG-13", "Parents Strongly Cautioned" },
    { "R", "Restricted" },
    { "NC-17", "No One 17 and Under Admitted" }
};

// Get the rating for a given movie
movie_rating_system_t get_rating(int age) {
    if (age < 0 || age > 100) {
        fprintf(stderr, "Invalid age: %d\n", age);
        exit(EXIT_FAILURE);
    }

    if (age < 17) {
        return rating_systems[0];
    } else if (age < 13) {
        return rating_systems[1];
    } else if (age < 17) {
        return rating_systems[2];
    } else if (age < 18) {
        return rating_systems[3];
    } else {
        return rating_systems[4];
    }
}

// Print the rating for a given movie
void print_rating(movie_rating_system_t rating) {
    printf("Rating: %s (%s)\n", rating.name, rating.description);
}

int main() {
    // Get the user's age
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    // Get the rating for the movie
    movie_rating_system_t rating = get_rating(age);

    // Print the rating
    print_rating(rating);

    return EXIT_SUCCESS;
}