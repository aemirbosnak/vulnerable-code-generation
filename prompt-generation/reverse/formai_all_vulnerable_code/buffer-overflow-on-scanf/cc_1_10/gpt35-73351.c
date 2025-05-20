//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a movie entry
typedef struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
} movie;

// Function to read in movie information from user input
void read_movie(movie *m) {
    printf("Enter movie title: ");
    fgets(m->title, 50, stdin);
    printf("Enter movie director: ");
    fgets(m->director, 50, stdin);
    printf("Enter movie release year: ");
    scanf("%d", &(m->year));
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &(m->rating));
    getchar(); // Clear newline character from buffer
}

// Function to print out a movie entry
void print_movie(movie *m) {
    printf("%s, directed by %s, released in %d, rated %.1f/10\n", m->title, m->director, m->year, m->rating);
}

// Function to compare two movies based on their rating
int compare_rating(const void *a, const void *b) {
    movie *movieA = (movie *)a;
    movie *movieB = (movie *)b;
    if (movieA->rating < movieB->rating) {
        return 1;
    } else if (movieA->rating > movieB->rating) {
        return -1;
    } else {
        return 0;
    }
}

// Function to compare two movies based on their year of release
int compare_year(const void *a, const void *b) {
    movie *movieA = (movie *)a;
    movie *movieB = (movie *)b;
    if (movieA->year > movieB->year) {
        return 1;
    } else if (movieA->year < movieB->year) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int num_movies = 0;
    int max_movies = 10;
    movie *movies = (movie *)malloc(sizeof(movie) * max_movies);

    printf("Welcome to the C Movie Rating System!\n");

    while (1) {
        // Display options to user
        printf("\nPlease choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. View all movies sorted by rating\n");
        printf("3. View all movies sorted by year of release\n");
        printf("4. Exit\n");

        // Read in user choice
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                // Check if we need to expand movie array
                if (num_movies == max_movies) {
                    max_movies *= 2;
                    movies = (movie *)realloc(movies, sizeof(movie) * max_movies);
                }

                // Read in new movie and add to array
                printf("\nAdding a new movie:\n");
                read_movie(&movies[num_movies]);
                num_movies++;
                break;
            case 2:
                // Sort movies by rating and print
                qsort(movies, num_movies, sizeof(movie), compare_rating);
                printf("\nAll movies sorted by rating:\n");
                for (int i = 0; i < num_movies; i++) {
                    print_movie(&movies[i]);
                }
                break;
            case 3:
                // Sort movies by year and print
                qsort(movies, num_movies, sizeof(movie), compare_year);
                printf("\nAll movies sorted by year of release:\n");
                for (int i = 0; i < num_movies; i++) {
                    print_movie(&movies[i]);
                }
                break;
            case 4:
                // Free memory and exit program
                free(movies);
                printf("\nThank you for using the C Movie Rating System!\n");
                return 0;
            default:
                // Invalid choice
                printf("\nInvalid choice! Please enter a number from 1 to 4.\n");
                break;
        }
    }
}