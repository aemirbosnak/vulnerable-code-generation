//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratings[100];
    int ratingCount;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char* title) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movies[movieCount].title, title);
        movies[movieCount].ratingCount = 0;
        movieCount++;
        printf("✨ Surprise! '%s' has been added to the movie list! ✨\n", title);
    } else {
        printf("🚫 Oh no! Maximum movie limit reached! 🚫\n");
    }
}

void rateMovie(int movieIndex, int rating) {
    if (movieIndex < 0 || movieIndex >= movieCount) {
        printf("💔 Oops! Movie not found! 💔\n");
        return;
    }
    if (movies[movieIndex].ratingCount < 100) {
        movies[movieIndex].ratings[movies[movieIndex].ratingCount++] = rating;
        printf("🌟 You rated '%s' with %d stars! 🌟\n", movies[movieIndex].title, rating);
    } else {
        printf("🚀 Wow! You've rated this movie enough times! 🚀\n");
    }
}

float getAverageRating(int movieIndex) {
    if (movieIndex < 0 || movieIndex >= movieCount) {
        return -1.0;
    }
    int sum = 0;
    for (int i = 0; i < movies[movieIndex].ratingCount; i++) {
        sum += movies[movieIndex].ratings[i];
    }
    return (float)sum / movies[movieIndex].ratingCount;
}

void displayMovies() {
    printf("\n🎬 Movie List 🎬\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s\n", i + 1, movies[i].title);
        float average = getAverageRating(i);
        if (average >= 0) {
            printf("   Average Rating: %.2f\n", average);
        }
    }
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    
    printf("🌟 Welcome to the Movie Rating Surprise System! 🌟\n");
    
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a Movie\n");
        printf("2. Rate a Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Choose your option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                getchar(); // to consume the newline character
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove the newline character
                addMovie(title);
                break;
            case 2:
                displayMovies();
                printf("Enter the movie number to rate: ");
                int movieNumber;
                scanf("%d", &movieNumber);
                printf("Enter your rating (1-5): ");
                int rating;
                scanf("%d", &rating);
                if (rating < 1 || rating > 5) {
                    printf("🚫 Rating should be between 1 and 5! 🚫\n");
                } else {
                    rateMovie(movieNumber - 1, rating);
                }
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("🎉 Thank you for using the Movie Rating Surprise System! Goodbye! 🎉\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please choose again. ❌\n");
        }
    }
    return 0;
}