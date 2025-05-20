//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store movie information
typedef struct {
    char title[100];
    int year;
    int rating; // 1-10 scale
    char review[256];
} Movie;

// Function declarations
void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void searchMovie(Movie *movies, int count);
void paranoidMode();
void waitForUserInput();

int main() {
    // Defining parameters for the Movie Rating System
    Movie movies[100];
    int count = 0;
    int option;

    // Simulate paranoia
    paranoidMode();

    while (1) {
        printf("\nMovie Rating System:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                printf("Exiting the program... But remember, they are always watching.\n");
                exit(0);
            default:
                printf("Invalid option. Choose wisely.\n");
        }
        waitForUserInput();
    }

    return 0;
}

void addMovie(Movie *movies, int *count) {
    if (*count >= 100) {
        printf("Movie list is full! Don't let them get to you...\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // consume newline
    fgets(movies[*count].title, 100, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter year of release: ");
    scanf("%d", &movies[*count].year);

    printf("Rate the movie (1-10): ");
    scanf("%d", &movies[*count].rating);

    printf("Write a review: ");
    getchar(); // consume newline
    fgets(movies[*count].review, 256, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // Remove newline
    
    (*count)++;
    printf("Movie added successfully. But did anyone see you add it?\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display. Feels like an empty room... \n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Year: %d | Rating: %d | Review: %s\n", 
                movies[i].title, movies[i].year, movies[i].rating, movies[i].review);
    }
}

void searchMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("You can't search if the shadows don't move...\n");
        return;
    }

    char searchTitle[100];
    printf("Enter the title of the movie: ");
    getchar(); // consume newline
    fgets(searchTitle, 100, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("Found Movie: %s | Year: %d | Rating: %d | Review: %s\n", 
                    movies[i].title, movies[i].year, movies[i].rating, movies[i].review);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("The movie does not exist, or perhaps it never did...\n");
    }
}

void paranoidMode() {
    srand(time(NULL));
    int delay = rand() % 3 + 1; // Random delay between 1-3 seconds
    printf("Initializing paranoia... Please wait a moment...\n");
    sleep(delay);
}

void waitForUserInput() {
    printf("Press Enter to continue...");
    getchar(); // Wait for user input
}