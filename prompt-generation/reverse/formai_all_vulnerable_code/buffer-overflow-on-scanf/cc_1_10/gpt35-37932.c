//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Define necessary constants */

#define MAX_MOVIE_COUNT 100
#define HIGHEST_RATING 5
#define RATING_SCALE 10

/* Define necessary structures */

typedef struct movie {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

/* Define necessary functions */

char get_choice();
void add_movie(Movie *movies, int *count);
void display_movies(Movie *movies, int count);
void rate_movie(Movie *movies, int count);
float calculate_average_rating(Movie *movies, int count);

/* Define main function */

int main() {
    Movie movies[MAX_MOVIE_COUNT];
    int count = 0;
    char choice;

    printf("Welcome to the Visionary Movie Rating System\n\n");

    do {
        choice = get_choice();

        switch (choice) {
            case 'a':
                add_movie(movies, &count);
                break;
            case 'b':
                display_movies(movies, count);
                break;
            case 'c':
                rate_movie(movies, count);
                break;
            case 'd':
                printf("Average rating: %.2f\n\n", calculate_average_rating(movies, count));
                break;
            case 'q':
                printf("Thank you for using the Visionary Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }

    } while (choice != 'q');

    return 0;
}

/* Define functions */

char get_choice() {
    char choice;

    printf("Please select an option:\n");
    printf("\ta) Add a movie\n");
    printf("\tb) Display all movies\n");
    printf("\tc) Rate a movie\n");
    printf("\td) Calculate average rating of all movies\n");
    printf("\tq) Quit\n\n");

    printf("Choice: ");
    scanf(" %c", &choice);
    choice = tolower(choice);

    printf("\n");

    return choice;
}

void add_movie(Movie *movies, int *count) {
    if (*count < MAX_MOVIE_COUNT) {
        printf("Adding Movie %d:\n", *count+1);
        printf("\tTitle: ");
        scanf(" %[^\n]s", movies[*count].title);
        printf("\tDirector: ");
        scanf(" %[^\n]s", movies[*count].director);
        printf("\tYear: ");
        scanf(" %d", &movies[*count].year);
        printf("\n");

        (*count)++;
    } else {
        printf("Maximum movie limit reached!\n\n");
    }
}

void display_movies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies added yet!\n\n");
    } else {
        printf("All Movies:\n\n");

        for (int i = 0; i < count; i++) {
            printf("Movie %d:\n", i+1);
            printf("\tTitle: %s\n", movies[i].title);
            printf("\tDirector: %s\n", movies[i].director);
            printf("\tYear: %d\n", movies[i].year);
            printf("\tRating: %.2f\n\n", movies[i].rating);
        }
    }
}

void rate_movie(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies added yet!\n\n");
    } else {
        char title[100];
        printf("Which movie do you want to rate? Enter the movie title:\n");
        scanf(" %[^\n]s", title);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(title, movies[i].title) == 0) {
                found = 1;
                printf("Enter rating (out of %d): ", HIGHEST_RATING);
                scanf(" %f", &movies[i].rating);
                movies[i].rating = (movies[i].rating / HIGHEST_RATING) * RATING_SCALE;
                printf("Rated %s %.2f out of %d\n\n", movies[i].title, movies[i].rating, RATING_SCALE);
                break;
            }
        }

        if (!found) {
            printf("Movie titled '%s' not found!\n\n", title);
        }
    }
}

float calculate_average_rating(Movie *movies, int count) {
    float total_rating = 0;
    float average_rating;

    if (count == 0) {
        printf("No movies added yet!\n\n");
        return 0;
    } else {
        for (int i = 0; i < count; i++) {
            total_rating += movies[i].rating;
        }

        average_rating = total_rating / count;

        return average_rating;
    }
}