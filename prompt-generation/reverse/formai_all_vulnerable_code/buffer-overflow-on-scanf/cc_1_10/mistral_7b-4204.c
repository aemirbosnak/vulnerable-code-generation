//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Movie {
    char title[100];
    float rating;
    int num_ratings;
} Movie;

void read_movie(Movie *m) {
    printf("Enter movie title: ");
    scanf("%s", m->title);
    printf("Enter movie rating: ");
    scanf("%f", &m->rating);
    printf("Enter number of ratings: ");
    scanf("%d", &m->num_ratings);
}

void print_movie(Movie m) {
    printf("\nTitle: %s", m.title);
    printf("\nRating: %.2f", m.rating);
    printf("\nNumber of Ratings: %d\n", m.num_ratings);
}

void calculate_average_rating(Movie *m) {
    if (m->num_ratings > 0) {
        m->rating = m->rating / m->num_ratings;
    } else {
        m->rating = 0.0;
    }
}

void print_menu() {
    printf("\nMovie Rating System Menu:\n");
    printf("1. Add Movie\n");
    printf("2. Print Movie\n");
    printf("3. Calculate Average Rating\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    int num_movies = 0;
    Movie movies[100];
    Movie selected_movie;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_movies < 100) {
                    read_movie(&movies[num_movies]);
                    num_movies++;
                } else {
                    printf("Movie limit reached.\n");
                }
                break;

            case 2:
                if (num_movies > 0) {
                    printf("Select movie index: ");
                    scanf("%d", &choice);
                    selected_movie = movies[choice];
                    print_movie(selected_movie);
                } else {
                    printf("No movies to display.\n");
                }
                break;

            case 3:
                if (num_movies > 0) {
                    printf("Select movie index: ");
                    scanf("%d", &choice);
                    selected_movie = movies[choice];
                    calculate_average_rating(&selected_movie);
                    print_movie(selected_movie);
                } else {
                    printf("No movies to display.\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}