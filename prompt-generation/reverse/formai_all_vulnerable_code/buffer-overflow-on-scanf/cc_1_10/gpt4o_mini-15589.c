//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void displayMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Rating: %s\n\n", movie.rating);
}

void displayAllMovies(Movie movies[], int count) {
    printf("Oh, gentle hearts, here comes the list of movies:\n");
    for (int i = 0; i < count; i++) {
        printf("~*~ Movie %d ~*~\n", i + 1);
        displayMovie(movies[i]);
    }
}

int findMovie(Movie movies[], int count, const char* title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void addMovie(Movie movies[], int* count) {
    if (*count >= MAX_MOVIES) {
        printf("Alas, the heavens do not permit more movies to be entered!\n");
        return;
    }

    Movie newMovie;
    printf("Enter the title of thy movie: ");
    getchar(); // Consume newline
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Give a rating to this fine piece of art (1-5): ");
    fgets(newMovie.rating, MAX_RATING_LENGTH, stdin);
    newMovie.rating[strcspn(newMovie.rating, "\n")] = 0; // Remove newline

    movies[*count] = newMovie;
    (*count)++;
    printf("O wonderful, thy movie hath been added!\n");
}

void updateMovie(Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Which movie dost thou seek to update? ");
    getchar(); // Consume newline
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int index = findMovie(movies, count, title);
    if (index != -1) {
        printf("Enter the new rating for '%s': ", movies[index].title);
        fgets(movies[index].rating, MAX_RATING_LENGTH, stdin);
        movies[index].rating[strcspn(movies[index].rating, "\n")] = 0; // Remove newline
        printf("Thy movie rating hath been updated!\n");
    } else {
        printf("What cruel fate! The movie defined is not found in this realm!\n");
    }
}

void deleteMovie(Movie movies[], int* count) {
    char title[MAX_TITLE_LENGTH];
    printf("Which movie dost thou wish to vanquish? ");
    getchar(); // Consume newline
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int index = findMovie(movies, *count, title);
    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            movies[i] = movies[i + 1];
        }
        (*count)--;
        printf("The movie '%s' hath been banished!\n", title);
    } else {
        printf("Alas, the title is not found in our illustrious collection!\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printf("\nWhat dost thou wish to do, dear cinephile?\n");
        printf("1. Add a movie\n");
        printf("2. Update a movie rating\n");
        printf("3. Delete a movie\n");
        printf("4. Display all movies\n");
        printf("5. Exit\n");
        printf("Select thy choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                updateMovie(movies, count);
                break;
            case 3:
                deleteMovie(movies, &count);
                break;
            case 4:
                displayAllMovies(movies, count);
                break;
            case 5:
                printf("Fare thee well, dear soul!\n");
                break;
            default:
                printf("Thou hast chosen poorly, selecteth again!\n");
        }
    } while (choice != 5);

    return 0;
}