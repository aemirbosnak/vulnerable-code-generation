//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
/* 
 *  The C Movie Rating System
 *  By: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char movie_title[50];
    char director[50];
    int release_year;
    int num_ratings;
    int rating_sum;
    float avg_rating;
} Movie;

int main() {
    int num_movies;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    // Get movie info from user
    for (int i = 0; i < num_movies; i++) {
        printf("\nEnter movie #%d title: ", i+1);
        scanf(" %[^\n]%*c", movies[i].movie_title);

        printf("Enter director name: ");
        scanf(" %[^\n]%*c", movies[i].director);

        printf("Enter release year: ");
        scanf("%d", &movies[i].release_year);

        movies[i].num_ratings = 0;
        movies[i].rating_sum = 0;
        movies[i].avg_rating = 0.0;
    }

    int choice, index, rating;
    do {
        // Display menu options
        printf("\nMovie Rating System Options\n");
        printf("===========================\n");
        printf("1. View all movies\n");
        printf("2. Rate a movie\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // View all movies
                printf("\nAll Movies\n");
                printf("==========\n");
                printf("%-3s%-30s%-20s%-10s%-10s\n", "ID", "Title", "Director", "Year", "Rating");
                for (int i = 0; i < num_movies; i++) {
                    printf("%-3d%-30s%-20s%-10d%-10.2f\n", i+1, movies[i].movie_title, movies[i].director, movies[i].release_year, movies[i].avg_rating);
                }
                break;
            case 2:
                // Rate a movie
                printf("\nEnter movie ID to rate (1-%d): ", num_movies);
                scanf("%d", &index);
                if (index < 1 || index > num_movies) {
                    printf("Invalid movie ID!\n");
                    break;
                }

                printf("Enter your rating (1-5 stars): ");
                scanf("%d", &rating);
                if (rating < 1 || rating > 5) {
                    printf("Invalid rating!\n");
                    break;
                }

                // Update movie rating
                movies[index-1].num_ratings++;
                movies[index-1].rating_sum += rating;
                movies[index-1].avg_rating = (float) movies[index-1].rating_sum / movies[index-1].num_ratings;
                printf("Rating added!\n");
                break;
            case 3:
                // Exit program
                printf("\n...Exiting Movie Rating System...\n");
                break;
            default:
                printf("\nInvalid choice, try again!\n");
        }
    } while (choice != 3);
    return 0;
}