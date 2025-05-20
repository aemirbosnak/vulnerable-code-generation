//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>

// Define a struct to store movie details
struct Movie {
    char name[50];
    int rating;
    char genre[50];
    char director[50];
    int year;
};

// Function to display the menu
void displayMenu() {
    printf("Please choose an option:\n");
    printf("1. Add a movie\n");
    printf("2. View all movies\n");
    printf("3. Rate a movie\n");
    printf("4. Exit\n");
}

// Function to add a movie
void addMovie(struct Movie* movies, int* numMovies) {
    printf("Enter the movie name: ");
    scanf("%s", movies[*numMovies].name);
    printf("Enter the movie rating: ");
    scanf("%d", &movies[*numMovies].rating);
    printf("Enter the movie genre: ");
    scanf("%s", movies[*numMovies].genre);
    printf("Enter the movie director: ");
    scanf("%s", movies[*numMovies].director);
    printf("Enter the movie year: ");
    scanf("%d", &movies[*numMovies].year);
    (*numMovies)++;
}

// Function to view all movies
void viewMovies(struct Movie* movies, int numMovies) {
    printf("Here is a list of all movies:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d): %s (%s) (%s)\n", movies[i].name, movies[i].rating, movies[i].genre, movies[i].director, movies[i].year);
    }
}

// Function to rate a movie
void rateMovie(struct Movie* movies, int numMovies) {
    int movieIndex;
    printf("Enter the movie index: ");
    scanf("%d", &movieIndex);
    printf("Enter the new rating: ");
    scanf("%d", &movies[movieIndex].rating);
}

// Function to exit the program
void exitProgram() {
    printf("Thank you for using the movie rating system.\n");
    exit(0);
}

int main() {
    // Create an array to store movie details
    struct Movie movies[100];
    int numMovies = 0;

    // Loop until the user chooses to exit
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(&movies, &numMovies);
                break;
            case 2:
                viewMovies(movies, numMovies);
                break;
            case 3:
                rateMovie(movies, numMovies);
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}