//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_TITLE_LENGTH];
    float rating;
} Movie;

Movie movie_database[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie database full. Cannot add more movies.\n");
        return;
    }

    Movie new_movie;

    printf("Enter movie title: ");
    scanf(" %[^\n]", new_movie.title);
    printf("Enter movie director: ");
    scanf(" %[^\n]", new_movie.director);
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &new_movie.rating);

    movie_database[movie_count++] = new_movie;
    printf("Movie added successfully!\n");
}

void display_movies() {
    if (movie_count == 0) {
        printf("No movies in the database.\n");
        return;
    }

    printf("\nMovie Database:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s | Director: %s | Rating: %.1f\n", 
               movie_database[i].title, 
               movie_database[i].director, 
               movie_database[i].rating);
    }
}

void search_movie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movie_database[i].title, title) == 0) {
            printf("Found! Title: %s | Director: %s | Rating: %.1f\n", 
                   movie_database[i].title, 
                   movie_database[i].director, 
                   movie_database[i].rating);
            return;
        }
    }

    printf("Movie not found in the database.\n");
}

void rate_movie() {
    char title[MAX_TITLE_LENGTH];
    float new_rating;
    
    printf("Enter movie title to rate: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movie_database[i].title, title) == 0) {
            printf("Enter new rating (0.0 to 10.0): ");
            scanf("%f", &new_rating);
            movie_database[i].rating = new_rating;
            printf("Rating updated successfully!\n");
            return;
        }
    }

    printf("Movie not found for rating.\n");
}

void menu() {
    int choice;
    do {
        printf("\nMovie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Rate Movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                rate_movie(); 
                break;
            case 5: 
                printf("Exiting program...\n"); 
                break;
            default: 
                printf("Invalid choice. Please try again.\n"); 
                break;
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Movie Rating System!\n");
    menu();
    return 0;
}