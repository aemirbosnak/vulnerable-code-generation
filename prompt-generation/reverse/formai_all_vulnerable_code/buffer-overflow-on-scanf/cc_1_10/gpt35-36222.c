//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    char genre[20];
    int rating;
};

void add_movie(struct movie *m);
void display_movies(struct movie *movies, int count);
void rate_movie(struct movie *movies, int count);
void sort_movies(struct movie *movies, int count);

int main() {
    int choice, count = 0, capacity = 1;
    struct movie *movies = (struct movie *) calloc(capacity, sizeof(struct movie));

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add movie\n");
        printf("2. Display movies\n");
        printf("3. Rate movie\n");
        printf("4. Sort movies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count == capacity) {
                    capacity *= 2;
                    movies = (struct movie *) realloc(movies, capacity * sizeof(struct movie));
                    if (movies == NULL) {
                        printf("Memory allocation failed\n");
                        exit(1);
                    }
                }
                add_movie(&movies[count++]);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                rate_movie(movies, count);
                break;
            case 4:
                sort_movies(movies, count);
                break;
            case 5:
                free(movies);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
}

void add_movie(struct movie *m) {
    printf("Enter movie title: ");
    scanf(" %[^\n]s", m->title);
    printf("Enter movie genre: ");
    scanf(" %[^\n]s", m->genre);
    printf("Enter movie rating (1-10): ");
    scanf("%d", &m->rating);
}

void display_movies(struct movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display\n");
    } else {
        printf("Movie List:\n");
        printf("----------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%s (%s) [%d/10]\n", movies[i].title, movies[i].genre, movies[i].rating);
        }
        printf("----------------------------------\n");
    }
}

void rate_movie(struct movie *movies, int count) {
    if (count == 0) {
        printf("No movies to rate\n");
    } else {
        char title[50];
        printf("Enter movie title to rate: ");
        scanf(" %[^\n]s", title);
        for (int i = 0; i < count; i++) {
            if (strcmp(title, movies[i].title) == 0) {
                printf("Enter rating for %s (%s): ", movies[i].title, movies[i].genre);
                scanf("%d", &movies[i].rating);
                printf("Rating updated!\n");
                return;
            }
        }
        printf("Movie not found\n");
    }
}

void sort_movies(struct movie *movies, int count) {
    if (count == 0) {
        printf("No movies to sort\n");
    } else {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(movies[i].title, movies[j].title) > 0) {
                    struct movie temp = movies[i];
                    movies[i] = movies[j];
                    movies[j] = temp;
                }
            }
        }
        printf("Movies sorted!\n");
    }
}