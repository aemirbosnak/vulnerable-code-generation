//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 100
#define MAX_DESC 250

typedef struct {
    char title[MAX_TITLE];
    char description[MAX_DESC];
    float rating;
} Movie;

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Oops! You can't add more movies. The list is full.\n");
        return;
    }
  
    printf("Let's add a new movie! What's the title? ");
    getchar(); // Clear the newline from the buffer
    fgets(movies[*count].title, MAX_TITLE, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0'; // Remove newline character
    
    printf("What a wonderful choice! Can you give me a brief description? ");
    fgets(movies[*count].description, MAX_DESC, stdin);
    movies[*count].description[strcspn(movies[*count].description, "\n")] = '\0'; // Remove newline character
    
    printf("On a scale of 1 to 10, how would you rate this movie? ");
    scanf("%f", &movies[*count].rating);
    
    // Ensure the rating is valid
    while (movies[*count].rating < 1.0 || movies[*count].rating > 10.0) {
        printf("Hmmm, that's not a valid rating. Please enter a rating between 1 and 10: ");
        scanf("%f", &movies[*count].rating);
    }

    printf("Great! You've added '%s' with a rating of %.1f stars! 🎬\n\n", movies[*count].title, movies[*count].rating);
    (*count)++;
}

void viewMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("Oh no! You don't have any movies in your collection yet.\n\n");
        return;
    }
    
    printf("Here's what you've got in your movie collection:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. '%s' - %s (Rating: %.1f)\n", i + 1, movies[i].title, movies[i].description, movies[i].rating);
    }
    printf("\n");
}

void rateMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("Can't rate what you don't have! Add some movies first.\n\n");
        return;
    }

    int index;
    printf("Which movie would you like to rate? (Enter the number): ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Hmm, that's not a valid movie number. Please try again.\n");
        return;
    }

    float newRating;
    printf("What would you now rate the movie '%s'? ", movies[index - 1].title);
    scanf("%f", &newRating);

    // Validate the new rating
    while (newRating < 1.0 || newRating > 10.0) {
        printf("That's still not quite right, please enter a rating between 1 and 10: ");
        scanf("%f", &newRating);
    }

    movies[index - 1].rating = newRating;
    printf("You've successfully updated the rating for '%s' to %.1f stars! 🌟\n\n", movies[index - 1].title, newRating);
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    printf("Welcome to the Movie Rating System! 🎥\n");
    do {
        printf("What would you like to do?\n");
        printf("1. Add a movie\n");
        printf("2. View movies\n");
        printf("3. Rate a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                rateMovies(movies, movieCount);
                break;
            case 4:
                printf("Thanks for using the Movie Rating System! Goodbye! 👋\n");
                break;
            default:
                printf("Hmm, that doesn't seem like a valid option. Please select between 1 and 4.\n\n");
        }
    } while (choice != 4);

    return 0;
}