//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_REVIEW_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char genre[MAX_NAME_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Oh no! We ran out of popcorn! Can't add more movies.\n");
        return;
    }
    
    printf("Enter the name of the movie: ");
    scanf(" %[^\n]s", movies[*count].name); // Read a string with spaces
    printf("Enter the genre of the movie: ");
    scanf(" %[^\n]s", movies[*count].genre);
    printf("Enter your rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    printf("Enter your review: ");
    scanf(" %[^\n]s", movies[*count].review);
    
    (*count)++;
    printf("Movie added! You've successfully added a new masterpiece!\n");
}

void listMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("Oops! No movies in the database. Did you eat them all?\n");
        return;
    }

    printf("\n=== Movie List ===\n");
    for (int i = 0; i < count; i++) {
        printf("Movie #%d: %s\n", i + 1, movies[i].name);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void searchMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("Searching for a unicorn in the desert? No movies to search here!\n");
        return;
    }

    char searchTerm[MAX_NAME_LENGTH];
    printf("Enter the movie name you want to search: ");
    scanf(" %[^\n]s", searchTerm);

    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].name, searchTerm) != NULL) {
            printf("Found Movie: %s\n", movies[i].name);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Review: %s\n\n", movies[i].review);
            return;
        }
    }
    printf("Sorry, didn't find any movie with '%s'. Better luck next time!\n", searchTerm);
}

void deleteMovie(Movie *movies, int *count) {
    if (*count == 0) {
        printf("No movies to delete? Are you looking for imaginary friends?\n");
        return;
    }

    int index;
    printf("Enter the index of the movie you want to delete (1 - %d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Oops! That's out of range! No movies were harmed in this process.\n");
        return;
    }

    printf("Deleting movie: %s\n", movies[index - 1].name);
    for (int i = index - 1; i < *count - 1; i++) {
        movies[i] = movies[i + 1]; // Shift movies left
    }
    (*count)--;
    printf("Movie deleted! Hooray for cleaning up!\n");
}

void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
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
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Thanks for using the Movie Rating System! Happy movie watching!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again or try to teach me how to dance!\n");
        }
    }

    return 0;
}