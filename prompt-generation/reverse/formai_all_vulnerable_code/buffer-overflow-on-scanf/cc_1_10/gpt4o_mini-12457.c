//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define MAX_RATINGS 10
#define THRESHOLD 0.5

typedef struct {
    char title[TITLE_LENGTH];
    int ratings[MAX_RATINGS];
    int rating_count;
} Movie;

Movie movie_db[MAX_MOVIES];
int movie_count = 0;

// Function to add a movie
void add_movie(const char* title) {
    if (movie_count < MAX_MOVIES) {
        strncpy(movie_db[movie_count].title, title, TITLE_LENGTH);
        movie_db[movie_count].rating_count = 0;
        movie_count++;
        printf("Movie '%s' added to the database.\n", title);
    } else {
        printf("Movie database is full!\n");
    }
}

// Function to rate a movie
void rate_movie(const char* title, int rating) {
    for (int i = 0; i < movie_count; i++) {
        if (strncmp(movie_db[i].title, title, TITLE_LENGTH) == 0) {
            if (movie_db[i].rating_count < MAX_RATINGS) {
                movie_db[i].ratings[movie_db[i].rating_count] = rating;
                movie_db[i].rating_count++;
                printf("Rated '%s' with %d.\n", title, rating);
            } else {
                printf("Maximum ratings reached for '%s'.\n", title);
            }
            return;
        }
    }
    printf("Movie '%s' not found in the database.\n", title);
}

// Function to calculate average rating
double calculate_average(const Movie* movie) {
    int sum = 0;
    for (int i = 0; i < movie->rating_count; i++) {
        sum += movie->ratings[i];
    }
    return movie->rating_count ? (double)sum / movie->rating_count : 0.0;
}

// Function to display average ratings
void display_ratings() {
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < movie_count; i++) {
        double average = calculate_average(&movie_db[i]);
        printf("Movie: %s | Average Rating: %.2f\n", movie_db[i].title, average);
    }
}

// Function to recommend a movie based on an average rating threshold
void recommend_movies() {
    printf("\nRecommended Movies (Avg Rating > %.2f):\n", THRESHOLD);
    for (int i = 0; i < movie_count; i++) {
        double average = calculate_average(&movie_db[i]);
        if (average > THRESHOLD) {
            printf("- %s\n", movie_db[i].title);
        }
    }
}

int main() {
    int choice;
    char title[TITLE_LENGTH];
    int rating;

    do {
        printf("\n---- Movie Rating System ----\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Ratings\n");
        printf("4. Recommend Movies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                add_movie(title);
                break;
            case 2:
                printf("Enter movie title to rate: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter rating (1-10): ");
                scanf("%d", &rating);
                rate_movie(title, rating);
                break;
            case 3:
                display_ratings();
                break;
            case 4:
                recommend_movies();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}