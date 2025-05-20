//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    int rating; // Rating from 1 to 5
    char review[REVIEW_LENGTH];
} Movie;

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void display_menu() {
    printf("\n**** Welcome to the Movie Rating System ****\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Search Movie by Title\n");
    printf("4. Rate a Movie\n");
    printf("5. Exit\n");
    printf("********************************************\n");
}

void add_movie(Movie *movies, int *movie_count) {
    if (*movie_count >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }
    
    Movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline

    new_movie.rating = 0; // Default rating
    strcpy(new_movie.review, "No review available");

    movies[*movie_count] = new_movie;
    (*movie_count)++;
    printf("Movie '%s' added successfully!\n", new_movie.title);
}

void view_movies(const Movie *movies, int movie_count) {
    if (movie_count == 0) {
        printf("No movies to display!\n");
        return;
    }
    
    printf("\n**** Movies List ****\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void search_movie(const Movie *movies, int movie_count) {
    if (movie_count == 0) {
        printf("No movies available for search!\n");
        return;
    }

    char search_title[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(search_title, TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movies[i].title, search_title) == 0) {
            printf("Movie found!\n");
            printf("Title: %s\n", movies[i].title);
            printf("Rating: %d\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No movie found with the title '%s'!\n", search_title);
    }
}

void rate_movie(Movie *movies, int movie_count) {
    if (movie_count == 0) {
        printf("No movies available to rate!\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Current Rating for '%s': %d\n", movies[i].title, movies[i].rating);
            int new_rating;

            do {
                printf("Enter new rating (1-5): ");
                scanf("%d", &new_rating);
                clear_input_buffer();
            } while (new_rating < 1 || new_rating > 5);

            movies[i].rating = new_rating;
            printf("Rating updated for '%s' to %d!\n", movies[i].title, new_rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No movie found with the title '%s'!\n", title);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_movie(movies, &movie_count);
                break;
            case 2:
                view_movies(movies, movie_count);
                break;
            case 3:
                search_movie(movies, movie_count);
                break;
            case 4:
                rate_movie(movies, movie_count);
                break;
            case 5:
                printf("Thanks for using the Movie Rating System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}