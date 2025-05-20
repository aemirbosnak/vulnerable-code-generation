//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Rating between 0-10
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count < MAX_MOVIES) {
        Movie new_movie;
        printf("Enter movie title: ");
        getchar(); // To clear the newline character
        fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
        new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline

        printf("Enter rating (0-10): ");
        scanf("%d", &new_movie.rating);
        if (new_movie.rating < 0 || new_movie.rating > 10) {
            printf("Rating must be between 0 and 10. Try again!\n");
            return;
        }

        movies[movie_count] = new_movie;
        movie_count++;
        printf("Movie '%s' with rating %d added successfully!\n", new_movie.title, new_movie.rating);
    } else {
        printf("Movie list is full! Can't add more movies.\n");
    }
}

void view_movies() {
    if (movie_count == 0) {
        printf("No movies rated yet!\n");
        return;
    }
    
    printf("Rated Movies:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d. %s - Rating: %d\n", i + 1, movies[i].title, movies[i].rating);
    }
}

float calculate_average_rating() {
    if (movie_count == 0) return 0.0;

    int total = 0;
    for (int i = 0; i < movie_count; i++) {
        total += movies[i].rating;
    }
    return (float)total / movie_count;
}

void display_average_rating() {
    float average = calculate_average_rating();
    if (average == 0.0) {
        printf("No ratings available to calculate an average.\n");
    } else {
        printf("Average Rating of Rated Movies: %.2f\n", average);
    }
}

void show_menu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Display Average Rating\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;
    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                view_movies();
                break;
            case 3:
                display_average_rating();
                break;
            case 4:
                printf("Exiting... Enjoy your movies!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}