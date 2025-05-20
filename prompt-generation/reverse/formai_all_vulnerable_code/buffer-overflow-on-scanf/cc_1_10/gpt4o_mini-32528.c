//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50
#define MAX_GENRE_LEN 20

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    float rating;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Maximum movie limit reached! Cannot add more movies.\n");
        return;
    }
    Movie newMovie;
    printf("Enter Movie Title: ");
    getchar(); // To consume the newline character from the previous input
    fgets(newMovie.title, MAX_TITLE_LEN, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("Enter Movie Genre: ");
    fgets(newMovie.genre, MAX_GENRE_LEN, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    printf("Enter Movie Rating (1.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    // Make sure the rating is valid
    if (newMovie.rating < 1.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! Please enter a value between 1.0 and 10.0.\n");
        return;
    }

    movies[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies rated yet!\n");
        return;
    }
    printf("\n=== Movie List ===\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s | Genre: %s | Rating: %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void averageRating() {
    if (movieCount == 0) {
        printf("No ratings available to calculate average.\n");
        return;
    }
    float sum = 0.0;
    for (int i = 0; i < movieCount; i++) {
        sum += movies[i].rating;
    }
    float average = sum / movieCount;
    printf("Average Movie Rating: %.1f\n", average);
}

void recommendMovie() {
    if (movieCount == 0) {
        printf("No movies to recommend. Please add some movies first!\n");
        return;
    }
    float highestRating = movies[0].rating;
    int highestIndex = 0;

    for (int i = 1; i < movieCount; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestIndex = i;
        }
    }

    printf("We recommend you to watch: %s (Genre: %s) with a Rating of %.1f!\n",
           movies[highestIndex].title, movies[highestIndex].genre, highestRating);
}

void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add a Movie\n");
    printf("2. Display Movies\n");
    printf("3. Show Average Rating\n");
    printf("4. Recommend a Movie\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                addMovie();
                break;
            case 2: 
                displayMovies();
                break;
            case 3: 
                averageRating();
                break;
            case 4: 
                recommendMovie();
                break;
            case 5: 
                printf("Thank you for using the Movie Rating System! Goodbye!\n");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}