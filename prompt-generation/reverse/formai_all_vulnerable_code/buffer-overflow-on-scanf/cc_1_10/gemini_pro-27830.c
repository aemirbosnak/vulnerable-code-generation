//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
#define G 1
#define PG 2
#define PG13 3
#define R 4

// Define the movie titles
char *movies[] = {
    "The Shawshank Redemption",
    "The Godfather",
    "The Dark Knight",
    "12 Angry Men",
    "Schindler's List",
    "The Lord of the Rings: The Return of the King",
    "Pulp Fiction",
    "Forrest Gump",
    "The Matrix",
    "Good Will Hunting"
};

// Define the movie ratings
int ratings[] = {
    PG13,
    R,
    PG13,
    G,
    R,
    PG13,
    R,
    PG13,
    R,
    R
};

// Get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Check if the user is old enough to see the movie
int check_rating(int age, int rating) {
    if (age >= 17 && rating == R) {
        return 1;
    } else if (age >= 13 && rating == PG13) {
        return 1;
    } else if (age >= 0 && rating == G || rating == PG) {
        return 1;
    } else {
        return 0;
    }
}

// Print the list of movies
void print_movies(int age) {
    printf("Here is a list of movies that are appropriate for your age:\n");
    for (int i = 0; i < 10; i++) {
        if (check_rating(age, ratings[i])) {
            printf("%s\n", movies[i]);
        }
    }
}

// Main function
int main() {
    // Get the user's age
    int age = get_age();

    // Print the list of movies
    print_movies(age);

    return 0;
}