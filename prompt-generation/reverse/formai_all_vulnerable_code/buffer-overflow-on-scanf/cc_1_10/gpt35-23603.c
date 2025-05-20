//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char name[50];
    int rating;
} Movie;

int total_movies = 0;
Movie movie_list[MAX_MOVIES];

void print_menu();
void add_movie();
void view_movies();
void rate_movie();
void get_movie_index(char movie_name[], int *index);

int main() {
    int choice;
    while (1) {
        print_menu();
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
                rate_movie();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

void print_menu() {
    printf("\n***** C Movie Rating System *****\n");
    printf("1. Add movie\n");
    printf("2. View movies\n");
    printf("3. Rate movie\n");
    printf("4. Exit\n");
}

void add_movie() {
    char movie_name[50];
    printf("Enter movie name: ");
    scanf("%s", movie_name);
    for (int i = 0; i < total_movies; i++) {
        if (strcmp(movie_name, movie_list[i].name) == 0) {
            printf("Movie already added.\n");
            return;
        }
    }
    if (total_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }
    strcpy(movie_list[total_movies].name, movie_name);
    total_movies++;
    printf("Movie added.\n");
}

void view_movies() {
    if (total_movies == 0) {
        printf("No movies added yet.\n");
        return;
    }
    printf("\nMovie List:\n");
    printf("---------------\n");
    for (int i = 0; i < total_movies; i++) {
        printf("%d. %s\n", i+1, movie_list[i].name);
    }
}

void rate_movie() {
    if (total_movies == 0) {
        printf("No movies added yet.\n");
        return;
    }
    char movie_name[50];
    int index;
    printf("Enter movie name to rate: ");
    scanf("%s", movie_name);
    get_movie_index(movie_name, &index);
    if (index == -1) {
        printf("Movie not found.\n");
        return;
    }
    int rating;
    printf("Enter rating (out of 10) for %s: ", movie_name);
    scanf("%d", &rating);
    if (rating < 0 || rating > 10) {
        printf("Invalid rating.\n");
        return;
    }
    movie_list[index].rating = rating;
    printf("Rating for %s has been updated.\n", movie_name);
}

void get_movie_index(char movie_name[], int *index) {
    *index = -1;
    for (int i = 0; i < total_movies; i++) {
        if (strcmp(movie_name, movie_list[i].name) == 0) {
            *index = i;
            return;
        }
    }
}