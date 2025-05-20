//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Define the movie rating system
enum rating { G, PG, PG13, R, NC17 };

// Define the movie titles
char *titles[] = {
    "Toy Story",
    "The Lion King",
    "The Shawshank Redemption",
    "The Godfather",
    "Pulp Fiction"
};

// Define the movie ratings
enum rating ratings[] = {
    G,
    G,
    PG13,
    R,
    NC17
};

// Get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Check if the user is old enough to see the movie
int is_old_enough(int age, enum rating rating) {
    switch (rating) {
        case G:
            return 1;
        case PG:
            return age >= 8;
        case PG13:
            return age >= 13;
        case R:
            return age >= 17;
        case NC17:
            return age >= 18;
        default:
            return 0;
    }
}

// Print the movie titles and ratings
void print_movies(int age) {
    for (int i = 0; i < 5; i++) {
        if (is_old_enough(age, ratings[i])) {
            printf("%s (rated %s)\n", titles[i], ratings[i]);
        }
    }
}

// Main function
int main() {
    int age = get_age();
    print_movies(age);
    return 0;
}