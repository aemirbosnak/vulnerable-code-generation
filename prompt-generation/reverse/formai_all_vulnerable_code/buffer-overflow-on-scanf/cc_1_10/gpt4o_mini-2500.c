//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char title[NAME_LENGTH];
    int year;
    float rating;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Alas! The inventory of cinematic tales is full!\n");
        return;
    }

    printf("Enter the title of the film: ");
    scanf(" %[^\n]", movies[*count].title);
    printf("Enter the year of release: ");
    scanf("%d", &movies[*count].year);
    printf("Enter the rating (from 0.0 to 5.0): ");
    scanf("%f", &movies[*count].rating);

    if (movies[*count].rating < 0.0 || movies[*count].rating > 5.0) {
        printf("A rating must be between 0.0 and 5.0, brave knight!\n");
    } else {
        (*count)++;
        printf("The film hath been added to the collection!\n");
    }
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("The collection is empty, kind viewer.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" (%d) - Rating: %.1f/5.0\n", i + 1, movies[i].title, movies[i].year, movies[i].rating);
    }
}

void searchMovie(Movie movies[], int count) {
    char searchTitle[NAME_LENGTH];
    printf("Enter the title of the film you seek: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("Thy requested film \"%s\" hath a rating of %.1f/5.0, released in the year %d.\n", 
                   movies[i].title, movies[i].rating, movies[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Alas! The film is not found in our annals.\n");
    }
}

void deleteMovie(Movie movies[], int *count) {
    if (*count == 0) {
        printf("No films to delete, valiant viewer.\n");
        return;
    }

    displayMovies(movies, *count);
    int index;
    printf("Enter the number of the film to remove (1-%d): ", *count);
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Thou hast chosen an invalid number!\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        movies[i] = movies[i + 1];
    }
    (*count)--;
    printf("The film hath been banished from the collection!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Regal Movie Rating System ===\n");
        printf("1. Add a Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search for a Movie\n");
        printf("4. Remove a Movie\n");
        printf("5. Exit\n");
        printf("Choose thy destiny (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Farewell, noble visitor!\n");
                return 0;
            default:
                printf("Verily! That choice is unknown.\n");
        }
    }

    return 0;
}