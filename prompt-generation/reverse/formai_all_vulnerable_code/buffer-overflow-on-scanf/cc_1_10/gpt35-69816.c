//FormAI DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    int year;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    printf("Enter movie title: ");
    scanf("%s", movies[*count].title);

    printf("Enter movie release year: ");
    scanf("%d", &movies[*count].year);

    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);

    printf("Movie added!\n");
    (*count)++;
}

void listMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("Title\t\tYear\tRating\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.1f\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

void searchMoviesByRating(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to search for.\n");
        return;
    }

    float rating;
    printf("Enter rating to search for: ");
    scanf("%f", &rating);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (movies[i].rating == rating) {
            printf("%s (%d)\n", movies[i].title, movies[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found.\n");
    }
}

int main() {
    struct Movie movies[100];
    int count = 0;
    int choice = 0;

    do {
        printf("\nC Movie Rating System\n");
        printf("======================\n");
        printf("1. Add movie\n");
        printf("2. List movies\n");
        printf("3. Search movies by rating\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                listMovies(movies, count);
                break;
            case 3:
                searchMoviesByRating(movies, count);
                break;
            case 4:
                printf("Thank you for using C Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}