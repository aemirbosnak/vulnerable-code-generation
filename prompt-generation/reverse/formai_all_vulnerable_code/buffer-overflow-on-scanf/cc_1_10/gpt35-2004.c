//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} movie;

void add_movie(movie *movies, int *count) {
    printf("Title: ");
    scanf("%s", movies[*count].title);
    printf("Director: ");
    scanf("%s", movies[*count].director);
    printf("Year: ");
    scanf("%d", &movies[*count].year);
    printf("Rating (out of 10): ");
    scanf("%f", &movies[*count].rating);
    (*count)++;
}

void display_movies(movie *movies, int count) {
    printf("\nTitle\t\tDirector\tYear\tRating\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%.1f\n", movies[i].title,
               movies[i].director, movies[i].year, movies[i].rating);
    }
}

int main() {
    movie movies[50];
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}