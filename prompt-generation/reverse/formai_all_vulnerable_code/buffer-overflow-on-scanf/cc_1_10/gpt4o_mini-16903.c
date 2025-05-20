//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_GENRE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieList;

void initMovieList(MovieList *list) {
    list->count = 0;
}

void addMovie(MovieList *list, const char *title, const char *genre, float rating) {
    if (list->count < MAX_MOVIES) {
        strncpy(list->movies[list->count].title, title, MAX_TITLE_LEN);
        strncpy(list->movies[list->count].genre, genre, MAX_GENRE_LEN);
        list->movies[list->count].rating = rating;
        list->count++;
        printf("Added movie: %s (%s) - Rating: %.1f\n", title, genre, rating);
    } else {
        printf("Movie list is full! Cannot add more movies.\n");
    }
}

void displayMovies(const MovieList *list) {
    if (list->count == 0) {
        printf("No movies available to display.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%s) - Rating: %.1f\n", i + 1, list->movies[i].title, list->movies[i].genre, list->movies[i].rating);
    }
}

void updateRating(MovieList *list, int index, float newRating) {
    if (index >= 0 && index < list->count) {
        list->movies[index].rating = newRating;
        printf("Updated movie: %s - New Rating: %.1f\n", list->movies[index].title, newRating);
    } else {
        printf("Invalid movie index: %d\n", index);
    }
}

float averageRating(const MovieList *list) {
    if (list->count == 0) return 0.0f;

    float totalRating = 0.0f;
    for (int i = 0; i < list->count; i++) {
        totalRating += list->movies[i].rating;
    }
    return totalRating / list->count;
}

void searchByGenre(const MovieList *list, const char *genre) {
    int found = 0;
    printf("\nMovies in Genre '%s':\n", genre);
    for (int i = 0; i < list->count; i++) {
        if (strcasecmp(list->movies[i].genre, genre) == 0) {
            printf("%s - Rating: %.1f\n", list->movies[i].title, list->movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in genre '%s'.\n", genre);
    }
}

int main() {
    MovieList movieList;
    initMovieList(&movieList);

    int choice;
    char title[MAX_TITLE_LEN], genre[MAX_GENRE_LEN];
    float rating;

    do {
        printf("\n---- Movie Rating System ----\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Update Movie Rating\n");
        printf("4. Average Movie Rating\n");
        printf("5. Search Movies by Genre\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                getchar(); // clear newline from buffer
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                printf("Enter movie genre: ");
                fgets(genre, MAX_GENRE_LEN, stdin);
                genre[strcspn(genre, "\n")] = 0; // remove newline
                printf("Enter movie rating (0-10): ");
                scanf("%f", &rating);
                addMovie(&movieList, title, genre, rating);
                break;

            case 2:
                displayMovies(&movieList);
                break;

            case 3:
                printf("Enter movie index to update (1-%d): ", movieList.count);
                int index;
                scanf("%d", &index);
                printf("Enter new rating (0-10): ");
                scanf("%f", &rating);
                updateRating(&movieList, index - 1, rating);
                break;

            case 4:
                printf("Average Movie Rating: %.1f\n", averageRating(&movieList));
                break;

            case 5:
                printf("Enter genre to search: ");
                getchar(); // clear newline from buffer
                fgets(genre, MAX_GENRE_LEN, stdin);
                genre[strcspn(genre, "\n")] = 0; // remove newline
                searchByGenre(&movieList, genre);
                break;

            case 0:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}