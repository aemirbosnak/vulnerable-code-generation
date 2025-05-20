//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold movie details
struct Movie {
    char title[100];
    char genre[50];
    float rating;
};

// Function to display a menu
void displayMenu() {
    printf("\n🎬 Movie Rating System 🎬\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

// Function to add a movie
void addMovie(struct Movie *movies, int *count) {
    printf("Enter movie title: ");
    scanf(" %[^\n]s", movies[*count].title);
    printf("Enter movie genre: ");
    scanf(" %[^\n]s", movies[*count].genre);
    movies[*count].rating = 0.0; // Initial rating 
    (*count)++;
    printf("✨ Movie added successfully! 🎉\n");
}

// Function to view all movies
void viewMovies(struct Movie *movies, int count) {
    if (count == 0) {
        printf("😢 No movies to display.\n");
    } else {
        printf("\n📽️ Movies List 📽️\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s (%s) - Rating: %.2f\n", i + 1, movies[i].title, movies[i].genre, movies[i].rating);
        }
    }
}

// Function to rate a movie
void rateMovie(struct Movie *movies, int count) {
    int choice;
    viewMovies(movies, count);
    if (count == 0) return;

    printf("Select a movie to rate (1-%d): ", count);
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("🚫 Invalid selection! Please try again.\n");
        return;
    }

    float newRating;
    printf("Enter new rating for '%s' (0.0 - 10.0): ", movies[choice - 1].title);
    scanf("%f", &newRating);
    if (newRating < 0.0 || newRating > 10.0) {
        printf("🚫 Invalid rating! Please enter a rating between 0.0 and 10.0.\n");
        return;
    }

    movies[choice - 1].rating = newRating; // Update the rating
    printf("⭐ Thank you! Rating updated for '%s' to %.2f!\n", movies[choice - 1].title, newRating);
}

int main() {
    struct Movie movies[100];
    int movieCount = 0;
    int choice = 0;

    printf("🌟 Welcome to the Movie Rating System! 🌟\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                rateMovie(movies, movieCount);
                break;
            case 4:
                printf("👋 Thank you for using the Movie Rating System! Goodbye! 🎉\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please select from the menu.\n");
                break;
        }
    }

    return 0;
}