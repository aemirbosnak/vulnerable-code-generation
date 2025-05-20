//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating; // Rating out of 10
} Movie;

Movie movieCollection[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Wow! You've added too many movies! Consider deleting some.\n");
        return;
    }

    char title[TITLE_LENGTH];
    int rating;

    printf("\n🎬 Surprise! Time to add a new movie!\n");
    printf("Enter the movie title: ");
    getchar(); // Consume newline from previous input
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    printf("Rate the movie (0-10): ");
    scanf("%d", &rating);

    if (rating < 0 || rating > 10) {
        printf("🤪 Oops! Ratings must be between 0 and 10.\n");
        return;
    }

    strcpy(movieCollection[movieCount].title, title);
    movieCollection[movieCount].rating = rating;
    movieCount++;

    printf("🎉 Hooray! You've added \"%s\" with a rating of %d!\n", title, rating);
}

void viewMovies() {
    printf("\n🎥 Your Movie Collection 🎥\n");
    if (movieCount == 0) {
        printf("Oooops! No movies in your collection yet!\n");
        return;
    }

    for (int i = 0; i < movieCount; ++i) {
        printf("%d. \"%s\" - Rating: %d/10\n", i + 1, movieCollection[i].title, movieCollection[i].rating);
    }
}

void surpriseMenu() {
    printf("🎉 Welcome to the Movie Rating Surprise App! 🎉\n");
    printf("1. Add a movie\n");
    printf("2. View movies\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        surpriseMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                printf("🎈 Thanks for visiting our surprise world of movies! Bye-bye! 🎈\n");
                exit(0);
            default:
                printf("🌀 Unexpected choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}