//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} movie;

void addMovie(movie movies[], int *movieCount) {
    movie newMovie;

    printf("Enter movie title: ");
    scanf("%s", &newMovie.title);

    printf("Enter movie director: ");
    scanf("%s", &newMovie.director);

    printf("Enter movie year: ");
    scanf("%d", &newMovie.year);

    printf("Enter movie rating: ");
    scanf("%f", &newMovie.rating);

    movies[*movieCount] = newMovie;
    *movieCount += 1;

    printf("\nMovie added successfully!\n\n");
}

void listMovies(movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies added yet.\n\n");
        return;
    }

    printf("Title\t\tDirector\tYear\tRating\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < movieCount; i++) {
        printf("%s\t\t%s\t\t%d\t%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }

    printf("\n");
}

void rateMovie(movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies added yet.\n\n");
        return;
    }

    char title[50];
    int index = -1;

    printf("Enter movie title: ");
    scanf("%s", &title);

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Movie not found.\n\n");
        return;
    }

    float rating;

    printf("Enter new rating: ");
    scanf("%f", &rating);

    movies[index].rating = rating;

    printf("\nRating updated successfully!\n\n");
}

void menu() {
    printf("\n1. Add a movie\n");
    printf("2. List all movies\n");
    printf("3. Rate a movie\n");
    printf("4. Quit\n\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int movieCount = 0;
    movie movies[50];

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                listMovies(movies, movieCount);
                break;
            case 3:
                rateMovie(movies, movieCount);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}