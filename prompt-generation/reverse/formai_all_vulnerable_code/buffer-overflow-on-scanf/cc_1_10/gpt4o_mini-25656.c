//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    int votes;
} Movie;

Movie movieDatabase[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Oh no! Movie limit reached! Cannot add more movies!\n");
        return;
    }

    Movie newMovie;

    printf("Enter movie title: ");
    getchar(); // Clear the newline
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = '\0'; // Remove newline character

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Alert! Invalid rating! Must be between 0.0 and 10.0\n");
        return;
    }

    newMovie.votes = 0; // Initial votes

    movieDatabase[movieCount++] = newMovie;

    printf("Movie '%s' added with rating: %.1f! Total movies: %d\n", newMovie.title, newMovie.rating, movieCount);
}

void rateMovie() {
    if (movieCount == 0) {
        printf("Uh-oh! No movies in the database to rate!\n");
        return;
    }

    printf("Choose a movie to rate (1 to %d):\n", movieCount);
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s (Current Rating: %.1f)\n", i + 1, movieDatabase[i].title, movieDatabase[i].rating);
    }

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > movieCount) {
        printf("Oops! Invalid choice! Please try again!\n");
        return;
    }

    float newRating;
    printf("Enter your rating for '%s': ", movieDatabase[choice - 1].title);
    scanf("%f", &newRating);

    if (newRating < 0.0 || newRating > 10.0) {
        printf("Warning! Invalid rating! Must be between 0.0 and 10.0\n");
        return;
    }

    movieDatabase[choice - 1].rating = (movieDatabase[choice - 1].rating * movieDatabase[choice - 1].votes + newRating) 
                                        / (++movieDatabase[choice - 1].votes);
    
    printf("Thank you for rating! The new rating for '%s' is %.1f!\n", movieDatabase[choice - 1].title, movieDatabase[choice - 1].rating);
}

void displayMovies() {
    if (movieCount == 0) {
        printf("Darn! No movies to display!\n");
        return;
    }

    printf("\nHere are all the movies in the database:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %.1f (%d vote%s)\n", i + 1, movieDatabase[i].title, movieDatabase[i].rating, movieDatabase[i].votes, 
             movieDatabase[i].votes == 1 ? "" : "s");
    }
}

void menu() {
    while (1) {
        printf("\n!!! MOVIE RATING SYSTEM !!!\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("Exiting... See you next time!\n");
                exit(0);
            default:
                printf("Yikes! Invalid selection! Please choose again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Movie Rating System!\n");
    menu();
    return 0;
}