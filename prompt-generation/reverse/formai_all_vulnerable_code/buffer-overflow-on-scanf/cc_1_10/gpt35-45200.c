//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MOVIES 100

typedef struct {
    char title[50];
    char genre[20];
    int year;
    float rating;
    int num_reviews;
    char reviews[3][100];
} Movie;

Movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    Movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, 50, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = '\0'; // Remove newline from title
    printf("Enter movie genre: ");
    fgets(new_movie.genre, 20, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = '\0'; // Remove newline from genre
    printf("Enter movie year: ");
    if (scanf("%d", &new_movie.year) != 1) {
        printf("Invalid input. Aborting.\n");
        return;
    }
    printf("Enter movie rating: ");
    if (scanf("%f", &new_movie.rating) != 1) {
        printf("Invalid input. Aborting.\n");
        return;
    }
    new_movie.num_reviews = 0;
    movies[num_movies++] = new_movie;
    printf("Movie added successfully.\n");
}

void display_movie(Movie m) {
    printf("Title: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Year: %d\n", m.year);
    printf("Rating: %.1f\n", m.rating);
    printf("Reviews:\n");
    for (int i = 0; i < m.num_reviews; i++) {
        printf("%s\n", m.reviews[i]);
    }
}

void search_movies() {
    char query[50];
    printf("Enter search query: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline from query
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strstr(movies[i].title, query) != NULL) {
            display_movie(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches found.\n");
    }
}

void rate_movie() {
    char title[50];
    printf("Enter movie title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline from title
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter your review (up to 3 lines):\n");
            for (int j = 0; j < 3; j++) {
                fgets(movies[i].reviews[j], 100, stdin);
                movies[i].reviews[j][strcspn(movies[i].reviews[j], "\n")] = '\0'; // Remove newline from review
            }
            movies[i].num_reviews = 3;
            printf("Movie rated successfully.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void display_menu() {
    printf("1. Add movie\n");
    printf("2. Search movies\n");
    printf("3. Rate movie\n");
    printf("4. Exit\n");
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int option;
    do {
        display_menu();
        printf("Enter option: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Aborting.\n");
            return 1;
        }
        clear_input();
        switch (option) {
            case 1:
                add_movie();
                break;
            case 2:
                search_movies();
                break;
            case 3:
                rate_movie();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);
    return 0;
}