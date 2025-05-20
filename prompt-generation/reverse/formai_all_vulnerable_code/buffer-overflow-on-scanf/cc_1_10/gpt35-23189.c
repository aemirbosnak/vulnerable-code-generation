//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

/* Struct for movie information */
typedef struct {
    char title[100];
    char director[50];
    int year;
    float ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

/* Function prototypes */
int display_menu();
void add_movie(Movie *movies, int *num_movies);
void display_movie_info(Movie movie);
void rate_movie(Movie *movie);
float calculate_rating(Movie movie);
void display_top_movies(Movie *movies, int num_movies);
void display_all_movies(Movie *movies, int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;

    /* Main program loop */
    do {
        choice = display_menu();

        switch(choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                display_all_movies(movies, num_movies);
                break;
            case 3:
                display_top_movies(movies, num_movies);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}

/* Function to display the program menu */
int display_menu() {
    int choice;

    printf("\n----- C Movie Rating System -----\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Display top rated movies\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

/* Function to add a new movie to the system */
void add_movie(Movie *movies, int *num_movies) {
    Movie new_movie;

    printf("\nEnter movie title: ");
    scanf(" %[^\n]s", new_movie.title);

    printf("Enter director name: ");
    scanf(" %[^\n]s", new_movie.director);

    printf("Enter year of release: ");
    scanf("%d", &new_movie.year);

    new_movie.num_ratings = 0;

    movies[*num_movies] = new_movie;
    *num_movies += 1;

    printf("\nMovie '%s' added successfully.\n", new_movie.title);
}

/* Function to display information about a movie */
void display_movie_info(Movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);

    if(movie.num_ratings > 0) {
        printf("Rating: %.1f\n", calculate_rating(movie));
    }
    else {
        printf("Rating: Unrated\n");
    }
}

/* Function to allow a user to rate a movie */
void rate_movie(Movie *movie) {
    int rating;

    if(movie->num_ratings == MAX_RATINGS) {
        printf("\nSorry, no more ratings can be added to this movie.\n");
        return;
    }

    printf("\nEnter your rating (1-5): ");
    scanf("%d", &rating);

    if(rating < 1 || rating > 5) {
        printf("\nInvalid rating.\n");
        return;
    }

    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings += 1;

    printf("\nThank you for rating this movie.\n");
}

/* Function to calculate the average rating of a movie */
float calculate_rating(Movie movie) {
    float total_rating = 0;

    for(int i = 0; i < movie.num_ratings; i++) {
        total_rating += movie.ratings[i];
    }

    return total_rating / movie.num_ratings;
}

/* Function to display the top rated movies */
void display_top_movies(Movie *movies, int num_movies) {
    Movie top_movies[MAX_MOVIES];
    int num_top_movies = 0;
    float highest_rating = 0;

    /* Loop through all movies to find the highest rating */
    for(int i = 0; i < num_movies; i++) {
        float movie_rating = calculate_rating(movies[i]);

        if(movie_rating > highest_rating) {
            num_top_movies = 1;
            top_movies[0] = movies[i];
            highest_rating = movie_rating;
        }
        else if(movie_rating == highest_rating) {
            top_movies[num_top_movies] = movies[i];
            num_top_movies += 1;
        }
    }

    /* Display all top rated movies */
    printf("\n--- Top Rated Movies ---\n");
    for(int i = 0; i < num_top_movies; i++) {
        printf("%d. ", i + 1);
        display_movie_info(top_movies[i]);
    }
}

/* Function to display all movies in the system */
void display_all_movies(Movie *movies, int num_movies) {
    printf("\n--- All Movies ---\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%d. ", i + 1);
        display_movie_info(movies[i]);
    }
}