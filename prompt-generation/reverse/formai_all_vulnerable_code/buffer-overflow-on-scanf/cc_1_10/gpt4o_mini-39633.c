//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
} Movie;

Movie movie_database[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie Database is full! Can't add more movies.\n");
        return;
    }
    Movie new_movie;
    printf("Enter movie title: ");
    getchar();  // To consume the newline
    fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter movie genre: ");
    fgets(new_movie.genre, MAX_GENRE_LENGTH, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = '\0'; // Remove trailing newline

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &new_movie.rating);
    
    if (new_movie.rating < 0.0 || new_movie.rating > 10.0) {
        printf("Invalid rating! Rating must be between 0.0 and 10.0.\n");
        return;
    }
    
    movie_database[movie_count++] = new_movie;
    printf("Movie added successfully!\n");
}

void view_movies() {
    if (movie_count == 0) {
        printf("No movies in the database!\n");
        return;
    }
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s | Genre: %s | Rating: %.1f\n", 
               movie_database[i].title, 
               movie_database[i].genre, 
               movie_database[i].rating);
    }
    printf("-------------------\n");
}

void search_movie() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // To consume the newline
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movie_database[i].title, search_title) == 0) {
            printf("Found!\nTitle: %s | Genre: %s | Rating: %.1f\n",
                   movie_database[i].title, 
                   movie_database[i].genre, 
                   movie_database[i].rating);
            return;
        }
    }
    printf("Movie not found in the database.\n");
}

void delete_movie() {
    char delete_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // To consume the newline
    fgets(delete_title, MAX_TITLE_LENGTH, stdin);
    delete_title[strcspn(delete_title, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movie_database[i].title, delete_title) == 0) {
            for (int j = i; j < movie_count - 1; j++) {
                movie_database[j] = movie_database[j + 1]; // Shift movies left
            }
            movie_count--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found! Nothing to delete.\n");
}

void display_menu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View All Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                view_movies();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                delete_movie();
                break;
            case 5:
                printf("Exiting the Movie Rating System. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}