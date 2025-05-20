//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for movie
typedef struct {
    char title[100];
    char director[50];
    char genre[50];
    int rating;
} Movie;

// Function declaration for adding new movie
void add_movie(Movie *movies, int *count);
// Function declaration for displaying all movies
void display_movies(Movie *movies, int count);
// Function declaration for searching movie by title
void search_by_title(Movie *movies, int count);
// Function declaration for searching movie by director
void search_by_director(Movie *movies, int count);
// Function declaration for searching movie by genre
void search_by_genre(Movie *movies, int count);
// Function declaration for updating movie rating
void update_rating(Movie *movies, int count);

int main() {
    // Initialize variables
    int count = 0;
    Movie movies[50];
    int choice;

    // Loop until user chooses to exit
    do {
        // Display menu
        printf("\n\n");
        printf("1. Add new movie\n");
        printf("2. Display all movies\n");
        printf("3. Search movie by title\n");
        printf("4. Search movie by director\n");
        printf("5. Search movie by genre\n");
        printf("6. Update movie rating\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        // Execute action based on user choice
        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                search_by_title(movies, count);
                break;
            case 4:
                search_by_director(movies, count);
                break;
            case 5:
                search_by_genre(movies, count);
                break;
            case 6:
                update_rating(movies, count);
                break;
            case 7:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void add_movie(Movie *movies, int *count) {
    // Check if maximum limit is reached
    if (*count >= 50) {
        printf("\nMaximum limit reached. Cannot add new movie.\n");
        return;
    }

    // Get details of new movie
    Movie new_movie;
    printf("\nEnter the title of the movie: ");
    scanf(" %[^\n]", new_movie.title);
    printf("Enter the name of the director: ");
    scanf(" %[^\n]", new_movie.director);
    printf("Enter the genre of the movie: ");
    scanf(" %[^\n]", new_movie.genre);
    printf("Enter the rating of the movie (out of 10): ");
    scanf("%d", &new_movie.rating);

    // Add new movie to array
    movies[*count] = new_movie;
    *count += 1;

    printf("\nMovie added successfully.\n");
}

void display_movies(Movie *movies, int count) {
    // Check if there are no movies in the array
    if (count == 0) {
        printf("\nNo movies to display.\n");
        return;
    }

    // Display the details of all movies in the array
    printf("\n%-30s %-20s %-20s %-10s\n", "Title", "Director", "Genre", "Rating");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-20s %-20s %-10d\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].rating);
    }
}

void search_by_title(Movie *movies, int count) {
    // Check if there are no movies in the array
    if (count == 0) {
        printf("\nNo movies to search.\n");
        return;
    }

    // Get search query from user
    char search_query[100];
    printf("\nEnter the title of the movie to search: ");
    scanf(" %[^\n]", search_query);

    // Search for movie and display details if found
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, search_query) == 0) {
            printf("\n%-30s %-20s %-20s %-10s\n", "Title", "Director", "Genre", "Rating");
            printf("%-30s %-20s %-20s %-10d\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].rating);
            return;
        }
    }

    printf("\nMovie not found.\n");
}

void search_by_director(Movie *movies, int count) {
    // Check if there are no movies in the array
    if (count == 0) {
        printf("\nNo movies to search.\n");
        return;
    }

    // Get search query from user
    char search_query[50];
    printf("\nEnter the name of the director to search: ");
    scanf(" %[^\n]", search_query);

    // Search for movies and display details if found
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].director, search_query) == 0) {
            if (!found) {
                printf("\n%-30s %-20s %-20s %-10s\n", "Title", "Director", "Genre", "Rating");
                found = 1;
            }

            printf("%-30s %-20s %-20s %-10d\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].rating);
        }
    }

    if (!found) {
        printf("\nMovie not found.\n");
    }
}

void search_by_genre(Movie *movies, int count) {
    // Check if there are no movies in the array
    if (count == 0) {
        printf("\nNo movies to search.\n");
        return;
    }

    // Get search query from user
    char search_query[50];
    printf("\nEnter the genre of the movie to search: ");
    scanf(" %[^\n]", search_query);

    // Search for movies and display details if found
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, search_query) == 0) {
            if (!found) {
                printf("\n%-30s %-20s %-20s %-10s\n", "Title", "Director", "Genre", "Rating");
                found = 1;
            }

            printf("%-30s %-20s %-20s %-10d\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].rating);
        }
    }

    if (!found) {
        printf("\nMovie not found.\n");
    }
}

void update_rating(Movie *movies, int count) {
    // Check if there are no movies in the array
    if (count == 0) {
        printf("\nNo movies to update.\n");
        return;
    }

    // Get search query from user
    char search_query[100];
    printf("\nEnter the title of the movie to update: ");
    scanf(" %[^\n]", search_query);

    // Search for movie and update rating if found
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, search_query) == 0) {
            printf("Enter the new rating for %s: ", movies[i].title);
            scanf("%d", &movies[i].rating);
            printf("\nRating updated successfully.\n");
            return;
        }
    }

    printf("\nMovie not found.\n");
}