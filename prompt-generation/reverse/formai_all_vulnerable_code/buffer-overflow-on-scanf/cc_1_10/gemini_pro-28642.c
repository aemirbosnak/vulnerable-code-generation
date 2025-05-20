//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG_13 2
#define R 3
#define NC_17 4

// Define the movie titles and ratings
char *movies[] = {
    "The Shawshank Redemption",
    "The Godfather",
    "The Dark Knight",
    "12 Angry Men",
    "Schindler's List",
    "Pulp Fiction",
    "Fight Club",
    "The Lord of the Rings: The Return of the King",
    "The Matrix",
    "Star Wars: Episode V - The Empire Strikes Back",
};

int ratings[] = {
    PG_13,
    R,
    PG_13,
    G,
    R,
    R,
    R,
    PG_13,
    R,
    PG,
};

// Get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Print the movies that are appropriate for the user's age
void print_movies(int age) {
    for (int i = 0; i < 10; i++) {
        if (ratings[i] <= age) {
            printf("%s\n", movies[i]);
        }
    }
}

// Main function
int main() {
    // Get the user's age
    int age = get_age();

    // Print the movies that are appropriate for the user's age
    print_movies(age);

    return 0;
}