//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about a movie
typedef struct {
    char title[100];
    char genre[50];
    float rating;
    int votes;
} Movie;

// Function prototypes
void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void calculateStatistics(Movie *movies, int count);

#define MAX_MOVIES 100

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Calculate Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                calculateStatistics(movies, movieCount);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a movie
void addMovie(Movie *movies, int *count) {
    if (*count < MAX_MOVIES) {
        printf("Enter movie title: ");
        getchar();  // consume newline
        fgets(movies[*count].title, 100, stdin);
        strtok(movies[*count].title, "\n");  // remove newline

        printf("Enter movie genre: ");
        fgets(movies[*count].genre, 50, stdin);
        strtok(movies[*count].genre, "\n");  // remove newline

        printf("Enter movie rating (0-10): ");
        scanf("%f", &movies[*count].rating);

        printf("Enter number of votes: ");
        scanf("%d", &movies[*count].votes);

        (*count)++;
    } else {
        printf("Movie list is full! Cannot add more movies.\n");
    }
}

// Function to display all movies
void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    printf("%-30s %-20s %-6s %-6s\n", "Title", "Genre", "Rating", "Votes");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %-20s %-6.2f %-6d\n", movies[i].title, movies[i].genre, movies[i].rating, movies[i].votes);
    }
}

// Function to calculate and display movie statistics
void calculateStatistics(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to calculate statistics.\n");
        return;
    }

    float sumRating = 0.0, avgRating;
    int totalVotes = 0;

    for (int i = 0; i < count; i++) {
        sumRating += movies[i].rating;
        totalVotes += movies[i].votes;
    }

    avgRating = sumRating / count;

    printf("\nStatistics:\n");
    printf("Total Movies: %d\n", count);
    printf("Average Rating: %.2f\n", avgRating);
    printf("Total Votes: %d\n", totalVotes);
    
    // This is a simplistic display of highest rated movie
    float maxRating = movies[0].rating;
    char highestRatedTitle[100];
    strcpy(highestRatedTitle, movies[0].title);

    for (int i = 1; i < count; i++) {
        if (movies[i].rating > maxRating) {
            maxRating = movies[i].rating;
            strcpy(highestRatedTitle, movies[i].title);
        }
    }

    printf("Highest Rated Movie: '%s' with a rating of %.2f\n", highestRatedTitle, maxRating);
}