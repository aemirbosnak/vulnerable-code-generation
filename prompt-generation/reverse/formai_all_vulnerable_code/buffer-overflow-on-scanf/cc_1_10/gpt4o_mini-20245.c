//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 5
#define MAX_TITLE 50
#define MAX_RATINGS 10

typedef struct {
    char title[MAX_TITLE];
    int ratings[MAX_RATINGS];
    int rating_count;
} Movie;

void printShape(char *str) {
    int num = strlen(str);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    for (int i = num-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayMovies(Movie movies[], int count) {
    printf("\n=== Movie Ratings ===\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Ratings: ");
        if (movies[i].rating_count == 0) {
            printf("No ratings yet.\n");
        } else {
            for (int j = 0; j < movies[i].rating_count; j++) {
                printf("%d ", movies[i].ratings[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

float calculateAverageRating(Movie movie) {
    if (movie.rating_count == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < movie.rating_count; i++) {
        sum += movie.ratings[i];
    }
    return sum / (float)movie.rating_count;
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_count = 0;

    printf("Welcome to the Shape-Shifting Movie Rating System!\n\n");

    while (1) {
        printf("1. Add Movie\n2. Rate Movie\n3. Display Movies\n4. Calculate Average Rating\n5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (movie_count >= MAX_MOVIES) {
                    printf("Maximum number of movies reached.\n");
                    break;
                }
                printf("Enter movie title: ");
                scanf(" %[^\n]", movies[movie_count].title);
                movies[movie_count].rating_count = 0;
                movie_count++;
                printf("Movie added.\n");
                break;

            case 2:
                {
                    printf("Select a movie to rate (0 to %d): ", movie_count - 1);
                    int idx;
                    scanf("%d", &idx);
                    if (idx < 0 || idx >= movie_count) {
                        printf("Invalid movie index.\n");
                        break;
                    }
                    if (movies[idx].rating_count >= MAX_RATINGS) {
                        printf("Maximum ratings reached for this movie.\n");
                        break;
                    }
                    int rating;
                    printf("Enter your rating (1-5): ");
                    scanf("%d", &rating);
                    if (rating < 1 || rating > 5) {
                        printf("Invalid rating. Please give a rating between 1 and 5.\n");
                        break;
                    }
                    movies[idx].ratings[movies[idx].rating_count] = rating;
                    movies[idx].rating_count++;
                    printf("Rating added.\n");
                    // Display shape shift
                    printShape(movies[idx].title);
                }
                break;

            case 3:
                displayMovies(movies, movie_count);
                break;

            case 4:
                {
                    printf("Select a movie to calculate average rating (0 to %d): ", movie_count - 1);
                    int idx;
                    scanf("%d", &idx);
                    if (idx < 0 || idx >= movie_count) {
                        printf("Invalid movie index.\n");
                        break;
                    }
                    float avg = calculateAverageRating(movies[idx]);
                    if (avg == 0.0) {
                        printf("No ratings available for %s.\n", movies[idx].title);
                    } else {
                        printf("Average rating for %s: %.2f\n", movies[idx].title, avg);
                    }
                }
                break;

            case 5:
                printf("Thank you for using the Shape-Shifting Movie Rating System! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}