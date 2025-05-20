//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    char director[30];
    int year;
    float rating;
};

void printMovie(struct movie m) {
    printf("%s, directed by %s, released in %d, rated %.1f/10\n", m.title, m.director, m.year, m.rating);
}

int main() {
    // sample movies
    struct movie m1 = {"The Dark Knight", "Christopher Nolan", 2008, 9.0};
    struct movie m2 = {"The Godfather", "Francis Ford Coppola", 1972, 9.2};
    struct movie m3 = {"Forrest Gump", "Robert Zemeckis", 1994, 8.8};
    struct movie m4 = {"Star Wars: Episode IV - A New Hope", "George Lucas", 1977, 8.7};

    // create array of movies
    struct movie movies[4] = {m1, m2, m3, m4};

    // display movies
    printf("MOVIES:\n\n");
    for (int i = 0; i < 4; i++) {
        printMovie(movies[i]);
    }
    printf("\n");

    // get user input for new movie
    char title[50];
    char director[30];
    int year;
    float rating;

    printf("Enter the title of the movie: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter the director of the movie: ");
    fgets(director, 30, stdin);
    director[strcspn(director, "\n")] = '\0';

    printf("Enter the year the movie was released: ");
    scanf("%d", &year);

    printf("Enter your rating for the movie (out of 10): ");
    scanf("%f", &rating);

    // create new movie and add to array
    struct movie newMovie = {title, director, year, rating};
    movies[4] = newMovie;
    printf("\nMovie added successfully!\n");

    // display movies with new addition
    printf("\nUPDATED MOVIES:\n\n");
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
    }

    return 0;
}