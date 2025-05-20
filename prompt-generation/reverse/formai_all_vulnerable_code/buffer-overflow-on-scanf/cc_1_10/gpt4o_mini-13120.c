//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie limit reached. Cannot add more movies.\n");
        return;
    }
    Movie new_movie;
    
    printf("Enter movie title: ");
    getchar();  // Consume newline character left in buffer
    fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline
    
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &new_movie.rating);
    
    if (new_movie.rating < 0.0 || new_movie.rating > 10.0) {
        printf("Invalid rating. Rating must be between 0.0 and 10.0.\n");
        return;
    }
    
    movies[movie_count++] = new_movie;
    printf("Movie added successfully!\n");
}

void view_movies() {
    if (movie_count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("Movie List:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d. %s - Rating: %.1f\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void view_highest_rated() {
    if (movie_count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }

    float highest_rating = movies[0].rating;
    char *highest_rated_title = movies[0].title;

    for (int i = 1; i < movie_count; i++) {
        if (movies[i].rating > highest_rating) {
            highest_rating = movies[i].rating;
            highest_rated_title = movies[i].title;
        }
    }

    printf("Highest Rated Movie: %s - Rating: %.1f\n", highest_rated_title, highest_rating);
}

void display_menu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. View Highest Rated Movie\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                view_movies();
                break;
            case 3:
                view_highest_rated();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}