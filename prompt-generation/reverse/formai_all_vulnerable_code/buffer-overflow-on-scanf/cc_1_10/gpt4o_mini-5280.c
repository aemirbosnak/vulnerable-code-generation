//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    float rating;
    int year;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieCollection;

void initializeCollection(MovieCollection* collection) {
    collection->count = 0;
}

void addMovie(MovieCollection* collection, const char* title, float rating, int year) {
    if (collection->count < MAX_MOVIES) {
        Movie newMovie;
        snprintf(newMovie.title, MAX_TITLE_LEN, "%s", title);
        newMovie.rating = rating;
        newMovie.year = year;
        collection->movies[collection->count] = newMovie;
        collection->count++;
        printf("Movie added: %s, Rating: %.1f, Year: %d\n", title, rating, year);
    } else {
        printf("Movie collection is full!\n");
    }
}

void displayMovies(const MovieCollection* collection) {
    if (collection->count == 0) {
        printf("No movies in the collection.\n");
        return;
    }

    printf("\nMovie Collection:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < collection->count; i++) {
        printf("Title: %s, Rating: %.1f, Year: %d\n", 
               collection->movies[i].title, 
               collection->movies[i].rating, 
               collection->movies[i].year);
    }
    printf("--------------------------------------------------\n");
}

void displayAverageRating(const MovieCollection* collection) {
    if (collection->count == 0) {
        printf("No movies to calculate average rating.\n");
        return;
    }

    float totalRating = 0.0;
    for (int i = 0; i < collection->count; i++) {
        totalRating += collection->movies[i].rating;
    }
    
    float averageRating = totalRating / collection->count;
    printf("Average Rating of Movies: %.2f\n", averageRating);
}

void sortMoviesByRating(MovieCollection* collection) {
    for (int i = 0; i < collection->count - 1; i++) {
        for (int j = i + 1; j < collection->count; j++) {
            if (collection->movies[i].rating < collection->movies[j].rating) {
                // Swap movies
                Movie temp = collection->movies[i];
                collection->movies[i] = collection->movies[j];
                collection->movies[j] = temp;
            }
        }
    }
}

void displayMenu() {
    printf("Welcome to the Movie Rating System!\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Display Average Rating\n");
    printf("4. Sort Movies by Rating\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MovieCollection collection;
    initializeCollection(&collection);

    int choice;
    char title[MAX_TITLE_LEN];
    float rating;
    int year;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                getchar(); // consume the newline
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // remove the newline

                printf("Enter movie rating (0 - 10): ");
                scanf("%f", &rating);
                printf("Enter movie year: ");
                scanf("%d", &year);

                addMovie(&collection, title, rating, year);
                break;

            case 2:
                displayMovies(&collection);
                break;

            case 3:
                displayAverageRating(&collection);
                break;

            case 4:
                sortMoviesByRating(&collection);
                printf("Movies sorted by rating.\n");
                break;

            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}