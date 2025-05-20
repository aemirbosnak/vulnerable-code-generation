//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Rating out of 10
    char review[MAX_REVIEW_LENGTH];
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("You have reached the maximum number of movies.\n");
        return;
    }
    
    printf("Enter the movie title: ");
    getchar(); // consume the newline character left by previous input
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline
    
    printf("Enter your rating for \"%s\" (0-10): ", movies[*count].title);
    scanf("%d", &movies[*count].rating);

    while (movies[*count].rating < 0 || movies[*count].rating > 10) {
        printf("Invalid rating. Please enter a rating between 0 and 10: ");
        scanf("%d", &movies[*count].rating);
    }

    printf("Enter your review for \"%s\": ", movies[*count].title);
    getchar(); // consume the newline character
    fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Movie \"%s\" added successfully!\n", movies[*count - 1].title);
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("There are no movies to display.\n");
        return;
    }
    
    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s\n", i + 1, movies[i].title);
        printf("   Rating: %d/10\n", movies[i].rating);
        printf("   Review: %s\n\n", movies[i].review);
    }
}

void searchMovie(Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie you want to search for: ");
    getchar(); // consume the newline character
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Rating: %d/10\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            return;
        }
    }
    printf("Movie \"%s\" not found.\n", title);
}

void deleteMovie(Movie movies[], int *count) {
    if (*count == 0) {
        printf("There are no movies to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the number of the movie you want to delete (1-%d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid number. Movie not deleted.\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        movies[i] = movies[i + 1];
    }
    
    (*count)--;
    printf("Movie successfully deleted.\n");
}

void menu() {
    printf("\n-----------------------------\n");
    printf("   Sherlock's Movie Ratings   \n");
    printf("-----------------------------\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;
    
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
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
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the movie rating system. Until next time, Watson!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}