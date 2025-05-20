//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50
#define MAX_REVIEW_LEN 200

typedef struct {
char title[MAX_TITLE_LEN];
char review[MAX_REVIEW_LEN];
int rating;
} Movie;

// Function to compare two movies based on their ratings
int compare_movies(const void *a, const void *b) {
Movie *movie1 = (Movie *)a;
Movie *movie2 = (Movie *)b;
return movie2->rating - movie1->rating;
}

// Function to print a movie's details
void print_movie(Movie *movie) {
printf("Title: %s\n", movie->title);
printf("Review: %s\n", movie->review);
printf("Rating: %d\n\n", movie->rating);
}

// Main function
int main() {
// Array of movies
Movie movies[MAX_MOVIES];

// Number of movies
int num_movies = 0;

// Read movies from file
FILE *fp = fopen("movies.txt", "r");
if (fp == NULL) {
perror("Error opening file");
return EXIT_FAILURE;
}

while (fscanf(fp, "%s %s %d", movies[num_movies].title, movies[num_movies].review, &movies[num_movies].rating) != EOF) {
num_movies++;
}

fclose(fp);

// Sort movies by rating
qsort(movies, num_movies, sizeof(Movie), compare_movies);

// Print sorted movies
for (int i = 0; i < num_movies; i++) {
print_movie(&movies[i]);
}

return EXIT_SUCCESS;
}