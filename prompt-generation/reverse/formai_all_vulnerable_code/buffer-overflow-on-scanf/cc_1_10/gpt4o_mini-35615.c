//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // 1 to 5 scale
} Movie;

void addMovie(Movie *movies, int *movieCount);
void showMovies(Movie *movies, int movieCount);
void rateMovie(Movie *movies, int movieCount);
void showSummary(Movie *movies, int movieCount);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    printf("🎬 Welcome to the Happy Movie Rating System! 🎬\n");
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. Show all movies\n");
        printf("4. Show summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                showMovies(movies, movieCount);
                break;
            case 4:
                showSummary(movies, movieCount);
                break;
            case 5:
                printf("Thank you for using the System! Have a great day! 🌟\n");
                break;
            default:
                printf("Invalid choice! Please choose again. 😊\n");
        }
    } while (choice != 5);

    return 0;
}

void addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("You have reached the maximum number of movies! 🎥\n");
        return;
    }
    printf("Enter the movie title: ");
    fgets(movies[*movieCount].title, MAX_TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // Remove newline character
    movies[*movieCount].rating = 0; // Initialize rating to 0
    (*movieCount)++;
    printf("Movie '%s' added successfully! 🎉\n", movies[*movieCount - 1].title);
}

void rateMovie(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies available to rate. Please add movies first! 😢\n");
        return;
    }

    showMovies(movies, movieCount);

    int index, rating;
    printf("Enter the movie number you want to rate: ");
    scanf("%d", &index);

    if (index < 1 || index > movieCount) {
        printf("Invalid movie number! Please choose a valid number. ❌\n");
        return;
    }

    printf("Rate the movie '%s' (1-5): ", movies[index - 1].title);
    scanf("%d", &rating);
    
    if (rating < 1 || rating > 5) {
        printf("Rating must be between 1 and 5! 🌈\n");
        return;
    }
    movies[index - 1].rating = rating;
    printf("Thank you for rating '%s' with a score of %d! ⭐️\n", movies[index - 1].title, rating);
}

void showMovies(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies in the list! 😔\n");
        return;
    }
    printf("\n🌟 List of Movies 🌟\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s (Rating: %d)\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void showSummary(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No ratings to summarize! Please add and rate some movies! 🌼\n");
        return;
    }

    printf("\n🎉 Movie Rating Summary 🎉\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie: %s | Your Rating: %d\n", movies[i].title, movies[i].rating);
    }
}