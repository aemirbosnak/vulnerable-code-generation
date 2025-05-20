//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_GENRE_LEN 30

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    float rating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void AddMovie();
void ListMovies();
void RateMovie();
void SearchMovie();
void DisplayMenu();
void ClearInputBuffer();

int main() {
    int choice;

    do {
        DisplayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        ClearInputBuffer();
        
        switch (choice) {
            case 1:
                AddMovie();
                break;
            case 2:
                ListMovies();
                break;
            case 3:
                RateMovie();
                break;
            case 4:
                SearchMovie();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void DisplayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Rate Movie\n");
    printf("4. Search Movie\n");
    printf("5. Exit\n");
}

void ClearInputBuffer() {
    while (getchar() != '\n');
}

void AddMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, MAX_TITLE_LEN, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character
        
    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LEN, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    newMovie.rating = 0.0;  // Initially, no rating
    
    movieList[movieCount++] = newMovie;
    
    printf("Movie '%s' added successfully!\n", newMovie.title);
}

void ListMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\n=== List of Movies ===\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Genre: %s, Rating: %.1f\n", 
                movieList[i].title, movieList[i].genre, movieList[i].rating);
    }
}

void RateMovie() {
    char title[MAX_TITLE_LEN];
    float rating;
    
    printf("Enter the title of the movie you want to rate: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            printf("Enter your rating (0.0 to 5.0): ");
            scanf("%f", &rating);
            ClearInputBuffer();
            
            if (rating < 0.0 || rating > 5.0) {
                printf("Invalid rating. Please enter a value between 0.0 and 5.0.\n");
            } else {
                movieList[i].rating = rating;
                printf("Rating for '%s' updated to %.1f\n", movieList[i].title, movieList[i].rating);
            }
            return;
        }
    }
    printf("Movie not found.\n");
}

void SearchMovie() {
    char title[MAX_TITLE_LEN];
    
    printf("Enter the title of the movie you want to search: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            printf("Found movie - Title: %s, Genre: %s, Rating: %.1f\n", 
                    movieList[i].title, movieList[i].genre, movieList[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}