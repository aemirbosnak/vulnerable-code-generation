//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieList;

void initMovieList(MovieList *list) {
    list->count = 0;
}

void addMovie(MovieList *list) {
    if (list->count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    scanf(" %[^\n]s", newMovie.title);
    printf("Enter movie director: ");
    scanf(" %[^\n]s", newMovie.director);
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! Must be between 0.0 and 10.0.\n");
        return;
    }

    list->movies[list->count] = newMovie;
    list->count++;
    printf("Movie added successfully!\n");
}

void displayMovies(const MovieList *list) {
    if (list->count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Title: %s\n", list->movies[i].title);
        printf("Director: %s\n", list->movies[i].director);
        printf("Year: %d\n", list->movies[i].year);
        printf("Rating: %.1f\n\n", list->movies[i].rating);
    }
}

void searchMovie(const MovieList *list) {
    char title[100];
    printf("Enter the movie title to search: ");
    scanf(" %[^\n]s", title);

    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcasecmp(list->movies[i].title, title) == 0) {
            printf("Movie found!\n");
            printf("Title: %s\n", list->movies[i].title);
            printf("Director: %s\n", list->movies[i].director);
            printf("Year: %d\n", list->movies[i].year);
            printf("Rating: %.1f\n\n", list->movies[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

void rateMovie(MovieList *list) {
    char title[100];
    printf("Enter the movie title to rate: ");
    scanf(" %[^\n]s", title);

    for (int i = 0; i < list->count; i++) {
        if (strcasecmp(list->movies[i].title, title) == 0) {
            float newRating;
            printf("Enter new rating for %s (Current: %.1f): ", title, list->movies[i].rating);
            scanf("%f", &newRating);
            if (newRating < 0.0 || newRating > 10.0) {
                printf("Invalid rating! Must be between 0.0 and 10.0.\n");
            } else {
                list->movies[i].rating = newRating;
                printf("Rating updated successfully!\n");
            }
            return;
        }
    }
    printf("Movie not found!\n");
}

void menu() {
    printf("Movie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MovieList list;
    initMovieList(&list);
    
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(&list);
                break;
            case 2:
                displayMovies(&list);
                break;
            case 3:
                searchMovie(&list);
                break;
            case 4:
                rateMovie(&list);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}