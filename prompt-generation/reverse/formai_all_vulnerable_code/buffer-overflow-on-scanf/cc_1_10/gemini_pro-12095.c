//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the rating categories
#define G "G"
#define PG "PG"
#define PG13 "PG-13"
#define R "R"
#define NC17 "NC-17"

// Define the movie rating system
struct rating_system {
    char *name;
    int age_restriction;
    char *description;
};

// Create an array of rating categories
struct rating_system rating_categories[] = {
    {G, 0, "General audiences"},
    {PG, 8, "Parental guidance suggested"},
    {PG13, 13, "Parents strongly cautioned"},
    {R, 17, "Restricted"},
    {NC17, 18, "No one 17 and under admitted"}
};

// Get the rating category for a given age
char *get_rating_category(int age) {
    for (int i = 0; i < 5; i++) {
        if (age < rating_categories[i].age_restriction) {
            return rating_categories[i].name;
        }
    }

    return NC17;
}

// Print the rating categories
void print_rating_categories() {
    for (int i = 0; i < 5; i++) {
        printf("%s: %s (%d)\n", rating_categories[i].name, rating_categories[i].description, rating_categories[i].age_restriction);
    }
}

// Get the user's age
int get_user_age() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    return age;
}

// Get the movie rating
char *get_movie_rating(int age) {
    char *rating = get_rating_category(age);

    return rating;
}

// Print the movie rating
void print_movie_rating(char *rating) {
    printf("The movie is rated %s.\n", rating);
}

// Main function
int main() {
    int age;
    char *rating;

    // Get the user's age
    age = get_user_age();

    // Get the movie rating
    rating = get_movie_rating(age);

    // Print the movie rating
    print_movie_rating(rating);

    return 0;
}