//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float ratings[MAX_MOVIES];
    int rating_count;
} Movie;

void addMovie(Movie *movies, int *movie_count) {
    if (*movie_count >= MAX_MOVIES) {
        printf("Whoa! That's too many movies already!\n");
        return;
    }
    
    Movie new_movie;
    printf("Enter the name of the movie: ");
    scanf(" %[^\n]", new_movie.name);
    new_movie.rating_count = 0;

    movies[*movie_count] = new_movie;
    (*movie_count)++;
    printf("Movie '%s' added successfully!\n", new_movie.name);
}

void rateMovie(Movie *movies, int movie_count) {
    char movie_name[NAME_LENGTH];
    float rating;

    printf("Enter the name of the movie you want to rate: ");
    scanf(" %[^\n]", movie_name);

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].name, movie_name) == 0) {
            printf("Enter your rating (0 to 10): ");
            scanf("%f", &rating);
            if (rating < 0 || rating > 10) {
                printf("Invalid rating! Please rate between 0 and 10.\n");
                return;
            }
            movies[i].ratings[movies[i].rating_count] = rating;
            movies[i].rating_count++;
            printf("Thank you! Your rating of %.2f for '%s' has been saved!\n", rating, movies[i].name);
            return;
        }
    }
    
    printf("Oops! Movie '%s' not found in our collection.\n", movie_name);
}

void displayRatings(Movie *movies, int movie_count) {
    printf("\n***** Movie Ratings *****\n");
    for (int i = 0; i < movie_count; i++) {
        float total = 0;
        for (int j = 0; j < movies[i].rating_count; j++) {
            total += movies[i].ratings[j];
        }
        float average = (movies[i].rating_count > 0) ? (total / movies[i].rating_count) : 0;
        printf("Movie: '%s' - Average Rating: %.2f (%d ratings)\n", movies[i].name, average, movies[i].rating_count);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_count = 0;
    int choice;

    while (1) {
        printf("\nWelcome to the Movie Rating System!\n");
        printf("1. Add a Movie\n");
        printf("2. Rate a Movie\n");
        printf("3. Display All Ratings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movie_count);
                break;
            case 2:
                rateMovie(movies, movie_count);
                break;
            case 3:
                displayRatings(movies, movie_count);
                break;
            case 4:
                printf("Thank you for using the Movie Rating System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}