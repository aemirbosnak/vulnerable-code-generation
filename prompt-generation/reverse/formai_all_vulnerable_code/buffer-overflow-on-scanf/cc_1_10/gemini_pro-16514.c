//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to store movie rating information
typedef struct {
    char *title;
    int rating;
    int num_votes;
} MovieRating;

// Function to compare two movie ratings by rating
int compare_ratings(const void *a, const void *b) {
    MovieRating *m1 = (MovieRating *)a;
    MovieRating *m2 = (MovieRating *)b;
    return m1->rating - m2->rating;
}

// Function to print a movie rating
void print_rating(MovieRating *rating) {
    printf("%s: %d (%d votes)\n", rating->title, rating->rating, rating->num_votes);
}

// Function to get user input for a movie rating
MovieRating *get_rating() {
    MovieRating *rating = malloc(sizeof(MovieRating));
    if (rating == NULL) {
        fprintf(stderr, "Error allocating memory for movie rating.\n");
        exit(1);
    }

    char buffer[1024];
    printf("Enter movie title: ");
    fgets(buffer, sizeof(buffer), stdin);
    rating->title = strdup(buffer);

    printf("Enter movie rating (1-5): ");
    scanf("%d", &rating->rating);

    printf("Enter number of votes: ");
    scanf("%d", &rating->num_votes);

    return rating;
}

// Main function
int main() {
    // Initialize array of movie ratings
    MovieRating ratings[10];
    for (int i = 0; i < 10; i++) {
        ratings[i] = *get_rating();
    }

    // Sort the array of movie ratings by rating
    qsort(ratings, 10, sizeof(MovieRating), compare_ratings);

    // Print the sorted array of movie ratings
    for (int i = 0; i < 10; i++) {
        print_rating(&ratings[i]);
    }

    return 0;
}