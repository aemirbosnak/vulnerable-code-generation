//FormAI DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure movie to hold movie information
struct movie {
    char title[50];
    char director[50];
    int rating;
};

// function to input movie information
void inputMovie(struct movie *m) {
    printf("Enter the movie title: ");
    fgets(m->title, 50, stdin);
    strtok(m->title, "\n"); // remove the newline character
    printf("Enter the director's name: ");
    fgets(m->director, 50, stdin);
    strtok(m->director, "\n"); // remove the newline character
    printf("Enter the movie rating (1-10): ");
    scanf("%d", &m->rating);
    getchar(); // remove the newline character
}

// function to display movie information
void displayMovie(struct movie m) {
    printf("\nMovie title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Rating: %d\n", m.rating);
}

// function to compare two movies based on their ratings
int compareMovies(const void *a, const void *b) {
    struct movie *m1 = (struct movie *)a;
    struct movie *m2 = (struct movie *)b;
    if (m1->rating > m2->rating) {
        return -1;
    } else if (m1->rating < m2->rating) {
        return 1;
    } else {
        return 0;
    }
}

// main function
int main(void) {
    int n;
    printf("Enter the number of movies to rate: ");
    scanf("%d", &n);
    getchar(); // remove the newline character

    // dynamically allocate memory for an array of n movies
    struct movie *movies = malloc(n * sizeof(struct movie));

    // input the movie information
    for (int i = 0; i < n; i++) {
        printf("\nMovie %d:\n", i+1);
        inputMovie(&movies[i]);
    }

    // sort the movies based on their ratings
    qsort(movies, n, sizeof(struct movie), compareMovies);

    // display the movies in ranked order
    printf("\nRanked movies by rating:\n");
    for (int i = 0; i < n; i++) {
        printf("\nRank %d:\n", i+1);
        displayMovie(movies[i]);
    }

    // free the dynamically allocated memory
    free(movies);

    return 0;
}