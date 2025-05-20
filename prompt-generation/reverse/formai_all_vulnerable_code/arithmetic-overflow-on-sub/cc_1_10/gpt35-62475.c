//FormAI DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs for movies and their ratings
struct movie {
    char title[100];
    char director[50];
    int year;
    char genre[20];
    float rating;
};

struct rating {
    char reviewer[50];
    float score;
};

// Function prototypes
void add_movie(struct movie* movies, int count);
void rate_movie(struct movie* movies, int count);
void display_movies(struct movie* movies, int count);
void display_ratings(struct movie* movies, int count);

int main(void) {
    struct movie movies[10];    // Array of 10 movies
    int count = 0;

    while (1) {
        printf("What would you like to do?\n");
        printf("[1] Add a movie\n");
        printf("[2] Rate a movie\n");
        printf("[3] Display all movies\n");
        printf("[4] Display movie ratings\n");
        printf("[5] Quit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie(movies, count);
                count++;
                break;
            case 2:
                rate_movie(movies, count);
                break;
            case 3:
                display_movies(movies, count);
                break;
            case 4:
                display_ratings(movies, count);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to add a movie
void add_movie(struct movie* movies, int count) {
    struct movie m;

    printf("Enter the movie title: ");
    fgets(m.title, sizeof(m.title), stdin);
    m.title[strcspn(m.title, "\n")] = '\0';

    printf("Enter the movie director: ");
    fgets(m.director, sizeof(m.director), stdin);
    m.director[strcspn(m.director, "\n")] = '\0';

    printf("Enter the movie year: ");
    scanf("%d", &m.year);

    printf("Enter the movie genre: ");
    fgets(m.genre, sizeof(m.genre), stdin);
    m.genre[strcspn(m.genre, "\n")] = '\0';

    printf("Movie added!\n");
    movies[count] = m;
}

// Function to rate a movie
void rate_movie(struct movie* movies, int count) {
    printf("Which movie would you like to rate?\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i + 1, movies[i].title);
    }

    int choice;
    scanf("%d", &choice);
    choice--;

    struct rating r;
    printf("Enter your name: ");
    fgets(r.reviewer, sizeof(r.reviewer), stdin);
    r.reviewer[strcspn(r.reviewer, "\n")] = '\0';

    printf("Enter your rating (0-10): ");
    scanf("%f", &r.score);

    movies[choice].rating += r.score;
    movies[choice].rating /= 2;

    printf("Rating added!\n");
}

// Function to display all movies
void display_movies(struct movie* movies, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%d) - %s, %s\n", movies[i].title, movies[i].year, movies[i].director, movies[i].genre);
    }
}

// Function to display movie ratings
void display_ratings(struct movie* movies, int count) {
    printf("Which movie would you like to see the ratings of?\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i + 1, movies[i].title);
    }

    int choice;
    scanf("%d", &choice);
    choice--;

    printf("Ratings for %s:\n", movies[choice].title);
    printf("IMDb: %.1f\n", movies[choice].rating);
}