//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int movie_count = 0;
Movie movie_list[MAX_MOVIES];

void add_movie();
void display_movies();
void average_rating();
void search_movie();
void delete_movie();
void sort_movies();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Average Rating\n");
        printf("4. Search Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Sort Movies by Rating\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: add_movie(); break;
            case 2: display_movies(); break;
            case 3: average_rating(); break;
            case 4: search_movie(); break;
            case 5: delete_movie(); break;
            case 6: sort_movies(); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);
}

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie limit reached! Cannot add more movies.\n");
        return;
    }
    
    Movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline
    printf("Enter release year: ");
    scanf("%d", &new_movie.year);
    printf("Enter rating (0-10): ");
    scanf("%f", &new_movie.rating);
    getchar(); // Consume newline
    printf("Enter your review: ");
    fgets(new_movie.review, MAX_REVIEW_LENGTH, stdin);
    new_movie.review[strcspn(new_movie.review, "\n")] = 0; // Remove newline

    movie_list[movie_count++] = new_movie;
    printf("Movie '%s' added successfully!\n", new_movie.title);
}

void display_movies() {
    if (movie_count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\n=== List of Movies ===\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s\n", movie_list[i].title);
        printf("Year: %d\n", movie_list[i].year);
        printf("Rating: %.1f\n", movie_list[i].rating);
        printf("Review: %s\n", movie_list[i].review);
        printf("---------------------\n");
    }
}

void average_rating() {
    if (movie_count == 0) {
        printf("No movies available for rating calculation.\n");
        return;
    }
    
    float total_rating = 0.0;
    for (int i = 0; i < movie_count; i++) {
        total_rating += movie_list[i].rating;
    }
    printf("Average rating of movies: %.2f\n", total_rating / movie_count);
}

void search_movie() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movie_list[i].title, search_title) == 0) {
            printf("Found Movie:\n");
            printf("Title: %s\n", movie_list[i].title);
            printf("Year: %d\n", movie_list[i].year);
            printf("Rating: %.1f\n", movie_list[i].rating);
            printf("Review: %s\n", movie_list[i].review);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie '%s' not found.\n", search_title);
    }
}

void delete_movie() {
    char delete_title[MAX_TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    fgets(delete_title, MAX_TITLE_LENGTH, stdin);
    delete_title[strcspn(delete_title, "\n")] = 0; // Remove newline
    
    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movie_list[i].title, delete_title) == 0) {
            for (int j = i; j < movie_count - 1; j++) {
                movie_list[j] = movie_list[j + 1];  // Shift movies left
            }
            movie_count--;
            printf("Movie '%s' deleted successfully!\n", delete_title);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie '%s' not found for deletion.\n", delete_title);
    }
}

void sort_movies() {
    for (int i = 0; i < movie_count - 1; i++) {
        for (int j = 0; j < movie_count - i - 1; j++) {
            if (movie_list[j].rating > movie_list[j + 1].rating) {
                Movie temp = movie_list[j];
                movie_list[j] = movie_list[j + 1];
                movie_list[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating successfully!\n");
}