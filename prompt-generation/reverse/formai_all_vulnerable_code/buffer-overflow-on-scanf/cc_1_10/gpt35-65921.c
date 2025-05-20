//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie rating system structure
struct movie {
    char name[100];
    char genre[50];
    int year;
    float rating;
};

int main() {
    int n;
    printf("How many movies do you want to rate?\n");
    scanf("%d", &n);

    // Allocate memory for array of movies
    struct movie *movies = (struct movie*) malloc(n * sizeof(struct movie));

    // Loop to get movie details
    for(int i=0; i<n; i++) {
        printf("\nEnter details for movie %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", movies[i].name);
        printf("Genre: ");
        scanf(" %[^\n]s", movies[i].genre);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
    }

    // Display movie list
    printf("\n=== Movie List ===\n");
    for(int i=0; i<n; i++) {
        printf("\n%d. %s\n", i+1, movies[i].name);
        printf("   Genre: %s\n", movies[i].genre);
        printf("   Year: %d\n", movies[i].year);
        printf("   Rating: %.1f\n", movies[i].rating);
    }

    // Calculate average rating and display it
    float total_rating = 0;
    for(int i=0; i<n; i++) {
        total_rating += movies[i].rating;
    }
    float avg_rating = total_rating/n;
    printf("\nAverage Rating: %.1f", avg_rating);

    // Free memory
    free(movies);

    return 0;
}