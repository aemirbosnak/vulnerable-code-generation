//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50
#define GENRE_LENGTH 30
#define RATING_LENGTH 5

typedef struct {
    char title[TITLE_LENGTH];
    char genre[GENRE_LENGTH];
    float rating;
} Movie;

void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Whoa! We can't add more movies, the collection is full!\n");
        return;
    }

    Movie newMovie;

    printf("🎥 Enter the movie title: ");
    getchar();  // Clear the newline
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("🎬 Enter the genre: ");
    fgets(newMovie.genre, GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    printf("⭐ Enter your rating (0-10): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("🚫 Ratings should be between 0 and 10! Try again!\n");
        return;
    }

    movies[*movieCount] = newMovie;
    (*movieCount)++;
    printf("🎉 Movie '%s' added successfully! Total movies: %d\n", newMovie.title, *movieCount);
}

void displayMovies(const Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("😢 No movies to display! Let's add some!\n");
        return;
    }

    printf("\n🌟 Movie List 🌟\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s | Genre: %s | Rating: %.1f/10\n", i + 1, movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void searchMovie(const Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("😢 No movies to search! Please add movies first!\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("🔍 Enter movie title to search: ");
    getchar();  // Clear the newline
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("🏆 Found: %s | Genre: %s | Rating: %.1f/10\n", movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("🚫 Sorry, movie '%s' not found in the collection!\n", searchTitle);
}

void deleteMovie(Movie movies[], int *movieCount) {
    if (*movieCount == 0) {
        printf("😢 No movies to delete! Add some first!\n");
        return;
    }

    displayMovies(movies, *movieCount);
    int index;
    printf("❌ Enter the movie number you want to delete: ");
    scanf("%d", &index);
    index--; // Adjust for zero-based index

    if (index < 0 || index >= *movieCount) {
        printf("🚫 Invalid movie number. Could not delete!\n");
        return;
    }

    for (int i = index; i < *movieCount - 1; i++) {
        movies[i] = movies[i + 1]; // Shift left
    }
    (*movieCount)--;
    printf("✅ Movie '%s' deleted successfully! Remaining movies: %d\n", movies[index].title, *movieCount);
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        printf("\n✨ Welcome to the Movie Rating System! 🎬✨");
        printf("\n1. Add Movie");
        printf("\n2. Display Movies");
        printf("\n3. Search Movie");
        printf("\n4. Delete Movie");
        printf("\n5. Exit");
        printf("\nChoose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 4:
                deleteMovie(movies, &movieCount);
                break;
            case 5:
                printf("👋 Thanks for using the Movie Rating System! See you next time! 🎊\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please select a valid option!\n");
        }
    }

    return 0;
}