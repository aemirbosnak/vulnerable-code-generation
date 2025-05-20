//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

struct Movie {
    char title[100];
    char genre[50];
    int year;
    float rating;
};

struct Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Oh no! We can't add more movies, we're all full! 📅\n");
        return;
    }

    struct Movie newMovie;

    printf("🎬 Let's add a movie! 🎬\n");
    
    printf("Enter the movie title: ");
    getchar(); // Clear input buffer
    fgets(newMovie.title, sizeof(newMovie.title), stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("What genre is it? ");
    fgets(newMovie.genre, sizeof(newMovie.genre), stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    printf("What year was it released? ");
    scanf("%d", &newMovie.year);

    printf("How would you rate this movie out of 10? ");
    scanf("%f", &newMovie.rating);

    movies[movieCount++] = newMovie;

    printf("🎉 Movie added successfully! 🎉\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("Uh-oh! There are no movies to display! 😢\n");
        return;
    }
    
    printf("Here are the movies in our collection! 📽️\n");
    
    for (int i = 0; i < movieCount; i++) {
        printf("%d. \"%s\" (%d) - Genre: %s | Rating: %.1f⭐\n", 
                i + 1, movies[i].title, movies[i].year, movies[i].genre, movies[i].rating);
    }
}

void searchMovie() {
    char searchTitle[100];
    
    printf("Enter the movie title you want to search for: ");
    getchar(); // Clear input buffer
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    printf("Searching for '%s'... 🔍\n", searchTitle);
    
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Found! \"%s\" (%d) - Genre: %s | Rating: %.1f⭐\n", 
                   movies[i].title, movies[i].year, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Sorry, we couldn't find that movie! ☹️\n");
}

void rateMovie() {
    displayMovies();
    int choice;
    
    printf("Choose a movie number to rate it: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > movieCount) {
        printf("Oops! That's not a valid choice! 🚫\n");
        return;
    }

    float newRating;
    printf("Give a new rating for \"%s\": ", movies[choice - 1].title);
    scanf("%f", &newRating);
    movies[choice - 1].rating = newRating;

    printf("✅ New rating updated for \"%s\" to %.1f⭐! 🎉\n", movies[choice - 1].title, newRating);
}

void menu() {
    int choice;

    do {
        printf("\n🎥 Welcome to the Movie Rating System! 🎥\n");
        printf("1. Add a Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search for a Movie\n");
        printf("4. Rate a Movie\n");
        printf("5. Exit\n");

        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                rateMovie();
                break;
            case 5:
                printf("Thank you for using the Movie Rating System! Goodbye! 👋\n");
                break;
            default:
                printf("Hmm... That's not an option! Try again! 🌈\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}