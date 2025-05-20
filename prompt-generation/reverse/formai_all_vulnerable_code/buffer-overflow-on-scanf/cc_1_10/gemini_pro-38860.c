//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the ratings
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Define the movie titles
#define MOVIES 5
char *movies[MOVIES] = {
    "The Shawshank Redemption",
    "The Godfather",
    "The Dark Knight",
    "12 Angry Men",
    "Schindler's List"
};

// Define the movie ratings
int ratings[MOVIES] = {
    PG13,
    R,
    PG13,
    G,
    R
};

// Get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Check if the movie is appropriate for the user's age
int is_appropriate(int age, int rating) {
    if (age >= 17) {
        return 1;
    } else if (age >= 13 && rating != R && rating != NC17) {
        return 1;
    } else if (age >= 6 && rating != R && rating != NC17 && rating != PG13) {
        return 1;
    } else {
        return 0;
    }
}

// Print the list of movies
void print_movies(int age) {
    printf("The following movies are appropriate for your age:\n");
    for (int i = 0; i < MOVIES; i++) {
        if (is_appropriate(age, ratings[i])) {
            printf("%s\n", movies[i]);
        }
    }
}

// Main function
int main() {
    int age = get_age();
    print_movies(age);
    return 0;
}