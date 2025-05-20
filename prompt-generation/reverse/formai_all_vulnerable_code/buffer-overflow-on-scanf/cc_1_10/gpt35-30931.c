//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

struct movie {
    char title[50];
    int num_ratings;
    double ratings[MAX_RATINGS];
};

int num_movies;
struct movie movies[MAX_MOVIES];

void print_menu() {
    printf("Movie Rating System\n");
    printf("1. Enter Movie\n");
    printf("2. Enter Rating\n");
    printf("3. Print Movie Ratings\n");
    printf("4. Print Movie Statistics\n");
    printf("5. Quit\n");
    printf("Enter choice: ");
}

void enter_movie() {
    if (num_movies >= MAX_MOVIES) {
        printf("Error: too many movies\n");
        return;
    }
    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);
    movies[num_movies].num_ratings = 0;
    num_movies++;
}

void enter_rating() {
    if (num_movies == 0) {
        printf("Error: no movies entered\n");
        return;
    }
    printf("Enter movie title: ");
    char title[50];
    scanf("%s", title);
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(title, movies[i].title) == 0) {
            break;
        }
    }
    if (i == num_movies) {
        printf("Error: movie not found\n");
        return;
    }
    if (movies[i].num_ratings >= MAX_RATINGS) {
        printf("Error: too many ratings for movie\n");
        return;
    }
    printf("Enter rating (0-10): ");
    double rating;
    scanf("%lf", &rating);
    if (rating < 0 || rating > 10) {
        printf("Error: rating must be between 0 and 10\n");
        return;
    }
    movies[i].ratings[movies[i].num_ratings] = rating;
    movies[i].num_ratings++;
}

void print_movie_ratings() {
    if (num_movies == 0) {
        printf("Error: no movies entered\n");
        return;
    }
    printf("Movie Ratings\n");
    int i, j;
    for (i = 0; i < num_movies; i++) {
        printf("%s: ", movies[i].title);
        if (movies[i].num_ratings == 0) {
            printf("No ratings\n");
        } else {
            for (j = 0; j < movies[i].num_ratings; j++) {
                printf("%.1lf ", movies[i].ratings[j]);
            }
            printf("\n");
        }
    }
}

void print_movie_statistics() {
    if (num_movies == 0) {
        printf("Error: no movies entered\n");
        return;
    }
    printf("Movie Statistics\n");
    int i, j;
    for (i = 0; i < num_movies; i++) {
        printf("%s:\n", movies[i].title);
        if (movies[i].num_ratings == 0) {
            printf("No ratings\n");
        } else {
            double sum = 0;
            for (j = 0; j < movies[i].num_ratings; j++) {
                sum += movies[i].ratings[j];
            }
            double mean = sum / movies[i].num_ratings;
            double var = 0;
            for (j = 0; j < movies[i].num_ratings; j++) {
                var += pow(movies[i].ratings[j] - mean, 2);
            }
            var /= movies[i].num_ratings;
            double sd = sqrt(var);
            printf("Mean Rating: %.1lf\n", mean);
            printf("Standard Deviation: %.1lf\n", sd);
        }
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enter_movie();
                break;
            case 2:
                enter_rating();
                break;
            case 3:
                print_movie_ratings();
                break;
            case 4:
                print_movie_statistics();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;
}