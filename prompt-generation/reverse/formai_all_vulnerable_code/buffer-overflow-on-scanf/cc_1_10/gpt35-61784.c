//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char title[100];
    int rating;
} movie_t;

int main() {
    int num_movies = 0;
    movie_t movies[MAX_MOVIES];

    // Loop to add movies
    while (num_movies < MAX_MOVIES) {
        char title[100];
        int rating;

        // Prompt the user to enter movie title
        printf("Enter movie title (or 'quit' to stop): ");
        if (fgets(title, sizeof(title), stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }

        // Check if the user wants to quit
        if (strcmp(title, "quit\n") == 0) {
            break;
        }

        // Prompt the user to enter movie rating
        printf("Enter movie rating (1-10): ");
        if (scanf("%d", &rating) != 1) {
            printf("Error reading input\n");
            return 1;
        }
        getchar(); // Remove the newline character from the input buffer

        // Check if the rating is valid
        if (rating < 1 || rating > 10) {
            printf("Invalid rating. Rating must be between 1 and 10\n");
            continue;
        }

        // Add the movie to the array
        strcpy(movies[num_movies].title, title);
        movies[num_movies].rating = rating;
        num_movies++;
    }

    // Print the list of movies
    printf("\nList of movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%d/10)\n", i+1, movies[i].title, movies[i].rating);
    }

    return 0;
}