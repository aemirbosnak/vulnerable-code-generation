//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to record the details of a movie
typedef struct {
    char title[50];
    char genre[30];
    int year;
    int rating; // 1 to 5 where 5 is the highest
} Movie;

// Function declarations
void displayMovies(Movie *movies, int count);
void addMovie(Movie *movies, int *count);
void rateMovie(Movie *movies, int count);
void displayInstructions();

int main() {
    Movie movies[100]; // Array to hold movie records
    int count = 0; // Number of movies registered
    int choice;

    printf("=== Welcome to the Medieval Movie Rating System ===\n");

    while (1) {
        displayInstructions();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 0:
                printf("Farewell, good traveler!\n");
                return 0;
            default:
                printf("Alas! Not an option in this realm. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to display instructions
void displayInstructions() {
    printf("\nChoose thy quest:\n");
    printf("1. Add a movie to the kingdom's scrolls\n");
    printf("2. Show the list of noble films\n");
    printf("3. Rate a movie in thine memory\n");
    printf("0. Depart from this enchanted realm\n");
    printf("Enter thine choice: ");
}

// Function to add a movie
void addMovie(Movie *movies, int *count) {
    if (*count >= 100) {
        printf("Alas! The scrolls are full, cannot add more films!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter the title of the film: ");
    scanf(" %[^\n]%*c", newMovie.title);
    printf("Enter the genre of the film: ");
    scanf(" %[^\n]%*c", newMovie.genre);
    printf("Enter the year of release: ");
    scanf("%d", &newMovie.year);
    
    do {
        printf("Rate the film (1 to 5): ");
        scanf("%d", &newMovie.rating);
        if (newMovie.rating < 1 || newMovie.rating > 5) {
            printf("A rating must be between 1 and 5!\n");
        }
    } while (newMovie.rating < 1 || newMovie.rating > 5);
    
    movies[*count] = newMovie;
    (*count)++;
    printf("The film '%s' has been inscribed in the annals of our kingdom!\n", newMovie.title);
}

// Function to display movies
void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No films in our scrolls, noble knight!\n");
        return;
    }

    printf("\nList of noble films in the Kingdom:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. '%s' (Genre: %s, Year: %d, Rating: %d)\n",
               i + 1, movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

// Function to rate a movie
void rateMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("There are no films to rate, fair traveler!\n");
        return;
    }

    int index;
    printf("Which film dost thou wish to rate? (Enter the number): ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Foul sorcery! There is no film with that number!\n");
        return;
    }
    
    Movie *selectedMovie = &movies[index - 1];
    int newRating;
    
    do {
        printf("Rate the film '%s' (1 to 5): ", selectedMovie->title);
        scanf("%d", &newRating);
        if (newRating < 1 || newRating > 5) {
            printf("A rating must be between 1 and 5!\n");
        }
    } while (newRating < 1 || newRating > 5);
    
    selectedMovie->rating = newRating;
    printf("Thou hast rated the film '%s' with a score of %d nobles!\n", selectedMovie->title, newRating);
}