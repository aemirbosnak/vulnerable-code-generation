//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>

#define MAX_MOVIES 100

// Structure to hold movie information
typedef struct {
    char title[100];
    float rating;
    int year;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void viewMovies(Movie movies[], int count);
void rateMovie(Movie movies[], int count);
void viewAverageRating(Movie movies[], int count);
void displayMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    printf("Welcome to the Movie Rating System!\n");

    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                viewAverageRating(movies, count);
                break;
            case 0:
                printf("Exiting the system. Happy watching!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to add a movie
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar();  // Clear newline from buffer
    fgets(newMovie.title, sizeof(newMovie.title), stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline
    
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    printf("Enter movie year: ");
    scanf("%d", &newMovie.year);

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

// Function to view all movies
void viewMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display. Please add movies first.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %.1f, Year: %d\n", movies[i].title, movies[i].rating, movies[i].year);
    }
}

// Function to rate a movie
void rateMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available to rate. Please add movies first.\n");
        return;
    }

    char title[100];
    int found = 0;
    printf("Enter the title of the movie you want to rate: ");
    getchar();  // Clear newline from buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            float newRating;
            printf("Enter new rating for '%s': ", movies[i].title);
            scanf("%f", &newRating);
            movies[i].rating = newRating;
            printf("Rating updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found! Make sure to add it first.\n");
    }
}

// Function to view the average rating of all movies
void viewAverageRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to calculate the average rating. Please add movies first.\n");
        return;
    }

    float totalRating = 0.0;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }

    float averageRating = totalRating / count;
    printf("Average rating of all movies: %.2f\n", averageRating);
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate Movie\n");
    printf("4. View Average Rating\n");
    printf("0. Exit\n");
}