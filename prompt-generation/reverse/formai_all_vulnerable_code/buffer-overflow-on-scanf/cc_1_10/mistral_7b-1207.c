//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_TITLE_LENGTH 50
#define MAX_RATING_LENGTH 2

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int numMovies = 0;

void printTableHeader() {
    printf("%-30s%-10s\n", "Movie Title", "Rating");
    printf("--------------------------------------\n");
}

void printMovie(Movie movie) {
    printf("%-30s%-10d\n", movie.title, movie.rating);
}

void addMovie() {
    if (numMovies >= MAX_MOVIES) {
        printf("Maximum movies reached!\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[numMovies].title, MAX_TITLE_LENGTH, stdin);
    movies[numMovies].title[strcspn(movies[numMovies].title, "\n")] = '\0';

    printf("Enter movie rating (1-10): ");
    scanf("%d", &movies[numMovies].rating);

    numMovies++;
}

void viewMovies() {
    printTableHeader();

    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }
}

void updateMovie(int index) {
    if (index >= 0 && index < numMovies) {
        printf("Enter new movie title: ");
        fgets(movies[index].title, MAX_TITLE_LENGTH, stdin);
        movies[index].title[strcspn(movies[index].title, "\n")] = '\0';

        printf("Enter new movie rating (1-10): ");
        scanf("%d", &movies[index].rating);

        printf("Movie updated successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

void deleteMovie(int index) {
    if (index >= 0 && index < numMovies) {
        for (int i = index; i < numMovies - 1; i++) {
            movies[i] = movies[i + 1];
        }
        numMovies--;

        printf("Movie deleted successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

int main() {
    int choice;
    int index;

    while (1) {
        printf("\n1. Add movie\n2. View movies\n3. Update movie\n4. Delete movie\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                printf("Enter index of movie to update: ");
                scanf("%d", &index);
                updateMovie(index);
                break;
            case 4:
                printf("Enter index of movie to delete: ");
                scanf("%d", &index);
                deleteMovie(index);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}