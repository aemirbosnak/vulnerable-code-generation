//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
#define G    0
#define PG   1
#define PG13 2
#define R    3
#define NC17 4

// Define the movie titles
char *movies[] = {
    "The Shawshank Redemption",
    "The Godfather",
    "The Dark Knight",
    "12 Angry Men",
    "Schindler's List",
    "The Lord of the Rings: The Return of the King",
    "Pulp Fiction",
    "Fight Club",
    "The Matrix",
    "Star Wars: Episode V - The Empire Strikes Back"
};

// Define the movie ratings
int ratings[] = {
    PG13,
    R,
    PG13,
    PG,
    R,
    PG13,
    R,
    R,
    R,
    PG
};

// Print the movie titles and ratings
int main() {
    // Get the user's age
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    // Print the movie titles and ratings
    printf("Movie Titles and Ratings:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: ", movies[i]);
        switch (ratings[i]) {
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
        }
    }

    // Print a message to the user
    if (age < 13) {
        printf("You are not old enough to see any of these movies.\n");
    } else if (age < 17) {
        printf("You are only allowed to see movies rated PG or PG-13.\n");
    } else {
        printf("You are allowed to see all of these movies.\n");
    }

    return 0;
}