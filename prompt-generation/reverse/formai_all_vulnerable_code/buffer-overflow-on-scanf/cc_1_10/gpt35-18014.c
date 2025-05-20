//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>

#define MAX_MOVIES 10

// Define the movie struct
struct movie {
    char title[50];
    int rating;
};

// Define the rating system struct
struct rating_system {
    char description[20];
    int min_rating;
    int max_rating;
};

// Define the rating systems
struct rating_system movie_rating = {"Movie Rating", 1, 10};
struct rating_system five_star_rating = {"Five Star Rating", 1, 5};
struct rating_system like_dislike_rating = {"Like/Dislike Rating", 0, 1};

// Define the movies array
struct movie movies[MAX_MOVIES];

// Define the function to display the movies
void display_movies(struct movie movies[], int num_movies, struct rating_system rating_system) {
    int i;

    printf("%s\n", rating_system.description);
    for (i = 0; i < num_movies; i++) {
        printf("%d. %s - %d\n", i + 1, movies[i].title, movies[i].rating);
    }
}

int main() {
    int num_movies, i, choice, rating;
    char title[50];

    printf("Welcome to the Movie Rating System!\n");
    printf("Enter the number of movies to rate (max %d): ", MAX_MOVIES);
    scanf("%d", &num_movies);

    // Loop through each movie and get the user's rating
    for (i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);

        // Display the different rating systems and get the user's choice
        printf("Choose a rating system:\n");
        printf("1. %s\n", movie_rating.description);
        printf("2. %s\n", five_star_rating.description);
        printf("3. %s\n", like_dislike_rating.description);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Get the user's rating based on their choice of rating system
        switch (choice) {
            case 1:
                printf("Enter your rating for %s (%d-%d): ", movies[i].title, movie_rating.min_rating, movie_rating.max_rating);
                scanf("%d", &rating);

                // Check if the rating is within the allowed range for the rating system
                if (rating < movie_rating.min_rating || rating > movie_rating.max_rating) {
                    printf("Rating must be between %d and %d\n", movie_rating.min_rating, movie_rating.max_rating);
                    i--;
                    continue;
                }

                movies[i].rating = rating;
                break;

            case 2:
                printf("Enter your rating for %s (%d-%d): ", movies[i].title, five_star_rating.min_rating, five_star_rating.max_rating);
                scanf("%d", &rating);

                // Check if the rating is within the allowed range for the rating system
                if (rating < five_star_rating.min_rating || rating > five_star_rating.max_rating) {
                    printf("Rating must be between %d and %d\n", five_star_rating.min_rating, five_star_rating.max_rating);
                    i--;
                    continue;
                }

                movies[i].rating = rating * 2;
                break;

            case 3:
                printf("Enter your rating for %s (like=1/dislike=0): ", movies[i].title);
                scanf("%d", &rating);

                // Check if the rating is within the allowed range for the rating system
                if (rating < like_dislike_rating.min_rating || rating > like_dislike_rating.max_rating) {
                    printf("Rating must be either 0 or 1\n");
                    i--;
                    continue;
                }

                movies[i].rating = rating;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                i--;
                continue;
        }
    }

    // Display the movies and their ratings
    display_movies(movies, num_movies, movie_rating);

    return 0;
}