//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating; // Rating from 1 to 5
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // consume newline character
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // remove newline
    
    printf("Enter movie rating (1-5): ");
    scanf("%d", &movies[*count].rating);
    
    if (movies[*count].rating < 1 || movies[*count].rating > 5) {
        printf("Invalid rating! Please enter a rating between 1 and 5.\n");
        return;
    }

    (*count)++;
    printf("Movie added: %s with rating %d\n", movies[*count - 1].title, movies[*count - 1].rating);
}

void listMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    printf("Movie List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Rating: %d)\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void modifyMovieRating(Movie movies[], int count) {
    int index;

    printf("Enter movie index to modify (1-%d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid index!\n");
        return;
    }

    printf("Current rating for %s is %d\n", movies[index - 1].title, movies[index - 1].rating);
    printf("Enter new rating (1-5): ");
    int newRating;
    scanf("%d", &newRating);

    if (newRating < 1 || newRating > 5) {
        printf("Invalid rating! Please enter a rating between 1 and 5.\n");
        return;
    }

    movies[index - 1].rating = newRating;
    printf("Updated rating for %s to %d\n", movies[index - 1].title, newRating);
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Modify Movie Rating\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                listMovies(movies, movieCount);
                break;
            case 3:
                modifyMovieRating(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    
    return 0;
}