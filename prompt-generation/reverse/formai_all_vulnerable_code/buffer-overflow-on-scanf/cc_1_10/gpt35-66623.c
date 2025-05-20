//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing movie information
struct movie {
    char title[100];
    char director[50];
    char genre[20];
    int year;
    float rating;
};

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Allocate memory for movie array
    struct movie* movies = (struct movie*) malloc(num_movies * sizeof(struct movie));

    // Input movie information
    for(int i=0; i<num_movies; i++) {
        printf("\nEnter details for movie %d\n", i+1);
        printf("Title: ");
        scanf("%s", (movies+i)->title);
        printf("Director: ");
        scanf("%s", (movies+i)->director);
        printf("Genre: ");
        scanf("%s", (movies+i)->genre);
        printf("Year: ");
        scanf("%d", &(movies+i)->year);
        printf("Rating: ");
        scanf("%f", &(movies+i)->rating);
    }

    // Display movie information
    printf("\nMovie Ratings\n");
    printf("------------------------------------------------------\n");
    printf("Title\t\tDirector\tGenre\t\tYear\tRating\n");
    printf("------------------------------------------------------\n");
    for(int i=0; i<num_movies; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t%.1f\n", (movies+i)->title,\
        (movies+i)->director, (movies+i)->genre, (movies+i)->year, (movies+i)->rating);
    }

    // Calculate average rating
    float sum_rating = 0.0, avg_rating;
    for(int i=0; i<num_movies; i++) {
        sum_rating += (movies+i)->rating;
    }
    avg_rating = sum_rating / num_movies;

    // Display average rating
    printf("\nAverage Movie Rating: %.1f\n", avg_rating);

    // Check rating category
    for(int i=0; i<num_movies; i++) {
        char rating_category[20];
        if((movies+i)->rating>=8.0) {
            strcpy(rating_category, "Excellent");
        } else if((movies+i)->rating>=6.0) {
            strcpy(rating_category, "Good");
        } else if((movies+i)->rating>=4.0) {
            strcpy(rating_category, "Average");
        } else {
            strcpy(rating_category, "Poor");
        }
        printf("Movie %d Rating Category: %s\n", i+1, rating_category);
    }

    // Free allocated memory
    free(movies);

    return 0;
}