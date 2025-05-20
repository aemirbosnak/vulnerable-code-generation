//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    float rating;
    int year;
} Movie;

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("\nEnter movie title: ");
    scanf(" %[^\n]", movies[*count].title);
    
    printf("Enter director's name: ");
    scanf(" %[^\n]", movies[*count].director);
    
    printf("Enter movie release year: ");
    scanf("%d", &movies[*count].year);
    
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);

    // Validate the rating
    while (movies[*count].rating < 0.0 || movies[*count].rating > 10.0) {
        printf("Invalid rating! Please enter a value between 0.0 and 10.0: ");
        scanf("%f", &movies[*count].rating);
    }

    (*count)++;
    printf("Movie \"%s\" added successfully!\n", movies[*count - 1].title);
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("\nNo movies to display!\n");
        return;
    }

    printf("\n\n** Movie List **\n");
    for (int i = 0; i < count; i++) {
        printf("---------------------------------------------------\n");
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
    }
    printf("---------------------------------------------------\n");
}

void searchByTitle(Movie *movies, int count) {
    char title[MAX_TITLE_LENGTH];
    printf("\nEnter movie title to search: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("\nMovie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            return;
        }
    }
    
    printf("Movie \"%s\" not found!\n", title);
}

void deleteMovie(Movie *movies, int *count) {
    if (*count == 0) {
        printf("\nNo movies to delete!\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("\nEnter movie title to delete: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie \"%s\" deleted successfully!\n", title);
            return;
        }
    }
    
    printf("Movie \"%s\" not found!\n", title);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0, choice;

    while (1) {
        printf("\n** Movie Rating System **\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie by Title\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchByTitle(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}