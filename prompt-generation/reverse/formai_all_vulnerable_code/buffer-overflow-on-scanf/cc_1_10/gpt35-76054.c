//FormAI DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct movie {
    char name[50];
    char genre[20];
    int year;
    float rating;
};

struct movie movies[100];
int num_movies = 0;

void add_movie() {
    printf("Enter movie name:");
    scanf("%s", &movies[num_movies].name);
    printf("Enter movie genre:");
    scanf("%s", &movies[num_movies].genre);
    printf("Enter movie release year:");
    scanf("%d", &movies[num_movies].year);
    printf("Enter movie rating (between 0 and 10):");
    scanf("%f", &movies[num_movies].rating);

    num_movies++;
}

void display_movies() {
    printf("Movie Name\tGenre\tYear\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%d\t%.1f\n", movies[i].name, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

void view_by_genre() {
    char genre[20];
    printf("Enter genre to view movies:\n");
    scanf("%s", genre);

    printf("Movie Name\tYear\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("%s\t%d\t%.1f\n", movies[i].name, movies[i].year, movies[i].rating);
        }
    }
}

void view_by_year() {
    int year;
    printf("Enter year to view movies:\n");
    scanf("%d", &year);

    printf("Movie Name\tGenre\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].year == year) {
            printf("%s\t%s\t%.1f\n", movies[i].name, movies[i].genre, movies[i].rating);
        }
    }
}

void view_by_rating() {
    float rating;
    printf("Enter rating to view movies:\n");
    scanf("%f", &rating);

    printf("Movie Name\tGenre\tYear\n");
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating >= rating) {
            printf("%s\t%s\t%d\n", movies[i].name, movies[i].genre, movies[i].year);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. View movies by genre\n");
        printf("4. View movies by year\n");
        printf("5. View movies by rating\n");
        printf("6. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_movie();
            break;
        case 2:
            display_movies();
            break;
        case 3:
            view_by_genre();
            break;
        case 4:
            view_by_year();
            break;
        case 5:
            view_by_rating();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input\n");
        }
        printf("\n");
    }
    return 0;
}