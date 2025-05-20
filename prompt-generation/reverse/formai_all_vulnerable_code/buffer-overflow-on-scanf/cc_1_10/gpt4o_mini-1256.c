//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char genre[TITLE_LENGTH];
    float rating;
} Movie;

void add_movie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full! Can't add more movies.\n");
        return;
    }
    Movie new_movie;
    printf("Enter Movie Title: ");
    getchar(); // Consume newline character from previous input
    fgets(new_movie.title, TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline

    printf("Enter Movie Genre: ");
    fgets(new_movie.genre, TITLE_LENGTH, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = 0; // Remove newline

    printf("Enter Movie Rating (0.0 to 10.0): ");
    scanf("%f", &new_movie.rating);
    if (new_movie.rating < 0.0 || new_movie.rating > 10.0) {
        printf("Invalid rating! Rating must be between 0.0 and 10.0.\n");
        return;
    }

    movies[*count] = new_movie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void display_movies(Movie movies[], int count) {
    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Genre: %s, Rating: %.1f\n", i + 1, movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void find_highest_rating(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }

    float max_rating = 0.0;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (movies[i].rating > max_rating) {
            max_rating = movies[i].rating;
            index = i;
        }
    }
    printf("Highest Rated Movie: %s | Genre: %s | Rating: %.1f\n", movies[index].title, movies[index].genre, movies[index].rating);
}

void find_lowest_rating(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }

    float min_rating = 10.0;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (movies[i].rating < min_rating) {
            min_rating = movies[i].rating;
            index = i;
        }
    }
    printf("Lowest Rated Movie: %s | Genre: %s | Rating: %.1f\n", movies[index].title, movies[index].genre, movies[index].rating);
}

void search_movie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to search.\n");
        return;
    }

    char search_title[TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Consume newline character from previous input
    fgets(search_title, TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, search_title) == 0) {
            printf("Movie Found: %s | Genre: %s | Rating: %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Movie with title \"%s\" not found.\n", search_title);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Find Highest Rated Movie\n");
        printf("4. Find Lowest Rated Movie\n");
        printf("5. Search Movie\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                find_highest_rating(movies, count);
                break;
            case 4:
                find_lowest_rating(movies, count);
                break;
            case 5:
                search_movie(movies, count);
                break;
            case 6:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}