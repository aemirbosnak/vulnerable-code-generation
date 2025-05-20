//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define MAX_MOVIES 100

typedef struct Movie {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

int num_movies = 0;
Movie movie_list[MAX_MOVIES];

void add_movie() {
    Movie m;
    printf("Enter movie title: ");
    scanf("%s", m.title);
    printf("Enter director name: ");
    scanf("%s", m.director);
    printf("Enter year of release: ");
    scanf("%d", &m.year);
    printf("Enter rating out of 10: ");
    scanf("%f", &m.rating);
    movie_list[num_movies++] = m;
    printf("Movie added successfully.\n");
}

void print_movie_list() {
    if (num_movies == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("%-25s%-25s%-10s%-10s\n", "Title", "Director", "Year", "Rating");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%-25s%-25s%-10d%-10.2f\n", movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
    }
}

void search_movie() {
    char search_title[100];
    printf("Enter movie title to search: ");
    scanf("%s", search_title);
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(search_title, movie_list[i].title) == 0) {
            printf("%-25s%-25s%-10s%-10s\n", "Title", "Director", "Year", "Rating");
            printf("----------------------------------------------------------\n");
            printf("%-25s%-25s%-10d%-10.2f\n", movie_list[i].title, movie_list[i].director, movie_list[i].year, movie_list[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

void rate_movie() {
    char search_title[100];
    printf("Enter movie title to rate: ");
    scanf("%s", search_title);
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(search_title, movie_list[i].title) == 0) {
            printf("Enter rating out of 10: ");
            scanf("%f", &movie_list[i].rating);
            printf("Rating updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add movie\n");
        printf("2. Print movie list\n");
        printf("3. Search for a movie\n");
        printf("4. Rate a movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                print_movie_list();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                rate_movie();
                break;
            case 5:
                printf("Thank you for using the movie rating system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}