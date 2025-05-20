//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char genre[30];
} Movie;

int movie_count = 0;
Movie movies[MAX_MOVIES];

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[movie_count].title);
    printf("Enter movie genre: ");
    scanf(" %[^\n]", movies[movie_count].genre);
    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movies[movie_count].rating);

    // Validation
    if (movies[movie_count].rating < 0.0 || movies[movie_count].rating > 10.0) {
        printf("Invalid rating! Please enter between 0.0 and 10.0\n");
        return;
    }

    movie_count++;
    printf("Movie \"%s\" added successfully!\n", movies[movie_count - 1].title);
}

void display_movies() {
    if (movie_count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s, Genre: %s, Rating: %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void search_movie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Movie found: Title: %s, Genre: %s, Rating: %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void delete_movie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            for (int j = i; j < movie_count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            movie_count--;
            printf("Movie \"%s\" deleted successfully!\n", title);
            return;
        }
    }
    printf("Movie not found.\n");
}

void update_rating() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to update rating: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Current Rating: %.1f. Enter new rating (0.0 - 10.0): ", movies[i].rating);
            float new_rating;
            scanf("%f", &new_rating);

            // Validation
            if (new_rating < 0.0 || new_rating > 10.0) {
                printf("Invalid rating! Please enter between 0.0 and 10.0\n");
                return;
            }

            movies[i].rating = new_rating;
            printf("Rating updated for \"%s\" to %.1f\n", title, new_rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void menu() {
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Update Movie Rating\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                delete_movie();
                break;
            case 5:
                update_rating();
                break;
            case 0:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}